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
				std::cout << "Вид атаки должен быть числом в промежутке от 1 до 3х. Повторите попытку\n";
			}
			std::cout << attacker->getNick() << ", выберите тип блока:\n";
			std::cout << "1. Верхняя атака\n";
			std::cout << "2. Средняя атака\n";
			std::cout << "3. Нижняя атака\n";
			std::cout << "ВВОД:";
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
				std::cout << "Тип блока должен быть числом в промежутке от 1 до 3х. Повторите попытку\n";
			}
			std::cout << inputPlayer->getNick() << ", выберите тип блока:\n";
			std::cout << "1. Верхний блок\n";
			std::cout << "2. Средний блок\n";
			std::cout << "3. Нижий блок\n";
			std::cout << "ВВОД:";
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