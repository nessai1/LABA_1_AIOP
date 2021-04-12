
class SideEffectRegeneration : public SideEffect
{
protected:
	int bonusHP;

	void manipulateFighter(Fighter* manipulatedFighter)
	{
		manipulatedFighter->addHP(this->bonusHP);
		std::cout << manipulatedFighter->getNick() << " восстановил свое здоровье на " << this->bonusHP << " очков с помощью регенерации (HP: " << manipulatedFighter->getHP() << ")\n";
	}

public:
	SideEffectRegeneration(int bonusHP = 100, int inputMoves = 0) : SideEffect(inputMoves), bonusHP(bonusHP) {}
	~SideEffectRegeneration() {}
};