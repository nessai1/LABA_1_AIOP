class SkillMageTornado : public SkillMage
{
protected:
	int skillDamage;

public:

	DamageType getDamageType()
	{
		return DamageType::PHYSICAL;
	}

	int getDamage()
	{
		return this->skillDamage;
	}

	SkillMageTornado(int skillDamage = 240, int skillCost = 130, std::string ownerNick = "UNNAMED") : SkillMage(skillCost, ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "Вызвать торнадо (Phys. damage: 240)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " попал в торнадо (Phys. damage: 240)");
	}


};