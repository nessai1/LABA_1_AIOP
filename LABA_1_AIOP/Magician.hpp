class Magician : public Fighter
{
protected:
	int mana;

public:

	void updateFighter()
	{
		this->mana += 30;
		std::cout << this->getNick() << ": MANA = " << this->getMana() << '\n';
	}

	Magician() : Fighter(800, 200, 0), mana(200) {}

	void useUltimate(Fighter* defencer)
	{
		std::cout << this->getNick() << " ������� ������ ���������� ���� ������������� ����. �������" << defencer->getNick() << " ������� ����� ������ ��������." << "\n";
		
		int defencerHP = defencer->getHP();
		defencer->setPureDamage(static_cast<int>(defencerHP/3));		 	
	}
};