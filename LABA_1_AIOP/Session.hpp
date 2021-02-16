

class Session
{
public:

	void startSession()
	{
		std::cout << "����� ���������� �� ����!\n";
		Player* firstPlayer = selectCharacter(1);
		Player* secondPlayer = selectCharacter(2);

		firstPlayer->setNick("����� 1");
		secondPlayer->setNick("����� 2");

		srand(time(0));
		int turn = rand() % 2;

		std::cout << std::endl;

		if (!turn)
		{
			std::cout << firstPlayer->getNick() << " ������������� ���� ������\n";
		}
		else
		{
			std::cout << secondPlayer->getNick() << " ������������� ���� ������\n";
			std::swap(firstPlayer, secondPlayer);
		}

		Player* winner = BattleManager::makeBattle(firstPlayer, secondPlayer);
		system("cls");
		std::cout << winner->getNick() << " ����� � ���� ����������� ����� � ���� �����������!!\n";
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
				std::cout << "�� ������ ������� ������ �� ���� ����������. ������� ����� �� 1 �� 3�.\n";
			}
			std::cout << "����� " << playerNumber << ", �������� ������ ���������\n";
			std::cout << "1. ����� ����\n";
			std::cout << "2. ������ ������\n";
			std::cout << "3. �������� ���\n";
			std::cout << "����: ";
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