//
// Created by daniel on 06.03.2021.
//

#ifndef LABA_2_AIOP_FIGHTER_HPP
#define LABA_2_AIOP_FIGHTER_HPP

class Fighter
{
private:
    std::string nickName;
    std::string fighterName;
    int hp;
    int blockID;

public:

    int 



    /**
     * give player damage with effects (use setPureDamage after manipulations)
     * @param inputDamage
     * @return
     */
    virtual bool setDamage(int inputDamage) = 0;

    /**
     * give player pure damage without effects
     * @param inputDamage
     * @return
     */
    bool setPureDamage(int inputDamage)
    {
        if (this->hp  >= inputDamage)
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
        return this->nickname;
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

#endif //LABA_2_AIOP_FIGHTER_HPP


