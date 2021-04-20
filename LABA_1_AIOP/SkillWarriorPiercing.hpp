class SkillWarriorPiercing : public SkillWarrior
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

	SkillWarriorPiercing(int skillDamage = 70, std::string ownerNick = "UNNAMED") : SkillWarrior(ownerNick), skillDamage(skillDamage) {}

	std::string getName()
	{
		std::string name = "�������� ���������� ����� (Purge: 70)";
		return name;
	}

	std::string skillMessage(std::string defencerNick)
	{
		return (defencerNick + " ������� �������� ����� (Purge: 70)");
	}

};