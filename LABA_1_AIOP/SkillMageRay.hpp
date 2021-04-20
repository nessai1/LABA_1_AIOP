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
		return "Нанести лучевой магический удар (MAGIC: " + this->skillDamage + ')';
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " поймал луч и получил хорошенькую порцию магического урона");
	}

};