class SkillMage : public Skill
{

public:

	virtual DamageType getDamageType()
	{
		return DamageType::MAGIC;
	}

	SkillMage(int inputCost, std::string ownerNick = "UNNAMED") : Skill(inputCost, ownerNick) {}
	~SkillMage() {}


};