#include <string>
#include <iostream>
#include "BlockType.hpp"

// abstract class 
class Player {

protected:
	int hp;
	BlockType playerBlock;
	std::string nick;

public:

	Player(int hp = 300)
		: hp(hp), nick("Player") {}

	void setNick(std::string inputNick)
	{
		this->nick = inputNick;
	}

	void setBlock(BlockType inputBlock)
	{
		this->playerBlock = inputBlock;
	}

	BlockType getBlock()
	{
		return this->playerBlock;
	}

	void setHP(int inputHP)
	{
		this->hp = inputHP;
	}

	bool isAlive()
	{
		return this->getHP() > 0;
	}

	int getHP()
	{
		return this->hp;
	}

	bool setDamage(int attackDamage)
	{
		this->setHP(this->getHP() - attackDamage);
	}

	void setNick(std::string inputNick)
	{
		this->nick = inputNick;
	}

	std::string getNick()
	{
		return this->nick;
	}

	virtual void attackUltimate(Player* defenser) = 0;
	virtual bool attackUp(Player* defenser) = 0;
	



};
