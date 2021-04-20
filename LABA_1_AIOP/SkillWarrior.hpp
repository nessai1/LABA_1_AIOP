class SkillWarrior : public Skill
{
public:

	virtual DamageType getDamageType()
	{
		return DamageType::PHYSICAL;
	}

	SkillWarrior(std::string ownerNick = "UNNAMED") : Skill(0, ownerNick) {}

};