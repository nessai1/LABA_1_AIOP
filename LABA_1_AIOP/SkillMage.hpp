class SkillMage : public Skill
{

public:

	DamageType getDamageType()
	{
		return DamageType::MAGIC;
	}

	SkillMage(int inputCost, std::string ownerNick = "UNNAMED") : Skill(inputCost, ownerNick) {}
	~SkillMage() {}


};