class Magician : public Fighter
{
public:
	Magician() : Fighter(800, 100, 50) {}

	void useUltimate(Fighter* defencer)
	{
		std::cout << this->getNick() << " ������� ������ ���������� ���� ������������� ����. �������" << defencer->getNick() << " ������� ����� ������ ��������." << "\n";
		
		int defencerHP = defencer->getHP();
		defencer->setPureDamage(static_cast<int>(defencerHP/3));		 	
	}
};