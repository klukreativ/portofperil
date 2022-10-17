#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*this structure contains all the vital information of the hero*/
typedef struct hero {
	char name[10];
	int mSK;
	int cSK;
	int mST;
	int cST;
	int mLK;
	int cLK;
	int hunger;
	int inv[79]; /*the list is detailed as a static char in header*/
} hero;

/*this structure will recieve info of enemies from an array, then use it in the battleSIM func*/
typedef struct enemy {
	char ename[20];
	int eSK;
	int eST;
} enemy;

/*this contains battles (if any) + #, next paragraphs, conditional, and misc mods*/
typedef struct story {
	int opt1;
	int opt2;
	int opt3;
	int cond;
	int misc1;
	int misc2;
	int misc3;
	int misc4;
} story;

extern unsigned int events[500][8];
extern unsigned char inventory[100][30];
extern unsigned char storytext[500][3][2100];
extern unsigned char theFOE[40][3][20];

void dispTITLE();
void intro();
void tellStory(int nextREAD, int whichP);
void progStory(struct story* sPara, int nextP);
void findFOE(struct enemy* fFOE, int fbatCOUNT);
void emptyINV(struct hero* ePC);
void dispINV(struct hero* iPC);
int batPLUSSIM(struct hero* bpPC, struct story* bpPara, int batTYPE);
void batRESOLVE(struct hero* brPC, int brPCroll, struct enemy* brFOE, int brFOEroll, struct story* brPara, int brCOND);
int specCOND(struct hero* scPC, struct story* scPara, int scnextSTEP);
int condStory(struct hero* cPC, struct story* cPara, int cnextSTEP);
int makeChoice(struct hero* mcPC, struct story* SC, int nS);