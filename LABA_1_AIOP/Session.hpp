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
	}

protected:

	Player* selectCharacter(int playerNumber)
	{
		std::cout << "����� " << playerNumber << ", �������� ������ ���������\n";
		std::cout << "1. ����� ����\n";
		std::cout << "2. ������ ������\n";
		std::cout << "3. �������\n";
		std::cout << "����: ";
	}

};