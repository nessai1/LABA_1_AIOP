class Warrior : public Fighter
{
public:
	Warrior() : Fighter(1000, 0, 90) {}

	void useUltimate(Fighter* defencer)
	{
		if (defencer->getHP() > this->getHP())
		{
			std::cout << "��� ����� ���������� ���! ��� ��� ���� �������� ������ �������� ����������, �� ������� ���������� ��� ������ ���������� ������ ������.\n(���� �������� ���������� ������� �� ��������� ����������)\n";
			int enemyHP = defencer->getHP();
			
			defencer->setHP(this->getHP());
			this->setHP(enemyHP);
		}	
		else
		{
			std::cout << "��������� ���� ������ ����������� ���� �� ��������� ����� �������� ������ ����������.\n";
			int enemyHP = static_cast<int>(defencer->getHP() / 3);
		
			defencer->setPureDamage(enemyHP);
			this->setHP(this->getHP() + enemyHP);
		}
	}
};