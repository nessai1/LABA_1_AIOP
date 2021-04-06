class SkillContract
{
protected: 
    int cost;
public:

    int getCost()
    {
        return this->cost;
    }

    virtual std::string getName() = 0;
    virtual int getDamage() = 0;
    virtual void manipulatePlayer(Fighter* manipulatedPlayer) = 0;
};