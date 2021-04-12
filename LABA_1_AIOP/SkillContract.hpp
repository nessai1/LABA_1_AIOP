//class Fighter;
class SkillContract
{
protected: 
    int cost;
public:

    SkillContract(int cost) : cost(cost) {}

    int getCost()
    {
        return this->cost;
    }

    virtual std::string getName() = 0;
    virtual void manipulatePlayer(Fighter* manipulatedPlayer) = 0;
};