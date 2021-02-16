

class Casador : public Player
{

protected:
	unsigned int shieldPower;
	int doubleDamage;
public:

	Casador()
	{
		this->doubleDamage = 0;
		this->setNick("Doom Slayer");
		this->shieldPower = 0;
	}

	void dailyEffect() override
	{
		if (this->shieldPower > 0)
			this->shieldPower /= 2;

		if (doubleDamage > 0)
			doubleDamage--;
		else if (doubleDamage < 0)
			doubleDamage = 0;
	}

	bool attackUp(Player* defenser) override {

		bool attackResult = true;
		if (defenser->getBlock() != BlockType::UP)
		{
			int resultDamage = defenser->setDamage(this->mainDamage);
			std::cout << this->getNick() << " ������ �� " << defenser->getNick() << " ������ � ������� ����� ���������\n";
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
			int resultDamage = defenser->setDamage(static_cast<int>(this->mainDamage * 1.3));
			std::cout << this->getNick() << " �������� ���������� �� " << defenser->getNick() << ", ������� ��������� ����� � ���� �������� ����� �� ���������� 2� ��������� �������\n";
			this->doubleDamage = 2;
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
			int resultDamage = defenser->setDamage(static_cast<int>(this->mainDamage * 1.5));
			std::cout << this->getNick() << " ����������� ���, ������� ��������� ����� � ������. ����� ����� ���������� � 2 ���� ������ �����, ���� ������������ �� ����������\n";
			this->shieldPower = 32;
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
		std::cout << this->getNick() << " ������ �� ������� ���� BFG-9000 � ������ ������� ������� ��������� ����� ������� ������ (+ ��������� ����). " << defenser->getNick() << ", ������ ������ �������� �������� � ������� ������.\n";
		defenser->setPureDamage(this->getDamage() * 2);
		std::cout << "���-�� ����������� �����: " << this->getDamage() * 2 << "HP\n";
	}

	int setDamage(int attackDamage) override
	{
		int pureDamage = (attackDamage > this->shieldPower ? attackDamage - this->shieldPower : 0);

		this->setPureDamage(pureDamage);

		this->dailyEffect();

		return pureDamage;
	}

	int getDamage() override
	{
		return this->mainDamage;
	}




};