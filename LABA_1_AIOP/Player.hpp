#include <string>
#include <iostream>
#include "BlockType.hpp"

// abstract class 
class Player {

protected:
	int hp;
	int mainDamage;
	BlockType playerBlock;
	std::string nick;

public:

	Player(int hp = 300)
		: hp(hp), nick("Player"), mainDamage(40), playerBlock(BlockType::NONE) {}


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

	void setPureDamage(int attackDamage)
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

	/* virtal block */

	// возвращает полученный дамаг
	virtual int setDamage(int attackDamage) = 0;

	// возвращает конечный дамаг пользователя
	virtual int getDamage() = 0;

	virtual void dailyEffect() = 0;

	virtual void attackUltimate(Player* defenser) = 0;
	virtual bool attackUp(Player* defenser) = 0;
	
	/* /virtual block */


};
