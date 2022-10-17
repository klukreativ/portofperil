#include <stdio.h>
#include "pop-header.h"

void dispTITLE() {
	printf(" -------------------------------------------------------------------------------------\n");
	printf("|                             ______   ______   _____   _______                       |\n");
	printf("|     _____  _   _  ____     |  __  \\ |  __  | |  __ \\ |__   __|     ___   ____       |\n");
	printf("|    |_   _|| |_| || ___|    | |__| | | |  | | | |__| |   | |       / _ \\ | ___|      |\n");
	printf("|      | |  |  _  || __|     |  ____/ | |  | | |     /    | |      | |_| ||  _|       |\n");
	printf("|      |_|  |_| |_||____|    | |      | |__| | | |\\  \\    | |       \\___/ |_|         |\n");
	printf("|                            |_|      |______| |_| \\__\\   |_|                         |\n");
	printf("|     ____________      _____________    ___________      __________    ____          |\n");
	printf("|    |            \\    |             |  |           \\    |          |  |    |         |\n");
	printf("|    |     ____    \\   |     ________|  |      ___   \\   |___    ___|  |    |         |\n");
	printf("|    |    |    |    |  |     |          |     |   \\   |      |  |      |    |         |\n");
	printf("|    |    |____|    |  |     |____      |     |___/   |      |  |      |    |         |\n");
	printf("|    |              |  |          |     |            /       |  |      |    |         |\n");
	printf("|    |     ________/   |     _____|     |           /        |  |      |    |         |\n");
	printf("|    |    |            |    |           |     |\\    \\        |  |      |    |         |\n");
	printf("|    |    |            |    |________   |     | \\    \\    ___|  |___   |    |____     |\n");
	printf("|    |    |            |             |  |     |  \\    \\  |          |  |         |    |\n");
	printf("|    |____|            |_____________|  |_____|   \\____\\ |__________|  |_________|    |\n");
	printf("|_____________________________________________________________________________________|\n");
}

/*this is the background story before beginning the adventure*/
void intro() {
	char introSTORY[26][1200] = {
		"Chalice is an affluent town on the north bank of Silver\nRiver, a wide, twisting river which flows gently down\nfrom the Moonstone Hills to merge with Catfish River on\nits way to the Western Ocean. It began as nothing more\nthan a merchant's store built at the end of a wooden jetty\nused by river traders to aldn their goods. At first, trade\nwas very slow, and the merchant complained he'd been\nhanded a poisoned chalice. Trade slowly improved, but\nthe name stuck, and over time Chalice grew to become a\nbusy river port.\n",
		"Chalice's inhabitants are mostly human, and it is also\nhome to a number of other races. There are Elves, who\nalways seem to know more about what's going on than\nanybody else; Striders, who run around town on their\nspindly long legs doing errands; Man-Orcs, who are\nusually hired as guards; Gnomes, who spend most of their\ntime slurping down bowls of pea soup; two beefy Ogres,\nwho hire themselves out to do most of the heavy lifting\njobs, and an unusually friendly Cyclops, who arrived\none day long ago with goods to trade and never left. He\nacquired the nickname of Cy, became a blacksmith, and\nquickly built a reputation as the best smithy in Chalice.\nHe later turned his skills to crafting the finest swords\nin Northern Allansia, but never made more than one a\nmonth, as he refused to compromise on quality. Cy proudly\nsells his famous 'One Eye' swords for 50 Gold Pieces each.\nA 'quality price for a quality product,' as he says with gusto\nto his customers, and he is never short of those.\n",
		"Commerce is the main reason for Chalice's prosperity.\nMerchants arrive from all over Allansia to sell their\nwares in the town, where prices are always at a premium.\nVendors pack the market square six days a week selling\nweapons, armour, potions, lotions, herbs, spices, grain,\nlivestock, semi-precious stones, jewellery, silk, furs, fine\ntextiles and exotic foodstuffs. Money changes hands\nfrom dawn till dusk in brisk trading. Although Chalice\nhas its fair share of improverished folk, it affords nobles,\nmerchants, landlords, and innkeepers a fine living. And\nlike any large town with wealthy inhabitants, Chalice also\nattracts pickpockets and thieves who see the opportunity\nto relieve some of the more naive townsfolk of their\nhard-earned silver and gold. Young con artists learn their\ndevious skills in Chalice, spinning yarns and practising\ntheir scams on the locals. If they don't get caught, the\nbest of them journey downriver to try their luck on the\ncitizens of Port Blacksand, where they must compete with\nhardened professional thieves and vagabonds.\n",
		"YOU are a seasoned adventurer, an experienced sword-\nfor-hire who enjoys slaying monsters and finding treasure\nabove anything else. Despite some memorable adventures,\nyou have learned the hard way that treasure hunting does\nnot always guarantee the reward of glittering gold. More\noften than not, treasure hunters come back from their\nexpeditions empty-handed. And when things don't go\nwell, adventurers reluctantly have to resort to working for\nothers, usually earning a low wage guarding rich nobles'\nestates or protecting merchants' caravans on their\njourneys to market. You recently arrived in Chalice tired\nand hungry after spending a month scouring the Paga\nPlains trying, but failing, to find the buried treasure\nhoard of Throm, the notorious axe-wielding barbarian\nwho, rumour has it, died in Baron Sukumvit's infamous\nDeathtrap Dungeon in Fang trying to win the grand prize\nof 10,000 Gold Pieces.\n",
		"Your days spent in Chalice have been anything but\nenjoyable. Unable to find work, you are forced to sleep\nrough in alleyways, scavenging for scraps of food left\nabandoned by traders in the market square at the end\nof the day. It is a warm evening on day four of your stay.\nThe sun is slowly sinking in the western sky and the\nlight is beginning to fade. You are standing outside the\nFat Frog Inn drooling over the menu nailed to the oak\ndoor when two men stagger outside arm in arm. One\nis middle-aged, bearded, and wearing a brown leather\ntunic over dark green leggings, whilst the younger one\nis wearing a checked woollen shirt tucked into his baggy\nbrown pants. Both men are giggling like children, very\nmuch the worse for the amount of ale they have drunk.\nThey brush past you, oblivious to everything. The\nyounger man is hiccuping and swaying erratically from\nside to side. He tries to grab hold of the back of a wooden\nbench to steady himself, but misses it, and falls over,\ncursing. This causes his friend to laugh even louder. The\nyounger man sits up, squinting in the bright light, his\nmouth hanging open like a gormless fool.\n",
		"'Eryk!' the younger man splutters, hiccuping.\n",
		"'What?'\n",
		"'Stop laughing at me.'\n",
		"'Why?'\n",
		"'Because I'm going to be rich!'\n",
		"'Shut up,' the older man replies dismissively.\n",
		"'I am! I'm going to be rich! I bought a treasure map!' he\nretorts, reaching into his pocket to produce an old piece\nof parchment as evidence. Too drunk to notice that he's\nholding it upside down, he stares at it with a befuddled\nexpression on his face. Although you're well within\nearshot, you pretend not to be listening.\n",
		"'How much did you pay for it?'\n",
		"'Four Copper Pieces.'\n",
		"'Four Copper Pieces? What a fool you are. There's not a\nhope that it's genuine. You've been done, Gregor,' the\nolder man says, laughing even louder. 'Stitched up like\na kipper. A fool chasing fool's gold, that's what you are.\nYou just don't learn, do you? You can't believe anything\nanyone says in the Fat Frog Inn.'\n",
		"'But... But that old man seemed so genuine. He had an\nhonest face, unlike all those other sharks and villains in\nthere giving it large. I wanted to believe him. I did believe\nhim!'\n",
		"'Are you going to go back in to get your money back?'\n",
		"'Nah, the poor man needed the money. He sounded\ndesperate. I felt sorry for him. That's why I bought the\nmap really. No hard feelings. I enjoyed listening to his\ntale about the iron chest filled with golden amulets. He\nsaid it was hidden deep inside a cave in Moonstone Hills.\nAnd he kept going on about a gold ring in the chest. Said\nit was more valuable than all the amulets put together.\nWhat did he call it again? The Ring of... Oh, fiddle! I can't\nremember now. But it doesn't matter if it isn't true! Or you\nsay it isn't true. Or whatever.'\n",
		"'Forget about it, Gregor. He made it all up'\n",
		"'The Ring of Burning Snakes! That's what he called it.\nHe said it used to belong to an old wizard called Nico or\nNico something or other. He said the wizard would pay a\npretty penny to get it back.'\n",
		"'I said forget about it, Gregor. Come on, get up, let's try\nthe Sun Inn next. I'm thirsty!' Eryk says sternly, pulling\nhis friend up off the ground.\n",
		"'All right, all right. I won't be needing this, then!' Gregor\nsays, crumpling up the parchment into a ball and tossing\nit over his shoulder before staggering off.\n"
		"The parchment ball lands just by your feet. Intrigued,\nyou bend down to pick it up. You unfold it to reveal a very\ndetailed hand-drawn map of the land surrounding Chalice.\n",
		"The map shows a dotted line heading north from Chalice,\nthen east, some way south of Darkwood Forest, crossing\nthe Eastern Plain to Moonstone Hills, where a large X\nmarks the entrance to a cave in Skull Crag, one of the\nhighest peaks in the range. There is a message in tiny\nhandwriting written in black ink on the back of the map\nwhich says:\n",
		"'Do NOT enter by the cave entrance. Climb the crag\nto a ledge twenty meters above. Move the standing branches\naside to reveal the secret entrance. Enter here and turn\nleft, right, right, at the junctions. An iron chest will be\nfound in the Crystal Cave.\n\nGood luck!\nMurgat Shurr'\n",
		"Could a treasure chest really lie hidden in a cave inside\nSkull Crag? Why would an old man sell his secrets for a\nfew Copper Pieces? And who is Murgat Shurr? Nothing\nmakes sense. You are about to toss the map away when\nyou hear the shrill squawk of a bird overhead. You look\nup to see a crow flying north. Could it be an omen?\nCould this be your lucky day after all? You decide you\nhave nothing to lose and everything to gain. You fold\nup the parchment and put it safely away in your pocket.\nTomorrow you will set off for Skull Crag. But right now\nyou need to find some food and somewhere to sleep\nbefore nightfall.\n"
	};
	int READintro;
	for (READintro = 0; READintro < 26; READintro++) {
		printf("%s", introSTORY[READintro]);
		getchar();
	}
}