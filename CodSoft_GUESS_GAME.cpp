#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main() {    
srand(time(0));
int secretNumber = rand() % 100 + 1;
int userGuess = 0;
    
cout<<"< CODSOFT GUESS GAME >"<<endl<<endl;
cout << "Guess the number (between 1 and 100): ";

    while (true) {
        cin >> userGuess;

        if (userGuess > secretNumber) {
            cout << "Too high! Try again: ";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You guessed the right number: " << secretNumber << endl;
            break;
        }
    }

    return 0;
}
