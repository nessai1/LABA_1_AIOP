#include "Player.hpp"

class BattleManager
{
public:

	static Player* makeBattle(Player* firstPlayer, Player* secondPlayer)
	{
		while (firstPlayer->isAlive() && secondPlayer->isAlive())
		{
			makeTurn(firstPlayer, secondPlayer);
			std::swap(firstPlayer, secondPlayer);
		}

		if (firstPlayer->isAlive())
		{
			return firstPlayer;
		}
		else
		{
			return secondPlayer;
		}
	}

protected:

	static void makeTurn(Player* attacker, Player* defenser)
	{
		bool wrongInput = false;
		int attackID;
		bool attackResult = true;
		
		selectBlock(defenser);

		while (true)
		{
			if (wrongInput)
			{
				wrongInput = false;
				std::cout << "��� ����� ������ ���� ������ � ���������� �� 1 �� 3�. ��������� �������\n";
			}
			std::cout << attacker->getNick() << ", �������� ��� �����:\n";
			std::cout << "1. ������� �����\n";
			std::cout << "2. ������� �����\n";
			std::cout << "3. ������ �����\n";
			std::cout << "����:";
			std::cin >> attackID;

			switch (attackID)
			{
			case 1:
				attackResult = attacker->attackUp(defenser);
				break;
			default:
				wrongInput = true;
				continue;
			}

			break;
		}

		defenser->setBlock(BlockType::NONE);

		if (!attackResult)
		{
			defenser->attackUltimate(attacker);
		}

	}

	static void selectBlock(Player* inputPlayer)
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

			switch (blockID)
			{
			case 1:
				inputPlayer->setBlock(BlockType::UP);
				break;
			case 2:
				inputPlayer->setBlock(BlockType::MIDDLE);
				break;
			case 3:
				inputPlayer->setBlock(BlockType::DOWN);
				break;
			default:
				wrongInput = true;
				continue;
			}

			break;
		}

	}

};