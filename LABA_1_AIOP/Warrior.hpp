class Warrior : public Fighter
{
protected:
	int armor;
public:

	Warrior(int hp = 200) : Fighter(hp)
	{
		this->armor = 0;
	}

	
};