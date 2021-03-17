#pragma once

class DeathClaw : public Player
{
protected:
	unsigned int shieldPower;
	int shieldTime;
	int doubleDamage;
public:

	DeathClaw()
	{
		this->shieldTime = 0;
		this->setNick("������ ������");
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
			int resultDamage = defenser->setDamage(this->getDamage());
			std::cout << this->getNick() << " ����� ���� ����� �� " << defenser->getNick() << " \n";
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

			int resultDamage = defenser->setDamage(static_cast<int>(this->getDamage() * 1.2));
			std::cout << this->getNick() << " ����� �������� ���� ������� ����� � �������� ����� �� ���� ����� " << defenser->getNick() << ", ������� ��������� ����� � ���� �������� ����� �� ���������� 2� ��������� �������\n";
			this->doubleDamage = 1;
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


	bool attackDown(Player* defenser) override {
		bool attackResult = true;
		if (defenser->getBlock() != BlockType::DOWN)
		{
			int resultDamage = defenser->setDamage(static_cast<int>(this->getDamage() * 1.7));
			std::cout << this->getNick() << " ������� " << defenser->getNick() << ". ��� ����� ������ ��������� ����� �� ����. (20 ������� ����� �� 2 ����).\n";
			this->shieldPower = 20;
			this->shieldTime = 2;
			std::cout << "���-�� ����������� �����: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " �������� ����������� ������� ����� �� " << defenser->getNick() << "\n";
			attackResult = false;
		}

		defenser->setBlock(BlockType::NONE);
		return attackResult;
	}


	void attackUltimate(Player* defenser) override {
		std::cout << this->getNick() << " ������� �����-����� ����� ������. " << defenser->getNick() << " �������� ������� ����.\n";
		int resDamage = defenser->setDamage(this->getDamage() * 3);
		std::cout << "���-�� ����������� �����: " << resDamage << "HP\n";
	}

	int setDamage(int attackDamage) override
	{
		int pureDamage = attackDamage;
		if (this->shieldTime > 0)
		{
			pureDamage = (attackDamage > this->shieldPower ? attackDamage - this->shieldPower : 0);
		}
		
		this->setPureDamage(pureDamage);

		this->dailyEffect();

		return pureDamage;
	}

	int getDamage() override
	{
		if (this->doubleDamage > 0)
		{
			return this->mainDamage * 2;
		}
		return this->mainDamage;
	}
};
