

class Fighter
{
protected:
    std::string nickName;
    int hp;
    int blockID;

    int mana; // mana


    int standartMagicArmor;
    int standartPhysicalArmor;
    
    // armor
    int magicArmor;
    int physicalArmor;
    float dodge; // ������� ��������� �� ���. ����� (�� 0.0 �� 1.0)

    bool magicBlock;
    std::vector<SkillContract*> skills;
    std::vector<SideEffect*> sideEffects;

public:

    virtual void useUltimate(Fighter* defencer) = 0;

    virtual int getMana()
    {
        return 0;
    }

    Fighter(int inputHP, int standartMagicArmor = 0, int standartPhysicalArmor = 0, std::string nickName = "FIGHTER") : nickName(nickName), standartMagicArmor(standartMagicArmor), standartPhysicalArmor(standartPhysicalArmor), hp(inputHP), magicArmor(0), physicalArmor(0), magicBlock(false)
    {}

    void clearStats()
    {
        this->magicArmor = this->standartMagicArmor;
        this->physicalArmor = this->standartPhysicalArmor;
    }

    void updatePlayer()
    {
        this->clearStats();
        for (int i = 0; i < sideEffects.size(); i++)
        {
            sideEffects[i]->makeSideEffect(this);
        }
    }
   
    void addSideEffect(SideEffect* inputSideEffect)
    {
        this->sideEffects.push_back(inputSideEffect);
    }

    void addSkill(SkillContract* inputSC)
    {
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

    

    bool attackPlayer(Fighter* defencer)
    {
        int inputID = 0;
        
        while (inputID > skills.size() && inputID <= 0)
        {
            std::cout << this->getNick() << ", �������� ���� �����:\n";
            this->showSkills();

            std::cout << "����: ";
            std::cin >> inputID;

            if (inputID > skills.size() && inputID <= 0)
            {
                std::cout << "[������] ������ �������� ����� �����������." << '\n';
                continue;
            }
            else
            {
                if (skills[inputID - 1]->getCost() > this->getMana())
                {
                    std::cout << "[������] � ��� ������������ ����!" << '\n';
                    inputID = 0;
                }
            }
        }

        std::cout << this->getNick() << " ���������� ����������� '" << this->skills[inputID - 1]->getName() << "'\n";
        if (defencer->getBlockID() != inputID)
        {
            this->skills[inputID - 1]->manipulatePlayer(defencer);
            return true;
        }
        else
        {
            std::cout << defencer->getNick() << "��������� ����� ����������." << '\n';
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

