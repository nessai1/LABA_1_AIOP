class SkillContract
{
public:
    virtual int getDamage() = 0;
    virtual void manipulatePlayer(Fighter* manipulatedPlayer) = 0;
};