
class SideEffectRegeneration : public SideEffect
{
protected:
	int bonusHP;

	void manipulateFighter(Fighter* manipulatedFighter)
	{
		manipulatedFighter->addHP(this->bonusHP);
		std::cout << manipulatedFighter->getNick() << " ����������� ���� �������� �� " << this->bonusHP << " ����� � ������� ����������� (HP: " << manipulatedFighter->getHP() << ")\n";
	}

public:
	SideEffectRegeneration(int bonusHP = 100, int inputMoves = 0) : SideEffect(inputMoves), bonusHP(bonusHP) {}
	~SideEffectRegeneration() {}
};