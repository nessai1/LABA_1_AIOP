class SkillMageRay : public SkillMage
{
protected:
	int skillDamage;

public:

	SkillMageRay(int skillDamage = 40, int skillCost = 30) : SkillMage(skillCost), skillDamage(skillDamage) {}

	std::string getName()
	{
		return "Пронзить противника лазерным лучом";
	}

	void manipulatePlayer(Fighter* manipulatedPlayer)
	{
		int finalDamage = manipulatedPlayer->setMagicDamage(this->skillDamage);
		std::cout << manipulatedPlayer->getNick() << " получил удар лучем и получил " << finalDamage << " очков урона\n";
	}
};