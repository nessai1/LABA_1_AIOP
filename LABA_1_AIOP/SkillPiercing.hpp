class SkillPiercing : public Skill
{
protected:
	int skillDamage;

public:

	SkillPiercing(std::string ownerNick = "UNNAMED") : Skill(0, ownerNick)
	{
		this->skillDamage = 45;
	}

	DamageType getDamageType()
	{
		return DamageType::PURGE;
	}

	int getDamage()
	{
		return this->skillDamage;
	}

	std::string getName()
	{
		std::string name = "������� ������������� ���� ������ ������ (Purge damage: 45)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return defencerNick + " ������ ������������� ���� (Purge. damage: 45)";
	}


};