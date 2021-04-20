class SkillWarriorPush : public SkillWarrior
{
protected:
	int skillDamage;

public:

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillWarriorPush(int skillDamage = 160, std::string ownerNick = "UNNAMED") : SkillWarrior(ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "Толкнуть противника щитом (Physical: 70)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (this->getOwnerNick() + " толкнул противника своим щитом (Physical: 70)");
	}

};