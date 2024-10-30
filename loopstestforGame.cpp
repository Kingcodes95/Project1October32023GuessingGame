#include <iostream>
using namespace std;

int main ()
{
    int score = 100;
    enum options{displayLeft = 1, displayRight = 2, guess = 3, change = 4, Exit = 5};
    options choice = guess;
    int numChoice, leftValue = -1, rightValue = -1, randomRoll1, randomRoll2, numberGuess;
    string name;
    //srand(static_cast<unsigned>(time(nullptr)));
    srand (time(NULL));
    bool gamePlay = true;

    while (gamePlay)
    {
        cout << "   " << leftValue << "      " << rightValue << endl;     
        cout << "Here are your options:" << endl;
        cout << "1. Display Left number" << endl; 
        cout << "2. Display Right number" << endl;
        cout << "3. Guess the number" << endl;
        cout << "4. Change" << endl;
        cout << "5. Exit The Game" << endl;
        cout << "What would you like to do?: "; 
        cin >> numChoice;

        switch (numChoice) 
        {
            case 1:
            leftValue = randomRoll1;
            break;

            case 2:
            rightValue = randomRoll2;
            break;

            case 3:
            
            cout << "Enter a guess: ";
            cin >> numberGuess;
            if (numberGuess > randomRoll1 && numberGuess < randomRoll2)
            {
                cout << "You got points!!" << endl;
            }
            else
            {
                cout << "Sorry try again" << endl;
            }  
            break;

            case 4:
            //code
            break;

            case 5:
            cout << "You are now leaving the game!" << endl;
            return 0;
            break;

            default:
            cout << "I do not understand this command" << endl;
            break;
        }
    }
    return 0;
}