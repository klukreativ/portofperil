/*This project was started in March 2020 as a practice exercise to demonstrate the skills
I have learned in the C language in the previous months

This exercise aims to translate a Fighting Fantasy gamebook (a Choose Your Own Adventure book with
an added battle system using dice) into a program

The source material is the property of Ian Livingstone, Fighting Fantasy, and Scholastic
This program was created for educational purposes only*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> /*used for randomizer*/
#include "pop-header.h"

/*this creates a line to distinguish between separate entries in the story*/
void pagebreak() {
	printf(" -------------------------------------------------------------------------------------\n");
}
/*displays character information, stats for now, will add inventory later*/
void displayChar(struct hero* dPC) {
	printf("\n| %s |", dPC->name);
	printf(" Skill: %i/%i |", dPC->cSK, dPC->mSK);
	printf(" Stamina: %i/%i |", dPC->cST, dPC->mST);
	printf(" Luck: %i/%i |\n", dPC->cLK, dPC->mLK);
}

/*displays contents of character inventory*/
void dispINV(struct hero* iPC) {
	/*this array details the values of the hero inventory, organized in sets of 5*/
	int readINV;
	for (readINV = 0; readINV < 100; readINV++) {
		if ((iPC->inv[readINV] > 0) && iPC->inv[readINV] < 100) {
			printf("%s", inventory[readINV]);
			if (iPC->inv[readINV] > 1) {
				printf(" x %i\n", iPC->inv[readINV]);
			}
			else {
				printf("\n");
			}
		}
	}
}
/*this function deletes character inventory - used for new characters and certain events*/
void emptyINV(struct hero* ePC) {
	int empty;
	for (empty = 0; empty < 100; empty++) {
		ePC->inv[empty] = 0;
	}
}

/*Test Your Luck function for various events & combat*/
int testyourluck(struct hero* lPC) {
	srandom(time(0));
	int test = ((random() % 6) + 1) + ((random() % 6) + 1);
	printf("\nYou roll a %i.\n", test);
	lPC->cLK = (lPC->cLK - 1);
	if (lPC->cLK < 0) {
		lPC->cLK = 0;
	}

	if (test <= lPC->cLK + 1) {
		printf("You are lucky!\n");
		return 0;
	}
	else {
		printf("\nYour luck fails you.\n");
		return 1;
	}

}

/*this receives the story pointer and assigns all of the events, options, and conditionals
for the current path of the story*/
void progStory(struct story* sPara, int nextP) {
	sPara->opt1 = events[nextP][0];
	sPara->opt2 = events[nextP][1];
	sPara->opt3 = events[nextP][2];
	sPara->cond = events[nextP][3];
	sPara->misc1 = events[nextP][4];
	sPara->misc2 = events[nextP][5];
	sPara->misc3 = events[nextP][6];
	sPara->misc4 = events[nextP][7];
}

void tellStory(int nextREAD, int whichP) {
	printf("\n%s", storytext[nextREAD][whichP - 1]);
}
/*this is where the player will make their choice on which branch the story takes*/
int makeChoice(struct hero* mcPC, struct story* SC, int nS) {
	char pcChoice[1];	
	while (1) {
		printf("\nSelect your option: [A]");
		if (SC->opt2 > 0) {
			printf(", [B]");
		}
		else {
			printf(" to continue");
		}
		if (SC->opt3 > 0) {
			printf(", [C]");
		}
		if (nS > 0) {
			
			printf(", [D]isplay Character Information, or [E]at a provision");
		}
		printf("\n");
		scanf("%s", pcChoice);

		if (strncasecmp(pcChoice, "A", 1) == 0)  {
			return SC->opt1;
		}
		else if ((strncasecmp(pcChoice, "B", 1) == 0) && (SC->opt2 > 0)) {
			return SC->opt2;
		}
		else if ((strncasecmp(pcChoice, "C", 1) == 0) && (SC->opt3 > 0)) {
			return SC->opt3;
		}
		else if ((strncasecmp(pcChoice, "D", 1) == 0) && (nS > 0)) {
			displayChar(mcPC);
			dispINV(mcPC);
		}
		else if ((strncasecmp(pcChoice, "E", 1) == 0) && (nS > 0)) {
			if ((mcPC->inv[2] > 0) && (mcPC->hunger == 0)) {
				mcPC->cST = mcPC->cST + 4;
				if (mcPC->cST > mcPC->mST) {
					mcPC->cST = mcPC->mST;
				}
				printf("You eat a meal and recover some STAMINA.\n");
			}
			else if ((mcPC->inv[2] > 0) && (mcPC->hunger == 1)) {
				printf("You are still too full to eat another meal.\n");
			}
			else {
				printf("You have no provisions left to eat.\n");
			}
		}
		else {
			printf("Invalid Selection. Please try again.\n");
		}
	}
}

int condStory(struct hero *cPC, struct story *cPara, int cnextSTEP) {
	/*Test Your Luck condition*/
	if (cPara->cond == 1){
		if (testyourluck(cPC) == 0) {
				return cPara->opt1;
		}
		else {
				return cPara->opt2;
		}
	}
	/*Test your Skill*/
	else if (cPara->cond == 2) {
		srandom(time(0));
		int testSK = ((random() % 6) + 1) + ((random() % 6) + 1);
		printf("You roll a %i\n", testSK);
		if (testSK + cPara->misc1 <= cPC->cSK + 1) {
			printf("SUCCESS!\n");
			return cPara->opt1;
		}
		else {
			printf("FAILURE!\n");
			return cPara->opt2;
		}
	}
	/*battle events*/
	/*regular*/
	else if (cPara->cond == 3) {
		batPLUSSIM(cPC, cPara, 0);
		return cPara->opt1;
	}
	/*enemy advantage*/
	else if (cPara->cond == 13) {
		batPLUSSIM(cPC, cPara, 1);
		return cPara->opt1;
	}
	/*player advantage*/
	else if (cPara->cond == 31) {
		batPLUSSIM(cPC, cPara, 2);
		return cPara->opt1;
	}
	/*death*/
	else if (cPara->cond == 4) {
		cPC->cST = 0;
		printf("Your adventure is over.\n");
		return 0;
	}
	/*modifies stat*/
	else if (cPara->cond == 5) {
		/*increase max value BY x*/
		if (cPara->misc4 == 1) {
			cPC->cSK = cPC->mSK + cPara->misc1;
			cPC->cST = cPC->mST + cPara->misc2;
			cPC->cLK = cPC->mLK + cPara->misc3;
		}
		/*increases max value TO x*/
		else if (cPara->misc4 == 2) {
			cPC->cSK = cPara->misc1;
			cPC->cST = cPara->misc2;
			cPC->cLK = cPara->misc3;
		}
		/*increases cur val BY x, corrects if exceeds MAX, checks for death*/
		else {
			cPC->cSK = cPC->cSK + cPara->misc1;
			if (cPC->cSK > cPC->mSK) {
				cPC->cSK = cPC->mSK;
			}
			cPC->cST = cPC->cST + cPara->misc2;
			if (cPC->cST < 1) {
				cPC->cST = 0;
				return 0;
			}
			if (cPC->cST > cPC->mST) {
				cPC->cST = cPC->mST;
			}
			cPC->cLK = cPC->cLK + cPara->misc3;
			if (cPC->cLK > cPC->mLK) {
				cPC->cLK = cPC->mLK;
			}
		}
		tellStory(cnextSTEP, 2);
		return makeChoice(cPC, cPara, cnextSTEP);
	}
	/*item based condition CHOICE/BUY*/
	else if (cPara->cond == 6) {
		if (cPC->inv[cPara->misc1] >= cPara->misc2) {
			tellStory(cnextSTEP, 2);
			if (makeChoice(cPC, cPara, cnextSTEP) == cPara->opt1) {
				/*buying/trading - removes the item(s)*/
				if (cPara->misc3 == 1) {
					cPC->inv[cPara->misc1] = cPC->inv[cPara->misc1] - cPara->misc2;
					/*buying/trading - this adds the new item*/
					if (cPara->misc4 > 0) {
						cPC->inv[cPara->misc4] = 1;
					}
				}
				/*picking up, different from cond 8 b/c this is forced*/
				else if (cPara->misc3 == 2) {
					cPC->inv[cPara->misc1] = cPC->inv[cPara->misc1] + cPara->misc4;
				}
				return cPara->opt1;
			}
		}
		else {
			tellStory(cnextSTEP, 3);
		}
		return cPara->opt2;
	}
	/*item based condition NO CHOICE*/
	else if (cPara->cond == 7) {
		/*event based*/
		if (cPara->misc3 == 1) {
			if (cPC->inv[cPara->misc1] == 100) {
				cPara->opt2 = 0;
			}
			else {
				tellStory(cnextSTEP, 2);
			}
			return makeChoice(cPC, cPara, cnextSTEP);
			printf("error");
		}
		else if ((cPC->inv[cPara->misc1] > 0) && (cPC->inv[cPara->misc1] < 100)) {
			return cPara->opt1;
		}
		else {
			tellStory(cnextSTEP, 2);
			return cPara->opt2;
		}
	}
	/*item GAINED/LOST*/
	else if (cPara->cond == 8) {
		cPC->inv[cPara->misc1] = cPC->inv[cPara->misc1] + cPara->misc2;
		if (cPC->inv[cPara->misc1] < 0) {
			cPC->inv[cPara->misc1] = 0;
		}
		/*checks for additional item*/
		if (cPara->misc3 > 0) {
			cPC->inv[cPara->misc3] = cPC->inv[cPara->misc3] + cPara->misc4;
			if (cPC->inv[cPara->misc3] < 0) {
				cPC->inv[cPara->misc3] = 0;
			}
		}
		tellStory(cnextSTEP, 2);
		return makeChoice(cPC, cPara, cnextSTEP);
	}
	/*SPECIAL CONDITION*/
	else if (cPara->cond == 9) {
		return specCOND(cPC, cPara, cnextSTEP);
	}
	else if (cPara->cond == 33) {
		batPLUSSIM(cPC, cPara, 1);
		return cPara->opt1;
	}
}

void findFOE(struct enemy* fFOE, int fbatCOUNT) {
strncpy(fFOE->ename, theFOE[fbatCOUNT - 1][0], sizeof(fFOE->ename));
fFOE->eSK = atoi(theFOE[fbatCOUNT - 1][1]);
fFOE->eST = atoi(theFOE[fbatCOUNT - 1][2]);
}

/*randomizes 2d6 roll for battles*/
int atkROLL() {
	srandom(time(0));
	int atkST = ((random() % 6) + 1) + ((random() % 6) + 1);
	return atkST;
}
/*Test Your Luck function specifically for battle*/
int batTYL(struct hero* btPC, struct story *btPara, int adv) {
	char choiceTYL[1];
	int rollLUCK;
	if (btPC->cLK > 0) {
		printf("Test Your Luck?\n\n[A] Yes\n[B] No\n");
		while (1) {
			scanf("%s", choiceTYL);
			if (strncasecmp(choiceTYL, "A", 1) == 0) {
				rollLUCK = testyourluck(btPC);
				if (rollLUCK == 0) {
					if (adv == 0) {
						printf("You strike a critical blow for %i damage.\n", (4 + btPara->misc4));
						return (4 + btPara->misc4);
					}
					else if (adv == 1) {
						printf("Your blow glances for %i damage.\n", (1 + btPara->misc4));
						return (1 + btPara->misc4);
					}
				}
				else if (rollLUCK == 1) {
					if (adv == 0) {
						printf("You brace yourself for the hit, taking 1 damage.\n");
						return 1;
					}
					else if (adv == 1) {
						printf("You are hit with a staggering blow for 3 damage.\n");
						return 3;
					}
				}
			}
			else if (strncasecmp(choiceTYL, "B", 1) == 0) {
				if (adv == 0) {
					printf("You strike the enemy for %i damage.\n", (2 + btPara->misc4));
					return (2 + btPara->misc4);
				}
				else if (adv == 1) {
					printf("The enemy strikes you for 2 damage.\n");
					return 2;
				}
				
			}
			else {
				printf("Invalid Selection. Please Try Again.\n");
			}
		}	
	}
}

/*this is the battle system*/

void batRESOLVE(struct hero* brPC, int brPCroll, struct enemy* brFOE, int brFOEroll, struct story* brPara, int brCOND) {
	if ((brPC->cSK + brPCroll) > (brFOE->eSK + brFOEroll)) {
		if ((brCOND == 0) || (brCOND == 2)) {
			brFOE->eST = brFOE->eST - batTYL(brPC, brPara, 0);
			if (brFOE->eST <= 0) {
				printf("You have slain the %s.\n", brFOE->ename);
				brFOE->eST = 0;
			}
		}
		else if (brCOND == 1) {
			printf("You are able to repel the %s's attack.\n", brFOE->ename);
		}
	}
	else if ((brPC->cSK + brPCroll) > (brFOE->eSK + brFOEroll)) {
		if (brCOND == 2) {
			printf("%s dodges your blow.\n", brFOE->ename);
		}
		else {
			brPC->cST = brPC->cST - batTYL(brPC, brPara, 1);
			if (brPC->cST < 0) {
				brPC->cST = 0;
			}
		}
	}
	else {
		printf("You and the %s parry blows.\n", brFOE->ename);
	}
}

int batPLUSSIM(struct hero* bpPC, struct story* bpPara, int batTYPE) {
	enemy bpFOE[3];
	char bpCHOICE[1];
	int bpcount;
	int bpPCroll;
	int bpPCatkST;
	int bpFOEroll;
	int bpFOEatkST;
	int target;

	/*resets bpFOE values*/
	for (bpcount = 0; bpcount < 3; bpcount++) {
		strncpy(bpFOE[bpcount].ename, "\n", sizeof(bpFOE->ename));
		bpFOE[bpcount].eSK = 0;
		bpFOE[bpcount].eST = 0;
	}

	/*assigns bpFOE values*/
	for (bpcount = 0; bpcount < bpPara->misc2; bpcount++) {		
		strncpy(bpFOE[bpcount].ename, theFOE[bpPara->misc1 + bpcount - 1][0], sizeof(theFOE[bpPara->misc1 + bpcount - 1][0]));
		bpFOE[bpcount].eSK = atoi(theFOE[bpPara->misc1 + bpcount - 1][1]);
		bpFOE[bpcount].eST = atoi(theFOE[bpPara->misc1 + bpcount - 1][2]);
	}
	
	/*runs while character & at least 1 enemy is still alive*/
	while ((bpPC->cST > 0) && ((bpFOE[0].eST > 0) || (bpFOE[1].eST > 0) || (bpFOE[2].eST > 0))) {
		srandom(time(0));
		/*selecting target from remaining enemies*/
		while (1) {
			displayChar(bpPC);
			printf("\nSelect a target:\n");
			if (bpFOE[0].eST > 0) {
				printf("[A] %s\n", bpFOE[0].ename);
			}
			if (bpFOE[1].eST > 0) {
				printf("[B] %s\n", bpFOE[1].ename);
			}
			if (bpFOE[2].eST > 0) {
				printf("[C] %s\n", bpFOE[2].ename);
			}
			scanf("%s", bpCHOICE);
			/*checks to see if choice is VALID & ALIVE*/
			if ((strncasecmp(bpCHOICE, "A", 1) == 0) && (bpFOE[0].eST > 0)) {
				target = 0;
				break;
			}
			else if ((strncasecmp(bpCHOICE, "B", 1) == 0) && (bpFOE[1].eST > 0)) {
				target = 1;
				break;
			}
			else if ((strncasecmp(bpCHOICE, "C", 1) == 0) && (bpFOE[2].eST > 0)) {
				target = 2;
				break;
			}
			else {
				printf("Invalid Selection. Please Try Again.\n");
			}
		}
		/*first resolves attack on target*/
		bpPCroll = atkROLL();
		printf("You roll a %i, for an ATTACK STRENGTH of %i.\n", bpPCroll, (bpPCroll + bpPC->cSK));
		bpFOEroll = atkROLL();
		printf("%s rolls a %i, for an ATTACK STRENGTH of %i.\n", bpFOE[target].ename, bpFOEroll, (bpFOEroll + bpFOE[target].eSK));
		batRESOLVE(bpPC, bpPCroll, &bpFOE[target], bpFOEroll, bpPara, 0);
		
		/*resolves attacks from other opponents*/
		if (batTYPE == 1) {
			for (bpcount = 0; bpcount < 3; bpcount++) {
				if ((target != bpcount) && (bpFOE[bpcount].eST > 0) && (bpPC->cST > 0)) {
					printf("\n%s advances.\n", bpFOE[bpcount].ename);
					bpPCroll = atkROLL();
					printf("You roll a %i, for an ATTACK STRENGTH of %i.\n", bpPCroll, (bpPCroll + bpPC->cSK));
					bpFOEroll = atkROLL();
					printf("%s rolls a %i, for an ATTACK STRENGTH of %i.\n", bpFOE[bpcount].ename, bpFOEroll, (bpFOEroll + bpFOE[bpcount].eSK));
					batRESOLVE(bpPC, bpPCroll, &bpFOE[bpcount], bpFOEroll, bpPara, batTYPE);
				}
			}
		}
		else if (batTYPE == 2) {
			printf("\nYou swing again at %s.\n", bpFOE[bpcount].ename);
			bpPCroll = atkROLL();
			printf("You roll a %i, for an ATTACK STRENGTH of %i.\n", bpPCroll, (bpPCroll + bpPC->cSK));
			bpFOEroll = atkROLL();
			printf("%s rolls a %i, for an ATTACK STRENGTH of %i.\n", bpFOE[bpcount].ename, bpFOEroll, (bpFOEroll + bpFOE[bpcount].eSK));
			batRESOLVE(bpPC, bpPCroll, &bpFOE[bpcount], bpFOEroll, bpPara, batTYPE);
		}
	}
	if (bpPC->cST > 0) {
		printf("You are victorious!\n");
		getchar();
		return 0;
	}
	else {
		printf("You have been slain.\n");
		getchar();
		return 1;
	}
}

void end_game() {
	puts("\nExiting...");
	exit(1);
}

/*character creation, recieves name, uses random 6 sided dice rolls to determine attributes
resets inventory (in case of continuation) and offers a potion*/
void rollChar(struct hero* cPC) {
	srandom(time(0));
	char potChoice[1];
	int RESETinv;

	printf("Enter name:");
	scanf("%s", cPC->name);
	if (strncasecmp(cPC->name, "Garou", 5) == 0) {
		cPC->mSK = 12;
		cPC->cSK = 12;
		cPC->mST = 24;
		cPC->cST = 24;
		cPC->mLK = 12;
		cPC->cLK = 12;
	}
	else {
		printf("\nRoll a 1d6 for SKILL\n");
		getchar();
		int rSK = (random() % 6) + 1;
		cPC->mSK = rSK + 6;
		cPC->cSK = cPC->mSK;
		printf("You rolled a %i, for a total of %i SKILL.\n", rSK, cPC->mSK);

		printf("\nRoll 2d6 for STAMINA\n");
		getchar();
		int rST = ((random() % 6) + 1) + ((random() % 6) + 1);
		cPC->mST = rST + 12;
		cPC->cST = cPC->mST;
		printf("You rolled a %i, for a total of %i STAMINA.\n", rST, cPC->mST);

		printf("\nRoll 1d6 for LUCK\n");
		getchar();
		int rLK = (random() % 6) + 1;
		cPC->mLK = rLK + 6;
		cPC->cLK = cPC->mLK;
		printf("You rolled a %i, for a total of %i LUCK.\n", rLK, cPC->mLK);
	}
	getchar();	

	/*this initalizes/resets the inventory in the event that a player starts a new
	character in succession or after a failed adventure
	sets all items to 0, and then initializes the provisions to 10*/
	
	emptyINV(cPC);

	/*this offers the player their choice of potion*/
	while (1) {
		printf("\nYou may select one potion for your journey:\n\n[A] Potion of SKILL\n[B] Potion of STAMINA\n[C] Potion of LUCK\n");
		scanf("%s", potChoice);

		if (strncasecmp(potChoice, "A", 1) == 0) {
			cPC->inv[3] = 1;
			break;
		}
		else if (strncasecmp(potChoice, "B", 1) == 0) {
			cPC->inv[4] = 1;
			break;
		}
		else if (strncasecmp(potChoice, "C", 1) == 0) {
			cPC->inv[5] = 1;
			break;
		}
		else {
			printf("Invalid selection. Please try again.\n");
		}
	}
}

int main() {
	struct hero PC[1];
	struct story Para[1];

	dispTITLE();

	while (1) {
		pagebreak();
		printf("|                    [C]reate Character, [B]egin Adventure, [E]xit                    |\n");
		pagebreak();
		char menu[1];
		scanf("%s", menu);

		if (strncasecmp(menu, "C", 1) == 0) {
			rollChar(PC);
		}
		else if (strncasecmp(menu, "B", 1) == 0) {
			/*checks if character is created before beginning*/
			if ((PC->cST > 1) && (PC->cST < 30)) {
				char skipintro[1];
				int nextSTEP = 0;
				printf("Enter [S] if you wish to skip the introduction.\n");
				scanf("%s", skipintro);
				getchar();
				if (strncasecmp(skipintro, "S", 1) != 0) {
					intro();
				}
				/*this is the main game function*/
				while (PC->cST > 0) {
					if (nextSTEP < 401) {
						pagebreak();
						PC->hunger = 0;
					}
					progStory(Para, nextSTEP);
					tellStory(nextSTEP, 1);
					getchar();
					if (Para->cond > 0) {
						nextSTEP = condStory(PC, Para, nextSTEP);
						getchar();
					}
					else {
						tellStory(nextSTEP, 2);
						nextSTEP = makeChoice(PC, Para, nextSTEP);
						getchar();
					}			
				}
			}
			/*warning if character has not been created yet*/
			else {
				printf("Please create a new character first.\n");
			}
		}
		else if (strncasecmp(menu, "E", 1) == 0) {
			end_game();
		}
		else {
			puts("Invalid Selection. Please Try again.\n");
		}
	}
	return 0;
}