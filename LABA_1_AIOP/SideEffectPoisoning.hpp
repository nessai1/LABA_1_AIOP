
class SideEffectPoisoning : public SideEffect
{
protected:

	int poisoningDamage;

	void manipulateFighter(Fighter* manipulatedFighter)
	{
		std::cout << "�� ��������� � ���������� ������� � ��������������. ���� �������� ��������� �� << " << this->poisoningDamage <<  "HP (��� "<< this->getTurn() << " �����)" << std::endl;
		manipulatedFighter->setPureDamage(this->poisoningDamage);
	}



public:

	SideEffectPoisoning(int inputDamage = 25, int inputTurns = 1) : SideEffect(inputTurns), poisoningDamage(inputDamage)
	{}

};