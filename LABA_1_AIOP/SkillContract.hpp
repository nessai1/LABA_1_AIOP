class SkillContract
{
public:
    virtual int getDamage() = 0;
    virtual std::string getMessage() = 0;
    virtual void manipulatePlayer(Fighter* manipulatedPlayer) = 0;
protected:
    virtual SideEffect* getSideEffect() = 0;
};