class Warrior : public Fighter
{
protected:
	int armor;
public:
	void useUltimate(Fighter* defencer)
	{
		int finalDamage = defencer->setPhysicalDamage(300);
		std::cout << this->getNick() << " ����� �������� ����. " << defencer->getNick() << "������� " << finalDamage << " ����� ����������� ����� � ������������ �� 2 ��������� ����." << "\n";
		//addBleeding(defencer);
	}

	Warrior() : Fighter(1000, 0, 120) {}
	~Warrior() {}

	
};