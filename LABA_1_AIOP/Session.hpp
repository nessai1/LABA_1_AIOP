#include "Player.h"
#include "Doomguy.hpp"

class Session
{
public:

	void startSession()
	{

	}

protected:

	Player* selectCharacter()
	{
		return new Doomguy;
	}

};