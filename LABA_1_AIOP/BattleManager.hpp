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
				std::cout << "Тип блока должен быть числом в промежутке от 1 до 3х. Повторите попытку\n";
			}
			std::cout << inputPlayer->getNick() << ", выберите тип блока:\n";
			std::cout << "1. Верхний блок\n";
			std::cout << "2. Средний блок\n";
			std::cout << "3. Нижий блок\n";
			std::cout << "ВВОД:";
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