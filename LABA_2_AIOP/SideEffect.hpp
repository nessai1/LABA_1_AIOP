
class SideEffect
{
protected:
	int turns;

public:

	SideEffect(int inputTurns)
	{
		this->turns = inputTurns;
	}

	int getTurn()
	{
		return this->turns;
	}

	bool setTurn(int inputTurn)
	{

		if (inputTurn >= 0)
		{
			this->turns = inputTurn;
			return true;
		}
		else
		{
			return false;
		}

	}

	bool makeTurn()
	{
		return setTurn(this->getTurn() - 1);
	}

	virtual bool makeSideEffect(Fighter* inputFighter) = 0;
};