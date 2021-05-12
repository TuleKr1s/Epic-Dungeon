#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::string;

extern double hp = 60.0, damage = 15.0, shield = 100.0;
extern double en_hp = 50.0, en_damage = 10.0, en_shield = 100.0;
extern double boss_hp = 1000.0, boss_damage = 250.0, boss_shield = 150;
extern int boss_lvl = 1;
extern int en_level = 1, hero_level = 1, energy = 6, gold = 0, skills = 0;
extern int experience = 0, new_lvl_xp = 10;
extern double en_fight_hp = en_hp;
extern double hero_fight_hp = hp;
extern int fight_energy = energy;
extern double boss_fight_hp = boss_hp;


int startGame();									//Game start functionality
void mainMenu();									//Main menu
void menuSkills();									//Skill menu
void menuHero();									//Hero menu
void menuLvl();										//Progress menu
void menuDev();										//Creators menu

void imgFightBoss();								//Boss Fight Visual
void imgFightNPC();									//Dungeon NPC combat visual
double fightNPC(double x, double y, double z);		//Functionality of the fight with NPCs from the dungeon
double fightHeroNpc(double x, double y, double z);	//The functionality of the battle with the Hero in the dungeon

void fightAttack();									//Simple attack function in combat
void fightDodge();									//Dodge attack function in combat
void fightShield();									//Shield function in battle
void fightHeal();									//Combat healing function

void fightAttackBoss();								//Simple attack function in boss fight
void fightDodgeBoss();								//Dodge attack function in boss fight
void fightShieldBoss();								//Shield function in boss fight
void fightHealBoss();								//Boss Fight Healing Function

void winBattleNPC();								//Victory in a battle with an NPC
void winBattleBoss();								//Winning a Boss Fight


int main() {
	system("chcp 1251>nul");
	startGame();
	return 0;
}


void mainMenu() {				//Main menu with a choice of actions
	cout << "Choose an action:\nGo to the boss: 1\nGo to the dungeon: 2\nSkills: 3\nHero characteristics: 4\nExit to the start menu: 5\n";
	char choose;
	cin >> choose;
	switch (choose) {
		case '1':
			imgFightBoss();
			break;
		case '2':
			imgFightNPC();
			break;
		case '3':
			menuSkills();
			break;
		case '4':
			
			menuHero();
			break;
		case '5':
			startGame();
			break;
		default:
			cout << "\t\t\t\t\t\tI do not understand what you want?\n";
			mainMenu();
			break;
	}

}

int startGame() {				//Game start functionality
	cout << "Start the game: 1\nQuit the game: 2\nCreators: 3\n";
	char choose;
	cin >> choose;
	switch (choose) {
		case '1':
			mainMenu();
			break;
		case '2':
			return 0;
			break;
		case '3':
			menuDev();
			break;
		default:
			cout << "\t\t\t\t\t\tI don't understand what is required!\n";
			startGame();
	}
	
}


    
void menuSkills() {				//Skills menu
	cout << "\t\t\t\t\t\t\t  Skill points: " << skills << "\n";
	cout << "\t\t\t\t\t\tHealth: " << hp << " Damage: " << damage << " Protection: " << shield << "\n";
	cout << "Select an action:\nImprove health skill: 1\nIncrease attack skill: 2\nIncrease Armor Skill: 3\nBack: 4\n";
	char choose;
	cin >> choose;
	switch (choose) {
		case '1':
			if (skills >= 1) {
				hp += 10.0;
				skills -= 1;
				hero_fight_hp = hp;
				menuSkills();
			}   
			else {
				cout << "\t\t\t\t\t\t   Not enough skill points!\n";
				menuSkills();
			}
			break;
		case '2':
			if (skills >= 1) {
				damage += 3.0;
				skills -= 1;
				menuSkills();
			}
			else {
				cout << "\t\t\t\t\t\t   Not enough skill points!\n";
				menuSkills();
			}
			break;
		case '3':
			if (skills >= 1) {
				if (shield < 500) {
					shield += 12.5;
					skills -= 1;
					menuSkills();
				}
				else {
					cout << "\t\t\t\t\t\tMaximum armor value reached!\n";
					menuSkills();
				}
			}
			else {
				cout << "\t\t\t\t\t\t   Not enough skill points!\n";
				menuSkills();
			}
			break;
		case '4':
			mainMenu();
			break;
		default:
			cout << "\t\t\t\t\t\tI don't understand what is required of me\n";
			menuSkills();
			break;
	}
}
void menuHero() {			//Hero menu
	cout << "\t\t\t\t\t\t ____________________\n";
	cout << "\t\t\t\t\t\t|                    |\n";
	cout << "\t\t\t\t\t\t  Level:         " << hero_level << "\n";
	cout << "\t\t\t\t\t\t  Skill points:  " << skills << "\n";
	cout << "\t\t\t\t\t\t  Health:        " << hp << "\n";
	cout << "\t\t\t\t\t\t  Damage:        " << damage << "\n";
	cout << "\t\t\t\t\t\t  Protection:    " << shield << "\n";
	cout << "\t\t\t\t\t\t|____________________|\n\n";
	cout << "\t\t\t\t\tView character level progress: 1\n";
	cout << "\t\t\t\t\tExit to the main menu:                 2\n";
	char choose;
	cin >> choose;
	switch (choose) {
		case '1':
			menuLvl();
			break;
		case '2':
			mainMenu();
			break;
		default:
			cout << "\t\t\t\t\t    I don't understand what is required of me\n";
			menuHero();
			break;
	}
}
void menuLvl() {
	cout << "\t\t\t\t\t\t ___________________\n";
	cout << "\t\t\t\t\t\t|                   |\n";
	cout << "\t\t\t\t\t\t      Level: " << hero_level << "\n";
	cout << "\t\t\t\t\t\t   Level progress:\n";
	cout << "\t\t\t\t\t\t        " << experience << "/" << new_lvl_xp << "\n";
	cout << "\t\t\t\t\t\t|___________________|\n";
	cout << "\t\t\t\t\t\t       Back: 1\n";
	char choose;
	cin >> choose;
	switch (choose) {
		case '1':
			menuHero();
			break;
		default:
			cout << "\t\t\t\t\t    I don't understand what is required of me\n";
			menuLvl();

	}
}


void menuDev() {
	cout << "\t\t\t\t\t\t ____________________\n";
	cout << "\t\t\t\t\t\t|                    |\n";
	cout << "\t\t\t\t\t\t      Idea creator: \n";
	cout << "\t\t\t\t\t\t   Rakhimzhanov Gleb\n";
	cout << "\t\t\t\t\t\t      Developer: \n";
	cout << "\t\t\t\t\t\t       TuleKr1s\n";
	cout << "\t\t\t\t\t\t|____________________|\n";
	cout << "\t\t\t\t\t\t     Back: 1\n";
	char choose;
	cin >> choose;
	switch (choose) {
	case '1':
		startGame();
		break;
	default:
		cout << "\t\t\t\t\t    I don't understand what is required of me\n";
		menuDev();

	}
}

void imgFightNPC() {				//displaying information on the battle with npc (yes, I know it's so awful)
	if (en_fight_hp > 0) {
		cout << "\t\t\t\t\t _______________________________________\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t                            YOU\n";
		cout << "\t\t\t\t                         energy: " << fight_energy << "\n";
		cout << "\t\t\t\t\n";
		cout << "\t\t\t\t                        hp      : " << hero_fight_hp << "\n";
		cout << "\t\t\t\t                        power   : " << damage << "\n";
		cout << "\t\t\t\t                        shield  : " << shield << "\n";
		cout << "\t\t\t\t         __                                   __\n";
		cout << "\t\t\t\t        |                                       |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |  |Attack:         1|  |Shield:    3|  |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |  |Attack + Dodge: 2|  |Healing:   4|  |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |                                       |\n";
		cout << "\t\t\t\t        |__                                   __|\n";
		cout << "\t\t\t\t                             DEVIL\n";
		cout << "\t\t\t\t                          level: " << en_level << "\n";
		cout << "\t\t\t\t\n";
		cout << "\t\t\t\t                        hp      : " << en_fight_hp << "\n";
		cout << "\t\t\t\t                        power   : " << en_damage << "\n";
		cout << "\t\t\t\t                        shield  : " << en_shield << "\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|_______________________________________|\n";
		char choose;
		cin >> choose;
		switch (choose) {
		case '1':			//attack

			fightAttack();
			imgFightNPC();
			break;
		case '2':			//attack + dodge

			fightDodge();
			imgFightNPC();
			break;
		case '3':			//shield

			fightShield();
			imgFightNPC();
			break;
		case '4':			//healing

			fightHeal();
			imgFightNPC();
			break;
		default:

			cout << "\t\t\t\t\t  I don't understand what is required of me\n";
			imgFightNPC();
			break;
		}
	}
	else {

		winBattleNPC();
		mainMenu();

	}
}
string boss_kind = "Satan";
void imgFightBoss() {						//displaying information on the battle with boss

	if (boss_lvl > 3) {

		cout << "\t\t\t\t\t\tYou have defeated all possible bosses!\n";
		mainMenu();

	}


	if (boss_fight_hp > 0) {
		cout << "\t\t\t\t\t _______________________________________\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t                            YOU\n";
		cout << "\t\t\t\t                         energy: " << fight_energy << "\n";
		cout << "\t\t\t\t\n";
		cout << "\t\t\t\t                        hp      : " << hero_fight_hp << "\n";
		cout << "\t\t\t\t                        power   : " << damage << "\n";
		cout << "\t\t\t\t                        shield  : " << shield << "\n";
		cout << "\t\t\t\t         __                                   __\n";
		cout << "\t\t\t\t        |                                       |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |  |Attack:         1|  |Shield:    3|  |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |  |Attack + Dodge: 2|  |Healing:   4|  |\n";
		cout << "\t\t\t\t        |  |=================|  |============|  |\n";
		cout << "\t\t\t\t        |                                       |\n";
		cout << "\t\t\t\t        |__                                   __|\n";
		cout << "\t\t\t\t                            BOSS\n";
		cout << "\t\t\t\t                         kind: " << boss_kind << "\n";
		cout << "\t\t\t\t\n";
		cout << "\t\t\t\t                        hp      : " << boss_fight_hp << "\n";
		cout << "\t\t\t\t                        power   : " << boss_damage << "\n";
		cout << "\t\t\t\t                        shield  : " << boss_shield << "\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|                                       |\n";
		cout << "\t\t\t\t\t|_______________________________________|\n";
		char choose;
		cin >> choose;
		switch (choose) {
		case '1':			//attack

			fightAttackBoss();
			imgFightBoss();

			break;
		case '2':			//attack + dodge

			fightDodgeBoss();
			imgFightBoss();

			break;
		case '3':			//shield

			fightShieldBoss();
			imgFightBoss();

			break;
		case '4':			//healing

			fightHealBoss();
			imgFightBoss();

			break;
		default:

			cout << "\t\t\t\t\t  I don't understand what is required of me!\n";
			imgFightNPC();
			break;
		}
	}
	else {

		winBattleBoss();
		mainMenu();

	}
}

void fightAttack() {				//attack function

	if (fight_energy == 0) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightNPC();
	}

	en_fight_hp = fightNPC(en_fight_hp, damage, en_shield);
	hero_fight_hp = fightHeroNpc(hero_fight_hp, en_damage, shield);
	--fight_energy;

	if (hero_fight_hp <= 0 && en_fight_hp > 0) {
		cout << "\t\t\t\t\t\tYou have failed!\n";
		fight_energy = energy;
		hero_fight_hp = hp;
		en_fight_hp = en_hp;
		mainMenu();
	}

}

void fightAttackBoss() {			//attack function with boss
	if (fight_energy == 0) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightBoss();
	}

	boss_fight_hp = fightNPC(boss_fight_hp, damage, boss_shield);
	hero_fight_hp = fightHeroNpc(hero_fight_hp, boss_damage, shield);
	--fight_energy;

	if (hero_fight_hp <= 0 && boss_fight_hp > 0) {
		cout << "\t\t\t\t\t\tYou have failed!\n";
		fight_energy = energy;
		hero_fight_hp = hp;
		boss_fight_hp = boss_hp;
		mainMenu();
	}
}

void fightDodge() {					//attack + dodge function

	if (fight_energy <= 1) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightNPC();
	}

	en_fight_hp = fightNPC(en_fight_hp, damage, en_shield);
	fight_energy -= 2;


}

void fightDodgeBoss() {				//attack + dodge funcion with boss
	if (fight_energy <= 1) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightBoss();
	}

	boss_fight_hp = fightNPC(boss_fight_hp, damage, boss_shield);
	fight_energy -= 2;

}

void fightShield() {				//shield function

	++fight_energy;
	hero_fight_hp = fightHeroNpc(hero_fight_hp, en_damage, shield);

	if (hero_fight_hp <= 0 && en_fight_hp > 0) {
		cout << "\t\t\t\t\t\tYou have failed!\n";
		fight_energy = energy;
		hero_fight_hp = hp;
		en_fight_hp = en_hp;
		mainMenu();
	}

}

void fightShieldBoss() {

	++fight_energy;
	hero_fight_hp = fightHeroNpc(hero_fight_hp, boss_damage, shield);

	if (hero_fight_hp <= 0 && boss_fight_hp > 0) {
		cout << "\t\t\t\t\t\tYou have failed!\n";
		fight_energy = energy;
		hero_fight_hp = hp;
		boss_fight_hp = boss_hp;
		mainMenu();
	}

}

void fightHeal() {					//healing function

	if (fight_energy <= 1) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightNPC();
	}

	hero_fight_hp += 20.0;
	fight_energy -= 2;

}

void fightHealBoss() {				//healing function with boss

	if (fight_energy <= 1) {
		cout << "\t\t\t\tNot enough energy! Use your shield to boost her!\n";
		imgFightBoss();
	}

	hero_fight_hp += 100.0;
	fight_energy -= 2;

}

void winBattleNPC() {				//battle victory function with NPC

	int xp = rand() % 5 + 1;			//obtained in battle
	cout << "\t\t\t\t\t\t  You have won! Received:\n";
	cout << "\t\t\t\t\t\t     Skill points: 5\n";
	cout << "\t\t\t\t\t\t     Experience: " << xp << "\n";
	experience += xp;					//received in battle, add to the total amount
	if (experience >= new_lvl_xp) {
		cout << "\t\t\t\t\t\tYou've got a new level!\n";
		++hero_level;
		experience -= new_lvl_xp;
		new_lvl_xp += (new_lvl_xp / 4);
	}
	en_hp += 40;
	en_damage += 15;
	++en_level;
	skills += 5;
	fight_energy = energy;
	en_fight_hp = en_hp;
	hero_fight_hp = hp;


}

void winBattleBoss() {				//battle victory function with Boss


	int xp = rand() % 10 + 10;			//obtained in battle
	cout << "\t\t\t\t\t\t  You have won! Received:\n";
	cout << "\t\t\t\t\t\t     Skill points: 10\n";
	cout << "\t\t\t\t\t\t     Experience: " << xp << "\n";
	experience += xp;					//received in battle, add to the total amount
	if (experience >= new_lvl_xp) {
		cout << "\t\t\t\t\t\tYou've got a new level\n";
		++hero_level;
		experience -= new_lvl_xp;
		new_lvl_xp += (new_lvl_xp / 4);
	}
	++boss_lvl;

	if (boss_lvl == 1) {
		boss_kind = "Satan";
	}
	else if (boss_lvl == 2) {
		boss_kind = "Lucifer";
		boss_hp = 2000;
		boss_damage = 500;
		boss_shield = 200;
	}
	else if (boss_lvl == 3) {
		boss_kind = "Leviathan";
		boss_hp = 4000;
		boss_damage = 800;
		boss_shield = 300;
	}

	if (boss_lvl > 3) {
		cout << "\t\t\t\t\t\tCongratulations! Defeated all possible bosses!\n";
	}
	skills += 10;
	fight_energy = energy;
	boss_fight_hp = boss_hp;
	hero_fight_hp = hp;


}

//I know it could be easier, but it's easier for me this way (I love shit code)

double fightNPC(double x, double y, double z) {				//change enemy hp in fight
	x -= y * (1 - z / 1000);									//x - enemy hp, y - hero damage, z - enemy shield
	return x;
}
double fightHeroNpc(double x, double y, double z) {			//change hero hp in fight
	x -= y * (1 - z / 1000);									//x - hero hp, y - enemy damage, z - hero shield
	return x;
}