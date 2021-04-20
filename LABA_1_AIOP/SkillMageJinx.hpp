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
		std::string name = "Наслать проклятье на противника (MAGIC: 100)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " был проклят, получив от этого магический урон");
	}

	
};