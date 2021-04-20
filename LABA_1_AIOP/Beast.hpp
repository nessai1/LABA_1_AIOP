class Beast : public Fighter
{
public:
	Beast() : Fighter(1300, 0, 0) 
	{
		this->setDodge(0.3);
	}

	void useUltimate(Fighter* defencer)
	{
		if (this->getDodge() < 0.9)
		{
			std::cout << "Обрел новых сил, получив 5% к уклонению от физических атак\n";
			this->setDodge(this->getDodge() + 0.05);
		}
		
		int finalDamage = static_cast<int>(defencer->getHP() / 2);
		std::cout << this->getNick() << " нанес кровавый удар. " << defencer->getNick() << "Получил чистый урон, равный половине здоровья нападавшего (HP:" << finalDamage << ")\n";
		defencer->setPureDamage(finalDamage);
	}
};