#include "Player.hpp"
#include "BattleManager.hpp"
#include "Doomguy.hpp"

class Session
{
public:

	void startSession()
	{
		std::cout << "Добро пожаловать на ринг!\n";
		Player* firstPlayer = selectCharacter(1);
		Player* secondPlayer = selectCharacter(2);

		firstPlayer->setNick("nessai1");
		secondPlayer->setNick("dancer1232");
		BattleManager::makeBattle(firstPlayer, secondPlayer);
	}

protected:

	Player* selectCharacter(int playerNumber)
	{
		int personID;
		Player* personPlayer;
		std::cout << "Игрок " << playerNumber << ", выберите своего персонажа\n";
		std::cout << "1. Палач рока\n";
		std::cout << "2. Коготь смерти\n";
		std::cout << "3. Касадор\n";
		std::cout << "ВВОД: ";
		std::cin >> personID;
		switch (personID)
		{
		default:
			personPlayer = new Doomguy;
			break;
		}
		return personPlayer;
	}

};