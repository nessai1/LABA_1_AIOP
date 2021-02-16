#include "Player.hpp"
#include "BattleManager.hpp"
#include "Doomguy.hpp"

class Session
{
public:

	void startSession()
	{
		std::cout << "����� ���������� �� ����!\n";
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
		std::cout << "����� " << playerNumber << ", �������� ������ ���������\n";
		std::cout << "1. ����� ����\n";
		std::cout << "2. ������ ������\n";
		std::cout << "3. �������\n";
		std::cout << "����: ";
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