

class Fighter
{
private:
    std::string nickName;
    std::string fighterName;
    int hp;
    int blockID;

public:

    Fighter(int inputHP) : hp(inputHP)
    {}
   
    virtual bool setDamage(int inputDamage) = 0;

    /**
     * give player pure damage without effects
     * @param inputDamage
     * @return
     */
    bool setPureDamage(int inputDamage)
    {
        if (this->hp >= inputDamage)
        {
            this->hp -= inputDamage;
            return true;
        }
        else
        {
            return false;
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

    /**
     * get player nickname
     * @return
     */
    std::string getNick()
    {
        return this->nickName;
    }

    /**
     * get fighter name
     * @return
     */
    std::string getPersonName()
    {
        return this->fighterName;
    }


};

