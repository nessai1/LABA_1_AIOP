
class SideEffect
{
protected:
	int turns;


	virtual void manipulateFighter(Fighter* manipulatedFighter) = 0;
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
	
	bool makeSideEffect(Fighter* inputFighter)
	{
		
		if (this->makeTurn())
		{
			this->manipulateFighter(inputFighter);
			return true;
		}
		else
		{
			return false;
		}

	}
};