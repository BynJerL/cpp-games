#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_HP 9

int main(){
    // Initialization
    srand(time(NULL));
    int playerHP = MAX_HP;
    int realAnswer = (rand() % 100);
    int guessedAnswer;
    bool gameOver = false;

    while(!gameOver and playerHP > 0){
        cout << "Guess any number (0-99)" << endl;
        cout << "Chance to guess: " << playerHP << endl;
        cout << "Your number: "; cin >> guessedAnswer;

        if (realAnswer == guessedAnswer) {
            cout << "Congrats, you have guessed the right one!\n";
            gameOver = true;
        } else if (realAnswer != guessedAnswer) {
            if (realAnswer > guessedAnswer) {
                cout << "Your number is too low! ";
                playerHP -= 1;
            } else if (realAnswer < guessedAnswer) {
                cout << "Your number is too high! ";
                playerHP -= 1;
            } else {
                cout << "ERROR!\n";
                gameOver = true;
            } 
        }

        if (!gameOver) {
            cout << "Try again.\n\n";
        }
    }

    return 0;
}