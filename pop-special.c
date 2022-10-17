#include "pop-header.h"

/*these conditionals require unique code and are unable to be duplicated using combinations of the existing conditionals*/
int specCOND(struct hero* scPC, struct story* scPara, int scnextSTEP) {
	int SPECIAL;
	char sCHOICE[1];

	if (scnextSTEP == 1) {
		scPC->inv[2] = 10;
		for (SPECIAL = 55; SPECIAL < 66; SPECIAL++) {
			scPC->inv[SPECIAL] = 1;
		}
		tellStory(scnextSTEP, 2);
		return makeChoice(scPC, scPara, scnextSTEP);
	}
	/*45*/
	else if (scnextSTEP == 408) {
		srandom(time(0));
		int SPECIAL = ((random() % 6) + 1);
		if (scPC->cSK >= 10) {
			SPECIAL++;
		}
		if (SPECIAL >= 6) {
			return scPara->opt2;
		}
		else {
			return scPara->opt1;
		}
	}
	else if (scnextSTEP == 65) {
		srandom(time(0));
		int SPECIAL = ((random() % 6) + 1);
		if (SPECIAL == 6) {
			return scPara->opt1;
		}
		else if (SPECIAL == 5) {
			return scPara->opt2;
		}
		else {
			return scPara->opt3;
		}
	}
	else if (scnextSTEP == 69) {
		SPECIAL == scPC->cST;
		scPara->cond = 3;
		batPLUSSIM(scPC, scPara, 0);
		if (SPECIAL == scPC->cST) {
			return scPara->opt1;
		}
		else if (SPECIAL > scPC->cST) {
			return scPara->opt2;
		}
	}
	else if (scnextSTEP == 87) {
		emptyINV(scPC);
		return scPara->opt1;
	}
	else if (scnextSTEP == 89) {
		int SPcount;
		for (SPcount = 0; SPcount < 3; SPcount++) {
			srandom(time(0));
			SPECIAL = ((random() % 6) + 1);
			if (SPECIAL == 1) {
				scPC->inv[0] = scPC->inv[0] - 2;
			}
			else if (SPECIAL == 2) {
				scPC->inv[0] = scPC->inv[0] - 3;
			}
			else if (SPECIAL == 3) {
				scPC->inv[28] = 0;
				scPC->inv[29] = 0;
			}
			else if (SPECIAL == 4) {
				scPC->inv[57] = 0;
				scPC->inv[0] = scPC->inv[0] - 1;
			}
			else if (SPECIAL == 5) {
				scPC->inv[10] = 0;
				scPC->inv[0] = scPC->inv[0] - 1;
			}
			else if (SPECIAL == 6) {
				scPC->inv[3] = 0;
				scPC->inv[4] = 0;
				scPC->inv[5] = 0;
			}
			if (scPC->inv[0] < 0) {
				scPC->inv[0] = 0;
			}
		}
		printf("Some items were stolen.\n");
		getchar();
		tellStory(scnextSTEP, 2);
		return makeChoice(scPC, scPara, scnextSTEP);
	}
	else if ((scnextSTEP == 101) || (scnextSTEP == 237)) {
		srandom(time(0));
		int SPECIAL = (((random() % 6) + 1) + ((random() % 6) + 1));
		if (scPC->inv[35] == 1) {
			printf("Do you wish to use your Lucky Bones?\n\n[A] Yes\n[B] No\n");
			while (1) {
				scanf("%s", sCHOICE);
					if (strncasecmp(sCHOICE, "A", 1) == 0) {
						SPECIAL = SPECIAL + 4;
						if (SPECIAL > 12) {
							SPECIAL = 12;
						}
						break;
					}
					else if (strncasecmp(sCHOICE, "B", 1) == 0) {
						SPECIAL = 0;
						break;
					}
					else {
						printf("Invalid Selection. Please Try Again.\n");
					}
			}
			printf("The dice clatter as they hit the wooden table.\nAs the dice come to a halt, they total %i.\n", SPECIAL);
			getchar();
			if (SPECIAL > 7) {
				return scPara->opt1;
			}
			else if (SPECIAL < 8) {
				return scPara->opt2;
			}
		}
	}
	else if (scnextSTEP == 192) {
		for (SPECIAL = 0; SPECIAL < 20; SPECIAL++) {
			scPC->inv[SPECIAL] = 0;
		}
		for (SPECIAL = 25; SPECIAL < 76; SPECIAL++) {
			scPC->inv[SPECIAL] = 0;
		}
	}
	else if (scnextSTEP == 217) {
		if ((scPC->inv[36] == 1) && (scPC->inv[37] == 1)) {
			printf("You may either:\n\n[A] Use the potion from the green bottle\n[B] Use the potion from the brown bottle\n");
			while (1) {
				scanf("%s", sCHOICE);
				if (strncasecmp(sCHOICE, "A", 1) == 0) {
					return scPara->opt1;
				}
				else if (strncasecmp(sCHOICE, "B", 1) == 0) {
					return scPara->opt2;
				}
				else {
					printf("Invalid Selection. Please try again.\n");
				}
			}
		}
		else if (scPC->inv[37] == 1) {
			return scPara->opt1;
		}
		else if (scPC->inv[36] == 1) {
			return scPara->opt2;
		}
		else {
			return scPara->opt3;
		}
	}
	else if (scnextSTEP == 220) {
		srandom(time(0));
		SPECIAL = ((random() % 6) + 1);
		if (SPECIAL == 1) {
			SPECIAL = 2;
		}
		printf("%i arrows strike you.\n", SPECIAL);
		SPECIAL = SPECIAL * 2;
		printf("You lose %i STAMINA points.\n", SPECIAL);
		return scPara->opt1;
	}
	/*p229*/
	else if (scnextSTEP == 439) {
		for (SPECIAL = 50; SPECIAL < 55; SPECIAL++) {
			printf("Do you wish to take the %s?\n\n[A] Yes\n[B] No\n", inventory[SPECIAL]);
			while (1) {
				scanf("%s", sCHOICE);
				if (strncasecmp(sCHOICE, "A", 1) == 0) {
					scPC->inv[SPECIAL] = 1;
					tellStory(scnextSTEP, 2);
					return makeChoice(scPC, scPara, scnextSTEP);
				}
				else if (strncasecmp(sCHOICE, "B", 1) == 0) {
					break;
				}
				else {
					printf("Invalid Choice. Please Try Again.\n");
				}
			}
		}
		tellStory(scnextSTEP, 2);
		return makeChoice(scPC, scPara, scnextSTEP);
	}
	else if (scnextSTEP == 235) {
	if ((scPC->inv[57] == 1) && (scPC->inv[60] == 1)) {
		printf("Do you wish to offer him your goblet with the unicorn-\nhead motif nand brass bell in exchange for his battleaxe?\n\n[A] Yes\n[B] No\n");
		while (1) {
			scanf("%s", sCHOICE);
			if (strncasecmp(sCHOICE, "A", 1) == 0) {
				scPC->inv[57] = 0;
				scPC->inv[60] = 0;
				return scPara->opt1;
			}
			if (strncasecmp(sCHOICE, "B", 1) == 0) {
				break;
			}
			else {
				printf("Invalid Choice. Please Try Again.\n");
			}
		}
	}
	if ((scPC->inv[57] == 1) && (scPC->inv[56] == 1)) {
		printf("Do you wish to offer him your brass bell and candle?\n\n[A] Yes\n[B] No\n");
		while (1) {
			scanf("%s", sCHOICE);
			if (strncasecmp(sCHOICE, "A", 1) == 0) {
				scPC->inv[57] = 0;
				scPC->inv[56] = 0;
				return scPara->opt2;
			}
			if (strncasecmp(sCHOICE, "B", 1) == 0) {
				break;
			}
			else {
				printf("Invalid Choice. Please Try Again.\n");
			}
		}
	}
	tellStory(scnextSTEP, 2);
	return scPara->opt3;
	}
	else if (scnextSTEP == 252) {
		printf("You may either:\n\n[A] Attack the Sporeball with your sword\n[B] Hold your breath and run through the clearing\n");
		if (scPC->inv[49] > 0) {
			printf("[C] Pour fireroot juice on the Sporeball\n");
		}
		while (1) {
			scanf("%s", sCHOICE);
			if (strncasecmp(sCHOICE, "A", 1) == 0) {
				return scPara->opt1;
			}
			else if (strncasecmp(sCHOICE, "B", 1) == 0) {
				return scPara->opt3;
			}
			else if ((strncasecmp(sCHOICE, "C", 1) == 0) && (scPC->inv[49] > 0)) {
				return scPara->opt2;
			}
			else {
				printf("Invalid Selection. Please Try Again.\n");
			}
		}
	}
	else if (scnextSTEP == 265) {
		SPECIAL = scPC->cST;
		scPara->cond = 3;
		int witch = condStory(scPC, scPara, scnextSTEP);
		if (scPC->cST < SPECIAL) {
			printf("The wounds you have suffered from the Plague Witch have\ninfected you with the worm plague, which turn your eyes black\nand make you go blind, just like her. It is impossible for you\nto continue your quest.\n");
			return 0;
		}
		return scPara->opt1;
		}
	else if (scnextSTEP == 296) {
		printf("You may either:\n\n[A] Attack him with your sword");
		if (scPC->inv[14] == 1) {
			printf("[B] Fire an arrow at him");
		}
		if ((scPC->inv[11] == 1) || (scPC->inv[12] == 1)) {
			printf("[C] Fire your flintlock pistol at him");
		}
		while (1) {
			scanf("%s", sCHOICE);
			if (strncasecmp(sCHOICE, "A", 1) == 0) {
				return scPara->opt1;
			}
			else if ((strncasecmp(sCHOICE, "B", 1) == 0) && (scPC->inv[14] == 1)) {
				return scPara->opt2;
			}
			else if ((strncasecmp(sCHOICE, "C", 1) == 0) && (scPC->inv[11] == 1)) {
				printf("Your flintlock pistol is unmaintained and does not fire.\n");
			}
			else if ((strncasecmp(sCHOICE, "C", 1) == 0) && (scPC->inv[12] == 1)) {
				return scPara->opt3;
			}
			else {
				printf("Invalid Selection. Please try again.\n");
			}
		}
	}
	else if (scnextSTEP == 314) {
		scPC->cSK = scPC->cSK - 1;
		scPC->cST = scPC->cST - 2;
		if (((scPC->inv[36] == 1)  || (scPC->inv[38] == 1)) && (scPC->cST > 0)) {
			printf("You may either:\n\n");
			if (scPC->inv[36] == 1) {
				printf("[A] Try using Snake Oil\n");
			}
			if (scPC->inv[38] == 1) {
				printf("[B] Try using Stikkle Wax\n");
			}
			while (1) {
				scanf("%s", sCHOICE);
				if ((strncasecmp(sCHOICE, "A", 1) == 0) && (scPC->inv[36] == 1)) {
					return scPara->opt1;
				}
				else if ((strncasecmp(sCHOICE, "B", 1) == 0) && (scPC->inv[38] == 1)) {
					return scPara->opt2;
				}
				else {
					printf("Invalid selection. Please try again.\n");
				}
			}
		}
		else {
			tellStory(scnextSTEP, 2);
			scPC->cST = 0;
			return 0;
		}
	}
	else if (scnextSTEP == 330) {
		int JARcount = 0; 
		for (SPECIAL = 43; SPECIAL < 50; SPECIAL++) {
			printf("Do you wish to take the %s?\n\n[A] Yes\n[B] No\n", inventory[SPECIAL]);
			while (JARcount < 3) {
				scanf("%s", sCHOICE);
				if (strncasecmp(sCHOICE, "A", 1) == 0) {
					scPC->inv[SPECIAL] = 1;
					JARcount++;
					break;
				}
				else if (strncasecmp(sCHOICE, "B", 1) == 0) {
					break;
				}
				else {
					printf("Invalid Selection. Please Try Again.\n");
				}
			}
			if (JARcount > 2) {
				break;
			}
		}
		printf("Finding nothing else of interest, you leave the cabin to\ncarry on to Moonstone Hills.\n");
		return scPara->opt1;
	}
	else if (scnextSTEP == 354) {
		if ((scPC->inv[36] > 0) || (scPC->inv[38] > 0) || (scPC->inv[41] > 0)) {
			printf("You may use:\n");
			if (scPC->inv[36] > 0) {
				printf("[A] Snake oil\n");
			}
			if (scPC->inv[38] > 0) {
				printf("[B] Stikkle wax\n");
			}
			if (scPC->inv[41] > 0) {
				printf("[C] Dried nettles\n");
			}
			while (1) {
				scanf("%s", sCHOICE);
				if ((strncasecmp(sCHOICE, "A", 1) == 0) && (scPC->inv[36] > 0)) {
					return scPara->opt1;
				}
				else if ((strncasecmp(sCHOICE, "B", 1) == 0) && (scPC->inv[38] > 0)) {
					return scPara->opt2;
				}
				else if ((strncasecmp(sCHOICE, "C", 1) == 0) && (scPC->inv[41] > 0)) {
					return scPara->opt3;
				}
				else {
					printf("Invalid Selection. Please Try Again.\n");
				}
			}
		}
		else {
			printf("Paralysis will soon set in and there is nothing you can do\nto stop it.\n");
			scPC->cST = 0;
		}
	}
	else if (scnextSTEP == 355) {
		srandom(time(0));
		SPECIAL = ((random() % 6) + 1);
		if (scPC->cSK > 9) {
			SPECIAL = SPECIAL + 1;
		}
		if (SPECIAL > 5) {
			return scPara->opt2;
		}
		else {
			return scPara->opt1;
		}
	}
	else if (scnextSTEP == 361) {
		int coin;
		for (SPECIAL = 0; SPECIAL < 5; SPECIAL++) {
			srandom(time(0));
			coin = (random() * 2);
			if (coin == 0) {
				if (scPC->inv[0]) {
					scPC->inv[0] = scPC->inv[0] - 1;
					printf("You lost a Gold Piece.\n");
				}
			}
			else if (coin == 1) {
				if (scPC->inv[1] > 0) {
					scPC->inv[1] = scPC->inv[1] - 1;
					printf("You lost a Copper Piece.\n");
				}
			}
		}
		return scPara->opt1;
	}
	else if (scnextSTEP == 377) {
		srandom(time(0));
		SPECIAL = ((random() * 6) + 1);
		printf("%i arrows strike you.\n\nLose %i STAMINA points.\n", SPECIAL, (SPECIAL * 2));
		return scPara->opt1;
	}
	else if (scnextSTEP == 383) {
		tellStory(scnextSTEP, 2);
		while (1) {
			scanf("%s", sCHOICE);
			if (strncasecmp(sCHOICE, "A", 1) == 0) {
				return scPara->opt1;
			}
			else if (strncasecmp(sCHOICE, "B", 1) == 0) {
				return scPara->opt2;
			}
			else if (strncasecmp(sCHOICE, "C", 1) == 0) {
				return scPara->opt3;
			}
			else if (strncasecmp(sCHOICE, "D", 1) == 0) {
				return 212;
			}
		}
	}
	else {
		printf("Error: Special Case %i not found.", scnextSTEP);
	}
}