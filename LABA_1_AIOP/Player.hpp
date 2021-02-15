#include <string>
#include <iostream>
#include "BlockType.hpp"

// abstract class 
class Player {
public:

	virtual bool attackUp(Player* defenser) = 0;
	virtual bool blockAttack(int attackID) = 0;

	virtual bool setDamage(int attackDamage) = 0;
	virtual std::string getNick() = 0;
	virtual void setNick(std::string newNick) = 0;
	virtual bool isAlive() = 0;

	void setBlock(BlockType inputBlock)
	{
		this->playerBlock = inputBlock;
	}

protected:

	BlockType playerBlock;

	BlockType getBlockType(int id)
	{
		if (id == 1)
		{
			return BlockType::UP;
		}
		else if (id == 2)
		{
			return BlockType::MIDDLE;
		}
		else if (id == 3)
		{
			return BlockType::DOWN;
		}
		else
		{
			throw new std::logic_error("Указан нев");
		}
	}
};