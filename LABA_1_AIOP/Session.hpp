#include "Player.h"
#include "Doomguy.hpp"

class Session
{
public:

	void startSession()
	{
		std::cout << "Добро пожаловать на ринг!\n";
		std::cout << ""
	}

protected:

	Player* selectCharacter(int playerNumber)
	{
		std::cout << "Игрок " << playerNumber << ", выберите своего персонажа"
		return new Doomguy;
	}

};