

class Fighter
{
protected:
    std::string nickName;
    int hp;
    int blockID;

    // armor
    int magicArmor;
    int physicalArmor;
    float dodge; // процент уклонения от физ. урона (от 0.0 до 1.0)

    bool magicBlock;

    std::vector<SkillContract*> skills;

public:

    Fighter(int inputHP) : hp(inputHP), magicArmor(0), physicalArmor(0), magicBlock(false)
    {}
   
    

    virtual int setPhysicalDamage(int inputDamage)
    {
        int nonDodgeDamage = inputDamage - static_cast<int>(inputDamage * this->dodge);
        this->setPureDamage(nonDodgeDamage);
        return nonDodgeDamage;
    }

    virtual int setMagicDamage(int inputDamage)
    {
        if (!this->magicBlock)
        {
            this->setPureDamage(inputDamage);
            return inputDamage;
        }
        else
        {
            return 0;
        }

    }

    /**
     * give player pure damage without effects
     * @param inputDamage
     * @return
     */
    void setPureDamage(int inputDamage)
    {
       this->hp -= inputDamage;
    }

    bool isAlive()
    {
        return this->hp > 0;
    }

    void setDodge(float inputDodge)
    {
        if (inputDodge <= 1 && 0 <= inputDodge)
        {
            this->dodge = inputDodge;
        }
        else
        {
            throw std::invalid_argument("input argument 'dodge' must be float value in [0;1] position");
        }
    }

    /**
     * set player HP
     * @param inputHP
     */
    void setHP(int inputHP)
    {
        this->hp = inputHP;
    }

    int getHP()
    {
        return this->hp;
    }

    /**
     * get player nickname
     * @return
     */
    std::string getNick()
    {
        return this->nickName;
    }

    
    void setBlockID(int inputBlockID)
    {
        this->blockID = inputBlockID;
    }

    int getBlockID()
    {
        return this->blockID;
    }
};

