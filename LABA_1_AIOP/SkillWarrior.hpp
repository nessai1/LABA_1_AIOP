class SkillWarrior : public Skill
{
public:

	DamageType getDamageType()
	{
		return DamageType::PHYSICAL;
	}

	SkillWarrior(std::string ownerNick = "UNNAMED") : Skill(0, ownerNick) {}

};