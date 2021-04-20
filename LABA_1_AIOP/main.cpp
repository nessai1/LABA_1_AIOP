#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <Windows.h>

#include "DamageType.h"

/// skills 
#include "Skill.hpp"

#include "SkillWarrior.hpp"


#include "SkillMage.hpp"
#include "SkillMageJinx.hpp"
#include "SkillMageRay.hpp"

#include "Fighter.hpp"

#include "Magician.hpp"
#include "Warrior.hpp"
#include "Beast.hpp"


#include "BattleManager.hpp"
#include "Session.hpp"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus");
	Session* game = new Session();
	game->startSession();
	return 0;
}