class Ranger : public Player
{

protected:
	unsigned int shieldPower;
	int shieldTime;
	int doubleDamage;

	int bonusDamage;
	int bonusTime;
public:

	Ranger()
	{
		bonusTime = 0;
		bonusDamage = 0;
		this->shieldTime = 0;
		this->setNick("�������� ������� NCR");
		this->shieldPower = 0;
	}

	void dailyEffect() override
	{
		if (this->shieldTime > 0)
		{
			this->shieldTime--;
		}

		if (doubleDamage > 0)
		{
			doubleDamage--;
		}

	}

	bool attackUp(Player* defenser) override {

		bool attackResult = true;
		if (defenser->getBlock() != BlockType::UP)
		{
			int resultDamage = defenser->setDamage(static_cast<int>(this->getDamage() * 0.5));
			std::cout << this->getNick() << " ������ ���� ��������� '������� ��������' � ��������� � " << defenser->getNick() << " \n";
			std::cout << "\n���-�� ����������� �����: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " �������� ����������� ������� ����� �� " << defenser->getNick() << "\n";
			attackResult = false;
		}

		defenser->setBlock(BlockType::NONE);
		return attackResult;
	}

	bool attackMiddle(Player* defenser) override {
		bool attackResult = true;
		if (defenser->getBlock() != BlockType::MIDDLE)
		{

			int resultDamage = defenser->setDamage(static_cast<int>(this->getDamage() * 1.5));
			std::cout << this->getNick() << " ��������� �� ����� ������, ���������������� ����������� ��������, ��������� ������������� �������, � " << defenser->getNick() << ", ������� ��������� ����� � ���� ��������������� ����� � ���� 30 ����� �� 3 ����\n";
			this->doubleDamage = 3;
			this->bonusDamage = 30;
			std::cout << "\n���-�� ����������� �����: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " �������� ����������� ������� ����� �� " << defenser->getNick() << "\n";
			attackResult = false;
		}
		return attackResult;
	}


	bool attackDown(Player* defenser) override {
		bool attackResult = true;
		if (defenser->getBlock() != BlockType::DOWN)
		{
			int resultDamage = defenser->setDamage(static_cast<int>(this->getDamage() * 1.7));
			std::cout << this->getNick() << " ����������� �����-����� �� 2 ����. ��-�� ��������� ���� " << defenser->getNick() << " ������� ������ � 2 ���� ������ �����.\ns";
			this->shieldPower = 20;
			this->shieldTime = 2;
			std::cout << "���-�� ����������� �����: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " �������� ����������� ������� ����� �� " << defenser->getNick() << "\n";
			attackResult = false;
		}
		return attackResult;
	}


	void attackUltimate(Player* defenser) override {
		std::cout << this->getNick() << " ��������� ������ ������� ���������� �������� ����� ������ " << defenser->getNick() << " ���� � �����, ������ ������� ���� ������ ������.";
		defenser->setPureDamage(this->getDamage() * 2);
		std::cout << "���-�� ����������� �����: " << this->getDamage() * 2 << "HP\n";
	}

	int setDamage(int attackDamage) override
	{
		int pureDamage = attackDamage;
		if (this->shieldTime > 0)
		{
			pureDamage = pureDamage / 2;
		}

		this->setPureDamage(pureDamage);

		this->dailyEffect();

		return pureDamage;
	}

	int getDamage() override
	{

		if (bonusTime > 0)
		{
			bonusTime--;
			return this->mainDamage + bonusDamage;
		}
		return this->mainDamage;
	}
};