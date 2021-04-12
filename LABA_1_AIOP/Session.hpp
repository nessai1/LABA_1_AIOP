

class Session
{
public:

	void startSession()
	{
		std::cout << "Да начнется же битва!\n";
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

		std::cout << " ходит первым\n";


		Fighter* winner = BattleManager::makeBattle(firstPlayer, secondPlayer);
		system("cls");
		std::cout << winner->getNick() << " победил в схватке!\n";
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
				std::cout << "Номер персонажа должен быть от 1 до 3х.\n";
			}
			std::cout << "Хэй, " << playerNumber << "й, выбери класс персонажа\n";
			std::cout << "1. Маг\n";
			std::cout << "2. Воин\n";
			std::cout << "3. Зверь\n";
			std::cout << "ВВОД: ";
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

		std::cout << "Теперь введи свой ник: ";
		std::cin >> inputNick;

		personPlayer->setNick(inputNick);

		std::cout << "Окей, " << personPlayer->getNick() << ", а теперь давай выберем тебе споснобности.\n";
		if (personID == 1)
		{
			std::vector<SkillContract*> availableSkills = { new SkillMageRay(), new SkillMageJinx() };
		}
		else
		{
			std::vector<SkillContract*> availableSkills = { new SkillMageRay(), new SkillMageJinx() };
		}

		return personPlayer;
	}

	void selectSkills(Fighter* selecter, std::vector<SkillContract*>& availableSkills)
	{
		std::cout << "Нужно выбрать 2 способности\n";
		int selectID;
		int selectCounter = 0;
		while (selectCounter != 2)
		{
			std::cout << "Выберите еще " << 2-selectCounter << " способностей:\n";
			for (int i = 0; i < availableSkills.size(); i++)
			{
				std::cout << i + 1 << ". " << availableSkills[i]->getName();
				if (availableSkills[i]->getCost() > 0)
				{
					std::cout << availableSkills[i]->getCost() << " маны за использование";
				}
				std::cout << '\n';
			}
			std::cout << "ВВОД: ";
			std::cin >> selectID;
			
			if (selectID > 2 || selectID < 1)
			{
				std::cout << "Нужно ввести число от 1 до 2!\n";
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