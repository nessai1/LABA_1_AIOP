class SkillMageFall : public SkillMage
{
protected:
	int skillDamage;

public:

	DamageType getDamageType()
	{
		return DamageType::PURGE;
	}

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillMageFall(int skillDamage = 200, int skillCost = 170, std::string ownerNick = "UNNAMED") : SkillMage(skillCost, ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "ѕровалить физический дух противника сквозь землю (Purge. damage: 200)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " на врем€ потер€л свой физический дух,  (Purge. damage: 200)");
	}


};