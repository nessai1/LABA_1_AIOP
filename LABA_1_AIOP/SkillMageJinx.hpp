class SkillMageJinx : public SkillMage
{
protected:
	int skillDamage;

public:

	SkillMageJinx(int skillDamage = 100, int skillCost = 80) : SkillMage(skillCost), skillDamage(skillDamage) {}

	std::string getName()
	{
		return "������� ��������� �� ���������� (MAGIC: " + this->skillDamage + ')';
	}

	void manipulatePlayer(Fighter* manipulatedPlayer)
	{
		int finalDamage = manipulatedPlayer->setMagicDamage(this->skillDamage);
		std::cout << manipulatedPlayer->getNick() << " ��� ������� � ������� " << finalDamage << " ����� �����\n";
	}
};