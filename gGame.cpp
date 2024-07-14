#include <bits/stdc++.h>
#include <ctime>
using namespace std;

// Class which provide functionality to our game
class GussingData
{
private:
    int random_Number;
    string nameOfPlayer01;
    string nameOfPlayer02;
    string singlePlayer_Name;

public:
    // Friend V/S Friend

    // 1st player information
    void setPlayer01Info()
    {
        cin.ignore();
        cout << " Enter 1st player name here :-        ";
        getline(cin, nameOfPlayer01);
        cout << endl;
    }

    string getPlayer01Info()
    {
        return nameOfPlayer01;
    }

    // 2nd player information
    void setPlayer02Info()
    {
        cout << " Enter 2nd player name here :-        ";
        getline(cin, nameOfPlayer02);
        cout << endl;
    }

    string getPlayer02Info()
    {
        return nameOfPlayer02;
    }

    // Single player
    void setSinglePlayer_Info()
    {
        cin.ignore();
        cout << " Enter your player name here :-        ";
        getline(cin, singlePlayer_Name);
        cout << endl;
    }

    string getSinglePlayer_Info()
    {
        return singlePlayer_Name;
    }

    // random number generator
    void rGenerator()
    {
        srand(time(0));
        random_Number = rand() % 20 + 1;
    }

    // Winner guessing logic
    bool winnerGuess(int guess, const string &playerName)
    {
        if (guess == random_Number)
        {
            cout << "______CONGRETULATIONS_____" << playerName << "_____YOU_____WINS_____" << endl;
            cout << endl;
            return true;
        }
        else
        {
            cout << " WRONG GUESS :- ";
        }

        return false;
    }

    // Hind Giver

    void hintGiver(int guess)
    {
        if (guess < random_Number)
        {
            cout << " TOO LOW " << endl;
        }
        else if (guess > random_Number)
        {
            cout << " TOO HIGH " << endl;
        }
        cout << endl;
    }
};

int main()
{
    int i = 0;

    do
    {

        cout << endl
             << endl
             << "_______________________WELCOME TO THE ARENA_______________________" << endl
             << endl;
        int ch;
        cout << " Enter (1) : "
             << " Single Player " << endl;

        cout << " Enter (2) : "
             << " Friend V/S Friend " << endl;

        cout << " Enter (3) :"
             << "  Exit " << endl;

        cout << endl;
        cout << "  ->  ";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
        {
            bool running = false;
            GussingData ob;
            ob.rGenerator();
            ob.setSinglePlayer_Info();
            do
            {
                int guess;
                cout << ob.getSinglePlayer_Info() << " : " << endl;
                cout << "Enter number between 1-20 :- ";
                cin >> guess;

                if (ob.winnerGuess(guess, ob.getSinglePlayer_Info()))
                {
                    running = true;
                    break;
                }
                ob.hintGiver(guess);
            } while (!running);

            break;
        }
        case 2:
        {
            bool running = false;

            GussingData ob;
            ob.setPlayer01Info();
            ob.setPlayer02Info();
            ob.rGenerator();

            do
            {
                int p1, p2;
                cout << ob.getPlayer01Info() << " : " << endl
                     << "Enter the no. between 1-20 :- ";
                cin >> p1;

                if (ob.winnerGuess(p1, ob.getPlayer01Info()))
                {
                    running = true;
                    break;
                }
                ob.hintGiver(p1);

                cout << ob.getPlayer02Info() << " : " << endl
                     << "Enter the no. between 1-20 :- ";
                cin >> p2;

                if (ob.winnerGuess(p2, ob.getPlayer02Info()))
                {
                    running = true;
                    break;
                }
                ob.hintGiver(p2);

            } while (!running);
            break;
        }
        case 3:
        {
            i = 1;
            break;
        }
        default:
        {
            cout << " YOU ENTERED THE WRONG OPTION , PLEASE SELECT THE CORRECT OPTION !!" << endl;
            break;
        }
        }
    } while (i != 1);

    return 0;
}
