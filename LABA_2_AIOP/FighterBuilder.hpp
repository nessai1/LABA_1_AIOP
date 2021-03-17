class FighterBuilder
{
public:
	Fighter* selectFighter()
	{
		return new Warrior();
	}
};