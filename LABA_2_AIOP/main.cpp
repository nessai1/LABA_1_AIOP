#include <iostream>
#include <string>
#include <ctime>
#include "BlockType.hpp"
#include "Player.hpp"
#include "Ranger.hpp"
#include "Doomguy.hpp"
#include "BattleManager.hpp"
#include "Session.hpp"


int main()
{
	setlocale(LC_ALL, "rus");
	Session* game = new Session();
	game->startSession();
	return 0;
}