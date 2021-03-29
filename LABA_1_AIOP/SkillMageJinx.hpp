
class SkillMageJinx : public SkillMage, public SkillContract
{
protected:
	int damage;
public:

	SkillMageJinx(int inputDamage = 40, int inputCost = 20) : damage(inputDamage), SkillMage(inputCost)
	{}

	int getDamage()
	{
		return this->damage;
	}

	void manipulatePlayer(Fighter* manipulatedPlayer)
	{
		
		std::cout << manipulatedPlayer->getNick() << " был проклят зельем разрушения и получил 40"
	}

	

};