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
		std::cout << this->getNick() << " обрушил мощный магический удар параллельного мира. Ѕедн€га" << defencer->getNick() << " потер€л треть своего здоровь€." << "\n";
		
		int defencerHP = defencer->getHP();
		defencer->setPureDamage(static_cast<int>(defencerHP/3));		 	
	}
};