#include "Player.h";

class Doomguy : public Player
{
public:

	Doomguy() : hp(300), mainDamage(30), nick("THE DOOM SLAYER"), blockUp(false)
	{}

	bool attackUp(Player* defenser) override {
		
		if (defenser->getBlockUp())
		{
			std::cout << this->getNick() << " проводит безуспешную верхнюю атаку по " << defenser->getNick() << "\n";
			return false;
		}
		else
		{
			defenser->setDamage(this->mainDamage);
			std::cout << this->getNick() << " сделал из " << defenser->getNick() << " решето с помощью своей двуствлки\n";	
		}
		

		return true;
	}

	bool isAlive() override {
		return this->hp > 0;
	}

	std::string getNick() override {
		return this->nick;
	}

	void setNick(std::string newNick) override {
		this->nick = newNick;
	}

	bool setDamage(int attackDamage) override {
		this->hp -= attackDamage;
		return true;
	}


protected:
	bool blockUp;
	int mainDamage;
	int hp;
	std::string nick;
};