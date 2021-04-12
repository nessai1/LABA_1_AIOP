class Warrior : public Fighter
{
protected:
	int armor;
public:
	void useUltimate(Fighter* defencer)
	{
		int finalDamage = defencer->setPhysicalDamage(300);
		std::cout << this->getNick() << " нанес кровавый удар. " << defencer->getNick() << "Получил " << finalDamage << " очков физического урона и кровотечение на 2 следующих хода." << "\n";
		//addBleeding(defencer);
	}

	Warrior() : Fighter(1000, 0, 120) {}
	~Warrior() {}

	
};