

class BattleManager
{
public:

    static Fighter* makeBattle(Fighter* firstPlayer, Fighter* secondPlayer)
    {
        for (int i = 1; firstPlayer->isAlive() && secondPlayer->isAlive(); i++)
        {
            //system("cls");
            std::cout << "\n==================\n";
            std::cout << "��� #" << i << '\n';
            std::cout << "��� ������ " << firstPlayer->getNick() << '\n';
            std::cout << firstPlayer->getNick() << " HP: " << firstPlayer->getHP() << " MANA: " << firstPlayer->getMana() << '\n';
            std::cout << secondPlayer->getNick() << " HP: " << secondPlayer->getHP() << " MANA: " << secondPlayer->getMana() << '\n';
            std::cout << "==================\n";

            makeTurn(firstPlayer, secondPlayer);
            std::swap(firstPlayer, secondPlayer);
        }

        if (firstPlayer->isAlive())
        {
            return firstPlayer;
        }
        else
        {
            return secondPlayer;
        }
    }

protected:

    static void makeTurn(Fighter* attacker, Fighter* defencer)
    {
        bool wrongInput = false;
        int attackID;
        bool attackResult = true;

        selectBlock(defencer);

        attackResult = attacker->attackPlayer(defencer);
        defencer->setBlockID(0);

        if (!attackResult)
        {
            defencer->useUltimate(attacker);
        }

    }

    static void selectBlock(Fighter* inputPlayer)
    {
        bool wrongInput = false;
        int blockID;
        while (true)
        {
            if (wrongInput)
            {
                wrongInput = false;
                std::cout << "��� ����� ������ ���� ������ � ���������� �� 1 �� 5��. ��������� �������\n";
            }
            std::cout << inputPlayer->getNick() << ", ������� ����� ����������� ����� (�� 1 �� 5):\n";
            std::cout << "����:";
            std::cin >> blockID;

            if (blockID > 5 || blockID < 1)
            {
                wrongInput = true;
                continue;
            }

            inputPlayer->setBlockID(blockID);
            break;
        }

    }

};