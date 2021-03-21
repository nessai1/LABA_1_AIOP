class SkillWarrior : public SkillContract
{
protected:
	int forcePoints;

public:

	bool checkForcePossible(int inputForcePoints)
	{

		if (forcePoints >= inputForcePoints)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	
};