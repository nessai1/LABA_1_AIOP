class SkillWarriorSword : public SkillWarrior
{
protected:
	int skillDamage;

public:

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillWarriorSword(int skillDamage = 160, std::string ownerNick = "UNNAMED") : SkillWarrior(ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "Нанести удар мечом (Physical: 160)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (this->getOwnerNick() + " нанес удар своим мечом по " + defencerNick + " (Physical: 160)");
	}

};