#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <Windows.h>

#include "DamageType.h"

/// skills 
#include "Skill.hpp"

// common skills 
#include "SkillFist.hpp"
#include "SkillPiercing.hpp"

// warrior skills
#include "SkillWarrior.hpp"
#include "SkillWarriorSword.hpp"
#include "SkillWarriorPush.hpp"
#include "SkillWarriorPiercing.hpp"

// mage skills
#include "SkillMage.hpp"
#include "SkillMageJinx.hpp"
#include "SkillMageRay.hpp"
#include "SkillMageTornado.hpp"
#include "SkillMageFall.hpp"

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
	Session* game = new Session();
	game->startSession();
	return 0;
}