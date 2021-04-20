class SkillMageJinx : public SkillMage
{
protected:
	int skillDamage;

public:

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillMageJinx(int skillDamage = 100, int skillCost = 80, std::string ownerNick = "UNNAMED") : SkillMage(skillCost, ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		return "Наслать проклятье на противника (MAGIC: " + this->skillDamage + ')';
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " был проклят, получив от этого магический урон");
	}

	
};