#include "Player.hpp"

class Doomguy : public Player
{

protected:
	unsigned int shieldPower;

public:

	Doomguy()
	{
		this->setNick("Doom Slayer");
		this->shieldPower = 0;
	}

	void dailyEffect() override
	{
		if (this->shieldPower > 0)
			this->shieldPower /= 2;
	}

	bool attackUp(Player* defenser) override {
		
		bool attackResult = true;
		if (defenser->getBlock() != BlockType::UP)
		{
			defenser->setDamage(this->mainDamage);
			std::cout << this->getNick() << " ������ �� " << defenser->getNick() << " ������ � ������� ����� ���������\n";
			
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
		std::cout << this->getNick() << " ������ �� ������� ���� BFG-9000 � ������ ������� ������� ��������� ����� ������� ������ (+ ��������� ����). ������ ������ �������� �������� � ������� ������.\n";
		defenser->setPureDamage(this->getDamage()*2);
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