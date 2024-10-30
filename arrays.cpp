#include <iostream>
#include <string>
using namespace std;

void StudentValues() {
    int totalVals = 5;
    string bank[totalVals];


    for (int i = 0; i < totalVals; i++) {
        cout << "Please enter a number for student " << i + 1 << ": ";
        cin >> bank[i];
        
    }

    for (int i = 0; i < totalVals; i++) {
        cout << bank[i] << " " << endl;
    }

}


int main() {

    StudentValues();
    cout << "Thats Cool" << endl;

    


    return 0;
}