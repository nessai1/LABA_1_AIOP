
class SideEffectBleeding : public SideEffect
{
protected:

	int bloodLoose;

	void manipulateFighter(Fighter* manipulatedFighter)
	{
		manipulatedFighter->setPureDamage(bloodLoose);
		std::cout << manipulatedFighter->getNick() << " теряет " << this->bloodLoose << " единиц здоровья от кровотечения (HP: " << manipulatedFighter->getHP() << ")\n";
	}

public:
	SideEffectBleeding(int bloodLoose = 25, int inputMoves = 0) : SideEffect(inputMoves), bloodLoose(bloodLoose) {}
	~SideEffectBleeding() {}
};