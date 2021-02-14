#include <string>
#include <iostream>

class Player {
public:
	virtual bool attackUp(Player* defenser) = 0;
	/*virtual bool getBlockUp() = 0;
	virtual void setBlockUp() = 0;*/

	virtual bool setDamage(int attackDamage) = 0;
	virtual std::string getNick() = 0;
	virtual void setNick(std::string newNick) = 0;
	virtual bool isAlive() = 0;
};