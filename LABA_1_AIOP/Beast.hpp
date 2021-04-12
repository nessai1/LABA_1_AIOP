class Beast : public Fighter
{
protected:
	int ultimateDamage;
	SideEffectBleeding* ultimateBleeding;

	void addBleeding(Fighter* inputFighter)
	{
		if (ultimateBleeding->getTurn() == 0)
		{
			this->ultimateBleeding->setTurn(2);
			inputFighter->addSideEffect(this->ultimateBleeding);
		}
		else
		{
			ultimateBleeding->setTurn(2);
		}
	}
public:
	Beast() : ultimateDamage(300), Fighter(1300, 0, 0) 
	{
		this->ultimateBleeding = new SideEffectBleeding();
	}

	void useUltimate(Fighter* defencer)
	{
		int finalDamage = defencer->setPhysicalDamage(300);
		std::cout << this->getNick() << " ����� �������� ����. " << defencer->getNick() << "������� " << finalDamage << " ����� ����������� ����� � ������������ �� 2 ��������� ����." << "\n";
		addBleeding(defencer);
	}
};