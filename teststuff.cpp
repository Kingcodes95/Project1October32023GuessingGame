#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int roll1, roll2;
    srand (time(NULL));

    roll1 = rand() % 101 + 100;

    while (roll1 <= 200 && roll1 >= 100) {
        cout << "The numbers are between 100-200" << endl;
        cout << roll1 << endl;
        roll1 = rand() % 101 + 100;
    }

    cout << roll1 << endl;

    return 0;
}


