

class BattleManager
{
public:

    static Fighter* makeBattle(Fighter* firstPlayer, Fighter* secondPlayer)
    {
        for (int i = 1; firstPlayer->isAlive() && secondPlayer->isAlive(); i++)
        {
            //system("cls");
            std::cout << "\n==================\n";
            std::cout << "Ход #" << i << '\n';
            std::cout << "Ход игрока " << firstPlayer->getNick() << '\n';
            std::cout << firstPlayer->getNick() << " HP: " << firstPlayer->getHP() << '\n';
            std::cout << secondPlayer->getNick() << " HP: " << secondPlayer->getHP() << '\n';
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
                std::cout << "Тип блока должен быть числом в промежутке от 1 до 5ти. Повторите попытку\n";
            }
            std::cout << inputPlayer->getNick() << ", введите номер блокируемой атаки (от 1 до 5):\n";
            std::cout << "ВВОД:";
            std::cin >> blockID;

            if (blockID > 5 || blockID < 1)
            {
                continue;
            }

            inputPlayer->setBlockID(blockID);
            break;
        }

    }

};