class Magician : public Fighter
{
public:
	Magician() : Fighter(800, 100, 50) {}

	void useUltimate(Fighter* defencer)
	{
		std::cout << this->getNick() << " обрушил мощный магический удар параллельного мира. Ѕедн€га" << defencer->getNick() << " потер€л треть своего здоровь€." << "\n";
		
		int defencerHP = defencer->getHP();
		defencer->setPureDamage(static_cast<int>(defencerHP/3));		 	
	}
};