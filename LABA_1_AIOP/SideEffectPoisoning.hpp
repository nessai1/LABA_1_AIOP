
class SideEffectPoisoning : public SideEffect
{
protected:

	int poisoningDamage;

	void manipulateFighter(Fighter* manipulatedFighter)
	{
		std::cout << "¬ы отравлены и чувствуете тошноту и головокружение. ¬аше здоровье уменьшено на << " << this->poisoningDamage <<  "HP (еще "<< this->getTurn() << " ходов)" << std::endl;
		manipulatedFighter->setPureDamage(this->poisoningDamage);
	}



public:

	SideEffectPoisoning(int inputDamage = 25, int inputTurns = 1) : SideEffect(inputTurns), poisoningDamage(inputDamage)
	{}

};