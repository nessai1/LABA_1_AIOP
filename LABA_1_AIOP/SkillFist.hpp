class SkillFist : public Skill
{
protected:
	int skillDamage;

public:

	SkillFist(std::string ownerNick = "UNNAMED") : Skill(0, ownerNick) 
	{
		this->skillDamage = 90;
	}

	DamageType getDamageType()
	{
		return DamageType::PHYSICAL;
	}

	int getDamage()
	{
		return this->skillDamage;
	}

	std::string getName()
	{
		std::string name = "ƒать пощечину игроку (Phys. damage: 90)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return defencerNick + " получил пощечину. (Phys. damage: 90)";
	}


};