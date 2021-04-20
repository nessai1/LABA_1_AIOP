
class Skill
{
protected: 
    int cost;
    std::string ownerNick;
public:
    
    std::string getOwnerNick()
    {
        return this->ownerNick;
    }

    void setOwnerNick(std::string inputNick)
    {
        this->ownerNick = inputNick;
    }

    virtual int getDamage() = 0;
    
    virtual DamageType getDamageType()
    {
        return DamageType::PHYSICAL;
    }

    Skill(int cost = 0, std::string ownerNick = "UNNAMED") : ownerNick(ownerNick), cost(cost) {}
    ~Skill() {}
    int getCost()
    {
        return this->cost;
    }

    virtual std::string skillMessage(std::string defencerNick) = 0;
    virtual std::string getName() = 0;
};