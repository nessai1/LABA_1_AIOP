

class Session
{
public:

	void startSession()
	{
		std::cout << "Добро пожаловать на ринг!\n";
		Player* firstPlayer = selectCharacter(1);
		Player* secondPlayer = selectCharacter(2);

		firstPlayer->setNick("Игрок 1");
		secondPlayer->setNick("Игрок 2");

		srand(time(0));
		int turn = rand() % 2;

		std::cout << std::endl;

		if (!turn)
		{
			std::cout << firstPlayer->getNick() << " предначертано быть первым\n";
		}
		else
		{
			std::cout << secondPlayer->getNick() << " предначертано быть первым\n";
			std::swap(firstPlayer, secondPlayer);
		}

		Player* winner = BattleManager::makeBattle(firstPlayer, secondPlayer);
		system("cls");
		std::cout << winner->getNick() << " выжил в этой смертельной битве и стал победителем!!\n";
	}

protected:

	Player* selectCharacter(int playerNumber)
	{
		int personID;
		bool wrongInput = false;
		Player* personPlayer;
		while (true)
		{
			if (wrongInput)
			{
				wrongInput = false;
				std::cout << "Вы должны выбрать одного из трех персонажей. Введите номер от 1 до 3х.\n";
			}
			std::cout << "Игрок " << playerNumber << ", выберите своего персонажа\n";
			std::cout << "1. Палач рока\n";
			std::cout << "2. Коготь смерти\n";
			std::cout << "3. Рейнджер НКР\n";
			std::cout << "ВВОД: ";
			std::cin >> personID;
			switch (personID)
			{
			case 1:
				personPlayer = new Doomguy;
				break;
			case 2:
				personPlayer = new DeathClaw;
				break;
			case 3:
				personPlayer = new Ranger;
				break;
			default:
				wrongInput = true;
				continue;
			}

			break;
		}
		
		return personPlayer;
	}

};