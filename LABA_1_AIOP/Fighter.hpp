

class Fighter
{
protected:
    std::string nickName;
    int hp;
    int blockID;



    int standartMagicArmor;
    int standartPhysicalArmor;
    
    float dodge; // процент уклонения от физ. урона (от 0.0 до 1.0)

    bool magicBlock;
    std::vector<Skill*> skills;

public:



    virtual void useUltimate(Fighter* defencer) = 0;

    virtual void updateFighter()
    {
        return;
    }

    virtual int getMana()
    {
        return 0;
    }

    Fighter(int inputHP, int standartMagicArmor = 0, int standartPhysicalArmor = 0, std::string nickName = "FIGHTER") : nickName(nickName), standartMagicArmor(standartMagicArmor), standartPhysicalArmor(standartPhysicalArmor), hp(inputHP), magicBlock(false)
    {}
 

    void addSkill(Skill* inputSC)
    {
        inputSC->setOwnerNick(this->getNick());
        this->skills.push_back(inputSC);
    }

    void showSkills()
    {
        for (int i = 0; i < skills.size(); i++)
        {
            std::cout << i + 1 << ". " << skills[i]->getName();
            
            if (skills[i]->getCost() == 0)
            {
                std::cout << '\n';
            }
            else
            {
                std::cout << " [Mana: " << skills[i]->getCost() << "]\n";
            }

        }
    }

    bool setSkillAttack(Skill* enemySkill)
    {
        int resultDamage;

        switch (enemySkill->getDamageType())
        {
        case DamageType::PURGE:
            resultDamage = this->setPureDamage(enemySkill->getDamage());
            break;
        case DamageType::PHYSICAL:
            resultDamage = this->setPhysicalDamage(enemySkill->getDamage());
            break;
        case DamageType::MAGIC:
            resultDamage = this->setMagicDamage(enemySkill->getDamage());
            break;
        default:
            throw new std::logic_error("Wrong DamageType input in getSkillAttack function");
            break;
        }

        std::cout << enemySkill->skillMessage(this->getNick()) << " ["<< resultDamage << " HP damage]\n"; 
        return true;
    }

    bool attackPlayer(Fighter* defencer)
    {
        int inputID = 0;
        
        while (inputID > skills.size() && inputID <= 0)
        {
            std::cout << this->getNick() << ", выберите свою атаку:\n";
            this->showSkills();

            std::cout << "ВВОД: ";
            std::cin >> inputID;

            if (inputID > skills.size() && inputID <= 0)
            {
                std::cout << "[Ошибка] Введен неверный номер способности." << '\n';
                continue;
            }
            else
            {
                if (skills[inputID - 1]->getCost() > this->getMana())
                {
                    std::cout << "[Ошибка] У вас недостаточно маны!" << '\n';
                    inputID = 0;
                }
            }
        }

        std::cout << this->getNick() << " использует способность '" << this->skills[inputID - 1]->getName() << "'\n";
        if (defencer->getBlockID() != inputID)
        {
            defencer->setSkillAttack(this->skills[inputID - 1]);
            return true;
        }
        else
        {
            std::cout << defencer->getNick() << "Блокирует атаку противника." << '\n';
            return false;
        }
    }


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
    int setPureDamage(int inputDamage)
    {
       this->hp -= inputDamage;
       return inputDamage;
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

    float getDodge()
    {
        return this->dodge;
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

    void addHP(int inputHP)
    {
        this->hp += inputHP;
    }


    /**
     * get player nickname
     * @return
     */
    std::string getNick()
    {
        return this->nickName;
    }

    void setNick(std::string inputNick)
    {
        this->nickName = inputNick;
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

