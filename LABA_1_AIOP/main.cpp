#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "BlockType.hpp"



/// skills 
#include "SkillContract.hpp"

#include "SkillWarrior.hpp"


#include "SkillMage.hpp"
#include "SkillMageJinx.hpp"
#include "SkillMageRay.hpp"


// side effects
#include "SideEffect.hpp"

#include "SideEffectPoisoning.hpp"
#include "SideEffectBleeding.hpp"
#include "SideEffectRegeneration.hpp"

#include "Fighter.hpp"

#include "Magician.hpp"
#include "Warrior.hpp"
#include "Beast.hpp"

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