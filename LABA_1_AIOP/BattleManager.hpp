#include "Player.hpp"

class BattleManager
{
public:

	static Player* makeBattle(Player* firstPlayer, Player* secondPlayer)
	{

	}

protected:

	bool selectBlock(Player* inputPlayer)
	{
		bool wrongInput = false;
		int blockID;
		while (true)
		{
			if (wrongInput)
			{
				wrongInput = false;
				std::cout << "��� ����� ������ ���� ������ � ���������� �� 1 �� 3�. ��������� �������\n";
			}
			std::cout << inputPlayer->getNick() << ", �������� ��� �����:\n";
			std::cout << "1. ������� ����\n";
			std::cout << "2. ������� ����\n";
			std::cout << "3. ����� ����\n";
			std::cout << "����:";
			std::cin >> blockID;
			if (blockID <= 0 || blockID > 3)
			{
				wrongInput = true;
				continue;
			}
			else
			{
				inputPlayer->setBlock(BlockType::DOWN);
			}
		}
	}

};