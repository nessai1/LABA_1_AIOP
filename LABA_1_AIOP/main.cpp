#include <iostream>
#include <string>
#include <ctime>
#include "BlockType.hpp"
#include "Player.hpp"


/// skills 
#include "SkillContract.hpp"
#include "SideEffect.hpp"

#include "SkillWarrior.hpp"

#include "SkillMage.hpp"
#include "SkillMageJinx.hpp"


// side effects
#include "SideEffect.hpp"

#include "SideEffectPoisoning.hpp"

#include "Fighter.hpp"
#include "Warrior.hpp"
#include "DeathÑlaw.hpp"
#include "Ranger.hpp"
#include "Doomguy.hpp"
#include "BattleManager.hpp"
#include "FighterBuilder.hpp"
#include "Session.hpp"



int main()
{
	setlocale(LC_ALL, "rus");
	Session* game = new Session();
	game->startSession();
	return 0;
}