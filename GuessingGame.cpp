#include <iostream>
#include <string>
#include <cctype>
#include <time.h>
using namespace std;

int main()
{
    cout << "This program was made by Ronald Perez & Angelica Gallegos" << endl;
    cout << "Rap0249, Ronaldperez@my.unt.edu  & Ag1734 Angelicagallegos2@my.unt.edu" << endl;
    cout << "        Computer Science" << endl;
    cout << endl;
    //cout << "----------------------------------------------------" << endl;

    int score = 100;
    enum options{displayLeft = 1, displayRight = 2, guess = 3, change = 4, Exit = 5};
    options choice = guess;
    int numChoice, leftValue = -1, rightValue = -1, randomRoll1, randomRoll2, numberGuess;
    string name;
    bool valueShown = false;
    srand(time(NULL));

    //checks if name has valid characters A-Z and a-z
    while (true) {

         bool validName = true;
         bool capitalize = true;

        cout << "Please Enter your name: ";
        getline(cin, name);

        // checks each character position if it is a digit or a #$%^$# character
        for (char ch : name)
        {
        if (isdigit(ch) || ispunct(ch))
        {
            validName = false;
            break;
        }
        }
        // if the name doesn't have a digit or a %^$#$% character, it will allow you to continue
        if (validName == true) 
        {
            
            // iterates thru the name to capitalize the first initials and the rest lowercase
            for (size_t i = 0; i < name.length(); i++)
            {
                char& currentChar = name[i];

                // checks the for first letter and then moves to next if its capitalized.
                if (capitalize) 
                {
                    currentChar = toupper(currentChar);
                    capitalize = false;
                } 
                // if there is a space, it will capitalize the next letter.
                else if (isspace(currentChar))
                {
                    capitalize = true;
                }
                //if its not the first letter it will make it lowercase
                else 
                {
                    currentChar = tolower(currentChar);
                }
            }
            
            cout << "Welcome to the Guessing Game " << name << "!" << endl;
            break;
        }
        else 
        {
            cout << "Please enter a Valid name without numbers or any special digits!" << endl;
            
        }
    
    }

    // Creates both random numbers 100-200 exclusive making sure the first value is smaller than the second
    do 
    {

    randomRoll1 = rand() % 99 + 101;
    randomRoll2 = rand() % 99 + 101;

    }
    while (randomRoll1 > randomRoll2); 
    
    //The actual game itself, runs the command options and the switch case while adding and subtracting points
    while (score >= 0)
    {
        cout << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "   " << leftValue << "         " << rightValue << "        "  << "Current score = " << score << endl; 
        cout << "----------------------------------------------------" << endl; 
        cout << "The objective of the game is to guess a number inbetween the 2 hidden values above!" << endl;  
        cout << "The left number will always be lower than the right number and between 101-199!" <<endl;
        //cout << "If you show either bounds of the numbers you will only gain 1 point per correct guess and lose 10 points per incorrect answer." << endl;
        cout << endl; 
        cout << "Here are your options:" << endl;
        cout << "1. Display Left number" << endl; 
        cout << "2. Display Right number" << endl;
        cout << "3. Guess a number inbetween" << endl;
        cout << "4. Change the random values (Minus 1 Point)" << endl;
        cout << "5. Exit The Game" << endl;
        cout << "What would you like to do?: "; 
        cin >> numChoice;

        switch (numChoice) 
        {
            case 1:
                //If the right bound number is showing then this will not allow the first number to show
                if (rightValue != randomRoll2)
                {
                    cout << endl;
                    cout << "You will now lose 10 points for incorrect answers and gain 1 for correct answers" << endl;
                    leftValue = randomRoll1;
                    valueShown = true;
                }
                else
                {
                    cout << "You're already showing the right value, you cannot show both" << endl;
                }
                break;

            case 2:
                //If the left number is showing then this will not allow the second number to show
                if (leftValue != randomRoll1)
                {
                    cout << endl;
                    cout << "You will now lose 10 points for incorrect answers and gain 1 for correct answers" << endl;
                    rightValue = randomRoll2;
                    valueShown = true;
                }
                else
                {
                    cout << "You're already showing the left value, you cannot show both" << endl;
                }
                break;

            case 3:
                cout << "Enter a guess: ";
                cin >> numberGuess;
                //if the number is between the 2 guess' then the person will get points added.
                if (numberGuess > randomRoll1 && numberGuess < randomRoll2)
                {
                    //valueShown is a bool statement stating if either left or right bound is showing then the point
                    //system changes from gaining 5 to gain 1, and losing 1 to losing 10
                    if (valueShown == false)
                    {
                        cout << endl;
                        cout << "You got it correct and gained 5 points!" << endl;
                        cout << "Now randomizing, you won't get me this time" << endl;
                        score = 5 + score;
                    }
                    else
                    {
                        cout << endl;
                        cout << "You got it correct and gained 1 points!" << endl;
                        cout << "Good luck, Randomizing" << endl;
                        score = 1 + score;
                    }
                    do 
                    {
                        randomRoll1 = rand() % 99 + 101;
                        randomRoll2 = rand() % 99 + 101;

                    }
                    while (randomRoll1 > randomRoll2);
                        leftValue = -1;
                        rightValue = -1;
                        valueShown = false;
                }
                else
                {
                    cout << endl;
                    cout << "You didn't Get the answer right, try again" << endl;
                    
                    if (valueShown == false)
                    {
                    
                        cout << "You lost 1 point." << endl;
                        score = score - 1;
                    }
                    else 
                    { 
                        cout << endl;
                        cout << "You lost 10 points." << endl;
                        score = score - 10;
                    }
                    
                    
                }

                break;

            case 4:
                //Changes the values of the random numbers
                cout << endl;
                cout << "Randomly changing the values!" << endl;
                score = score - 1;
                cout << "You lost 1 point for changing numbers!" << endl;
                do 
                {

                randomRoll1 = rand() % 99 + 101;
                randomRoll2 = rand() % 99 + 101;

                }
                while (randomRoll1 > randomRoll2);
                leftValue = -1;
                rightValue = -1;
                break;

            case 5:
                cout << "--------------------------------------" << endl;
                cout << "     You are now leaving the game.  " << endl;
                cout << "     You finished with " << score << " points!" << endl;
                cout << "--------------------------------------" << endl;
                return 0;
                break;

            default:
                cout << "I don't recongnize that command, enter a value (1-5)" << endl;
                //Because the user can enter values that aren't just numbers it needs to be cleared and ignored in
                //order for the code to re - loop if i understood it correctly 
                cin.clear();
                cin.ignore();
                break;
        }
    }
    cout << name << "! you ran out of points, You lost!" << endl;

    return 0;
}