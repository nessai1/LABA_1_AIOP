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
		this->setNick(" оготь смерти");
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
			std::cout << this->getNick() << " нанес удар лапой по " << defenser->getNick() << " \n";
			std::cout << "\n ол-во нанесенного урона: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " проводит безуспешную верхнюю атаку по " << defenser->getNick() << "\n";
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
			std::cout << this->getNick() << " нанес свирепый удар получив бонус к двойному урону на один раунд " << defenser->getNick() << ", получив временный бонус в виде двойного урона на прот€жении 2х следующих раундов\n";
			this->doubleDamage = 1;
			std::cout << "\n ол-во нанесенного урона: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " проводит безуспешную верхнюю атаку по " << defenser->getNick() << "\n";
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
			std::cout << this->getNick() << " пронзил " << defenser->getNick() << ". ≈го кровь станет временным щитом от атак. (20 поинтов брони на 2 хода).\n";
			this->shieldPower = 20;
			this->shieldTime = 2;
			std::cout << " ол-во нанесенного урона: " << resultDamage << "HP\n";
		}
		else
		{
			std::cout << this->getNick() << " проводит безуспешную верхнюю атаку по " << defenser->getNick() << "\n";
			attackResult = false;
		}

		defenser->setBlock(BlockType::NONE);
		return attackResult;
	}


	void attackUltimate(Player* defenser) override {
		std::cout << this->getNick() << " призвал альфа-самца когт€ смерти. " << defenser->getNick() << " получает тройной урон.\n";
		int resDamage = defenser->setDamage(this->getDamage() * 3);
		std::cout << " ол-во нанесенного урона: " << resDamage << "HP\n";
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
