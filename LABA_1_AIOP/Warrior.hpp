class Warrior : public Fighter
{
public:
	Warrior() : Fighter(1000, 0, 90) {}

	void useUltimate(Fighter* defencer)
	{
		if (defencer->getHP() > this->getHP())
		{
			std::cout << "Бог войны благоволит вам! Так как ваше здоровье меньше здоровья противника, вы забрали физический дух своего противника взамен своего.\n(Ваше здоровье поменялось местами со здоровьем противника)\n";
			int enemyHP = defencer->getHP();
			
			defencer->setHP(this->getHP());
			this->setHP(enemyHP);
		}	
		else
		{
			std::cout << "Благодаря силе вашего физического духа вы забираете треть здоровья своего противника.\n";
			int enemyHP = static_cast<int>(defencer->getHP() / 3);
		
			defencer->setPureDamage(enemyHP);
			this->setHP(this->getHP() + enemyHP);
		}
	}
};