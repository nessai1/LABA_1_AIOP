class SkillMage : public SkillContract
{
protected:
	int mana;

public:



	bool checkManaPossible(int inputMana)
	{

		if (this->mana >= inputMana)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	virtual int getCost() = 0;
};