

class Session
{
public:

	void startSession()
	{
		std::cout << "Да начнется же битва!\n";
		Player* firstPlayer = selectCharacter(1);
		Player* secondPlayer = selectCharacter(2);

		firstPlayer->setNick("Player 1");
		secondPlayer->setNick("Player 2");

		srand(time(0));
		int turn = rand() % 2;

		std::cout << std::endl;

		if (!turn)
		{
			std::cout << firstPlayer->getNick();
		}
		else
		{
			std::cout << secondPlayer->getNick();
			std::swap(firstPlayer, secondPlayer);
		}

		std::cout << " ходит первым\n";


		Player* winner = BattleManager::makeBattle(firstPlayer, secondPlayer);
		system("cls");
		std::cout << winner->getNick() << " победил в схватке!\n";
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
				std::cout << "Номер персонажа должен быть от 1 до 3х.\n";
			}
			std::cout << "Хэй, " << playerNumber << ", выберите персонажа\n";
			std::cout << "1. Думгай\n";
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
				personPlayer = new Doomguy;
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