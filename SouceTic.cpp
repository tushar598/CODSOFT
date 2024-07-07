#include <bits/stdc++.h>
using namespace std;
class TicTac
{

public:
    char playerSign()
    {
        char player;
        cout << " What you want 'x' or 'o' ==> ";
        cin >> player;
        return player;
    }

    char playerchooiseSing(const string &a)
    {
        char player;
        cout << a << " you have to choose your sign first :- " << endl;
        cout << " What you want 'x' or 'o' ==> ";
        cin >> player;
        cout << endl;
        return player;
    }

    void groundGrid(char *space)
    {
        cout << endl;
        cout << "     |     |     " << endl;
        cout << "  " << space[0] << "  |  " << space[1] << "  |  " << space[2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << space[3] << "  |  " << space[4] << "  |  " << space[5] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << endl;
        cout << "     |     |     " << endl;
        cout << endl;
    }

    void playerMove(char *space, char p)
    {
        int number;

        do
        {
            cout << " Enter the move between (1-9) :- ";
            cin >> number;
            cout << endl;
            number = number - 1;
            if (space[number] == ' ')
            {
                space[number] = p;
                break;
            }
        } while (!number > 0 || !number < 8);
    }

    void alternatePlayerMove(char *space, char p1)
    {
        int number;

        do
        {
            cout << " Enter the move between (1-9) :- ";
            cin >> number;
            cout << endl;
            number = number - 1;
            if (space[number] == ' ')
            {
                space[number] = p1;
                break;
            }
        } while (!number > 0 || !number < 8);
    }

    void computerMove(char *space, char c)
    {
        int number;
        srand(time(0));
        while (true)
        {
            number = rand() % 9;
            if (space[number] == ' ')
            {
                space[number] = c;
                break;
            }
        }
    }

    bool gameWinner(char *space, char p, char c)
    {

        // rows
        if ((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2]))
        {
            space[0] == p ? cout << "YOU WIN " : cout << "YOU LOSE ";
        }
        else if ((space[3] != ' ') && (space[3] == space[4]) && (space[4] == space[5]))
        {
            space[3] == p ? cout << "YOU WIN " : cout << " YOU LOSE ";
        }
        else if ((space[6] != ' ') && (space[6] == space[7]) && (space[7] == space[8]))
        {
            space[6] == p ? cout << "YOU WIN " : cout << " YOU LOSE ";
        }
        // column
        else if ((space[0] != ' ') && (space[0] == space[3]) && (space[3] == space[6]))
        {
            space[0] == p ? cout << "YOU WIN " : cout << " YOU LOSE ";
        }
        else if ((space[1] != ' ') && (space[1] == space[4]) && (space[4] == space[7]))
        {
            space[1] == p ? cout << "YOU WIN " : cout << " YOU LOSE ";
        }
        else if ((space[2] != ' ') && (space[2] == space[5]) && (space[5] == space[8]))
        {
            space[2] == p ? cout << "YOU WIN " : cout << " YOU LOSE ";
        }

        // Diagonals

        else if ((space[0] != ' ') && (space[0] == space[4]) && (space[4] == space[8]))
        {
            space[0] == p ? cout << " YOU WIN " : cout << " YOU LOSE ";
        }
        else if ((space[2] != ' ') && (space[2] == space[4]) && (space[4] == space[6]))
        {
            space[2] == p ? cout << " YOU WIN " : cout << " YOU LOSE ";
        }
        else
        {
            return false;
        }
        cout << endl;
        return true;
    }

    bool gameTie(char *space)
    {
        int i = 0;
        while (i < 9)
        {
            if (space[i] == ' ')
            {
                return false;
                break;
            }
            i += 1;
        }
        cout << "GAME IS TIE !" << endl;
        cout << "|--- THANK YOU FOR PLAYING ---|" << endl
             << endl;
        return true;
    }
};

int main()
{
    do
    {

        char space[9] = {
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' '};
        int chooice;
        cout << " Enter:-(1) Human V/S Computer " << endl;
        cout << " Enter:-(2) Friend V/S Friend " << endl;
        cout << " Enter (3) for Exit " << endl;
        cout << " ==> ";
        cin >> chooice;

        switch (chooice)
        {
        case 1:
        {
            TicTac obj;

            char player = obj.playerSign();
            char computer;
            bool running = true;
            int i = 0;
            do
            {
                switch (player)
                {
                case 'x':
                {
                    computer = 'o';
                    i = 1;
                    break;
                }

                case 'o':
                {
                    computer = 'x';
                    i = 1;
                    break;
                }
                default:
                {
                    cout << "not a valid sign " << endl;
                    player = 0;
                    player = obj.playerSign();
                }
                }

            } while (i != 1);

            do
            {
                obj.playerMove(space, player);
                obj.groundGrid(space);
                if (obj.gameWinner(space, player, computer))
                {
                    running = false;
                    break;
                }
                else if (obj.gameTie(space))
                {
                    running = false;

                    break;
                }

                obj.computerMove(space, computer);
                obj.groundGrid(space);
                if (obj.gameWinner(space, player, computer))
                {
                    running = false;
                    break;
                }
                else if (obj.gameTie(space))
                {
                    running = false;
                    break;
                }
            } while (running != false);

            break;
        }
        case 2:
        {
            TicTac obj;

            string p1Name;
            string p2Name;
            cout << " Enter name of Player 1 :- ";
            cin >> p1Name;
            cout << endl;
            cout << " Enter name of Player 2 :- ";
            cin >> p2Name;

            char player = obj.playerchooiseSing(p1Name);
            char alternatePlayer;

            // upper code modification
            bool running = true;
            int i = 0;
            do
            {
                switch (player)
                {
                case 'x':
                {
                    alternatePlayer = 'o';
                    i = 1;
                    break;
                }

                case 'o':
                {
                    alternatePlayer = 'x';
                    i = 1;
                    break;
                }
                default:
                {
                    cout << "not a valid sign " << endl;
                    player = ' ';
                    player = obj.playerchooiseSing(p1Name);
                }
                }

            } while (i != 1);

            do
            {
                cout << p1Name << " your move  :- " << endl;
                obj.playerMove(space, player);
                obj.groundGrid(space);
                if (obj.gameWinner(space, player, alternatePlayer))
                {
                    cout << p1Name << endl
                         << endl;
                    running = false;
                    break;
                }
                else if (obj.gameTie(space))
                {
                    running = false;

                    break;
                }

                cout << endl;

                cout << p2Name << " your move next   :- " << endl;
                obj.alternatePlayerMove(space, alternatePlayer);
                obj.groundGrid(space);
                if (obj.gameWinner(space, player, alternatePlayer))
                {
                    cout << p1Name << endl
                         << endl;
                    running = false;
                    break;
                }
                else if (obj.gameTie(space))
                {
                    running = false;
                    break;
                }
            } while (running != false);

            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
            cout << " It's not a valid chooise , Please enter the vaid option ";
            break;
        }
    } while (1 == 1);

    return 0;
}