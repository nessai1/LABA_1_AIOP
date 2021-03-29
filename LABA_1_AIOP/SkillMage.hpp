class SkillMage
{
protected:
	int cost;

public:

	SkillMage(int inputCost = 0) : cost(inputCost)
	{}

	bool checkManaPossible(int inputMana)
	{

		if (this->cost <= inputMana)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	virtual int getCost() 
	{
		return this->cost;
	}
};