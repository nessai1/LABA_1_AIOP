

class Session
{
public:

	void startSession()
	{
		std::cout << "�� �������� �� �����!\n";
		Fighter* firstPlayer = selectCharacter(1);
		Fighter* secondPlayer = selectCharacter(2);


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

		std::cout << " ����� ������\n";


		Fighter* winner = BattleManager::makeBattle(firstPlayer, secondPlayer);
		system("cls");
		std::cout << winner->getNick() << " ������� � �������!\n";
	}

protected:

	Fighter* selectCharacter(int playerNumber)
	{
		int personID;
		bool wrongInput = false;
		Fighter* personPlayer;
		while (true)
		{
			if (wrongInput)
			{
				wrongInput = false;
				std::cout << "����� ��������� ������ ���� �� 1 �� 3�.\n";
			}
			std::cout << "���, " << playerNumber << "�, ������ ����� ���������\n";
			std::cout << "1. ��� (800 HP, 200 ����� ���� �� ������, ������ �� ���. ����� = 70 )\n";
			std::cout << "2. ���� (1000 HP, 90 ����� �����)\n";
			std::cout << "3. ����� (1300 HP, ��������� ������� ��������� = 30%)\n";
			std::cout << "����: ";
			std::cin >> personID;
			switch (personID)
			{
			case 1:
				personPlayer = new Magician();
				break;
			case 2:
				personPlayer = new Warrior();
				break;
			case 3:
				personPlayer = new Beast();
				break;
			default:
				wrongInput = true;
				continue;
			}

			break;
		}
		
		std::string inputNick;

		std::cout << "������ ����� ���� ���: ";
		std::cin >> inputNick;

		personPlayer->setNick(inputNick);

		std::cout << "����, " << personPlayer->getNick() << ", � ������ ����� ������� ���� ������������.\n";
		std::vector<Skill*> availableSkills;
		
		if (personID == 1)
		{
			availableSkills = {new SkillFist(), new SkillPiercing(), new SkillMageFall(), new SkillMageTornado(), new SkillMageRay(), new SkillMageJinx() };
		}
		else
		{
			availableSkills = { new SkillMageRay(), new SkillMageJinx() };
		}

		

		this->selectSkills(personPlayer, availableSkills);
		return personPlayer;
	}

	void selectSkills(Fighter* selecter, std::vector<Skill*>& availableSkills)
	{
		std::cout << "����� ������� 5 ������������\n";
		int selectID;
		int selectCounter = 0;
		while (selectCounter != 5)
		{
			std::cout << "�������� ��� " << 5-selectCounter << " ������������:\n";
			for (int i = 0; i < availableSkills.size(); i++)
			{
				std::cout << i + 1 << ". " << availableSkills[i]->getName();
				if (availableSkills[i]->getCost() > 0)
				{
					std::cout << ' ' << availableSkills[i]->getCost() << " ���� �� �������������";
				}
				std::cout << '\n';
			}
			std::cout << "����: ";
			std::cin >> selectID;
			
			if (selectID > 5 || selectID < 1)
			{
				std::cout << "����� ������ ����� �� 1 �� 5!\n";
				continue;
			}
			else
			{
				selecter->addSkill(availableSkills[selectID - 1]);
				availableSkills.erase(availableSkills.begin() + (selectID - 1));
				selectCounter++;
			}
		}
	}

};