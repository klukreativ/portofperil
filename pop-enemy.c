#include "pop-header.h"

/*this function will search for the correct enemy and assign the data to a pointer*/
unsigned char theFOE[40][3][20] = {
	{"First Bandit", "6", "7"},	{"Second Bandit", "7", "7" }, {"Third Bandit", "7", "6"},
	{"Norgul", "10", "9"},
	{"Warhawk", "8", "8"},
	{"Imperial Guard Troll", "11", "11"},
	{"First Gronk", "5", "5"}, {"Second Gronk", "5", "4"}, {"Third Gronk", "5", "4"},
	{"Hill Troll", "10", "10"},
	{"Hippohog", "9", "8"},
	{"Ogre", "8", "10"},
	{"Chaos Warrior", "10", "11"},
	{"First Wild Hill Man", "6", "5"}, {"Second Wild Hill Man", "6", "6"},
	{"Vampire Bug", "6", "5"},
	{"Scorpion Bug", "8", "10"},
	{"Zombie", "6", "5"},
	{"Quag-Shugguth", "12", "13"},
	{"Dwarf", "7", "7"},
	/*21*/
	{"First Blue Imp", "6", "5"}, {"Second Blue Imp", "6", "4"}, {"Third Blue Imp", "6", "5"},
	{"First Dark Elf", "8", "6"}, {"Second Dark Elf", "8", "7"}, {"Third Dark Elf", "7", "7"},
	{"First Robber", "6", "6"}, {"Second Robber", "6", "5"}, {"Third Robber", "7", "6"},
	{"Plague Witch", "5", "5"},
	{"Giant Centipede", "8", "7"},
	{"Bandit", "6", "7"},
	{"First Man-Orc", "5", "6"}, {"Second Man-Orc", "5", "4"},
	{"Giant Lavaworm", "9", "9"},
	{"First Goblin", "5", "5"}, {"Second Goblin", "5", "4"},
	{"Man-Orc", "6", "6"},
	{"First Attack Dog", "6", "6"}, {"Second Attack Dog", "6", "7"}
};