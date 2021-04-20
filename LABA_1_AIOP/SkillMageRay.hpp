class SkillMageRay : public SkillMage
{
protected:
	int skillDamage;

public:

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillMageRay(int skillDamage = 160, int skillCost = 100, std::string ownerNick = "UNNAMED") : SkillMage(skillCost, ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "Ќанести лучевой магический удар (MAGIC: 160)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " поймал хорошенький магический луч и получил магический урон.");
	}

};