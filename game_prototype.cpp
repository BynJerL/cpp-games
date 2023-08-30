#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_CHANCE 10
#define MIN_NUMBER 0
#define MAX_NUMBER 1000

int main(){
    // Initialization
    srand(time(NULL));
    bool gameOver = false;

    while(!gameOver){
        int playerChance = MAX_CHANCE;
        int realAnswer = (MIN_NUMBER + (rand() % MAX_NUMBER));
        int guessedAnswer;
        while(playerChance > 0){
            cout << "Guess any number (0-999)" << endl;
            cout << "Chance to guess: " << playerChance << endl;
            cout << "Your number: "; cin >> guessedAnswer;

            if (realAnswer == guessedAnswer) {
                cout << "Congrats, you have guessed the right one!\n";
                break;
            } else if (realAnswer != guessedAnswer) {
                if (realAnswer > guessedAnswer) {
                    cout << "too low! ";
                    playerChance -= 1;
                } else if (realAnswer < guessedAnswer) {
                    cout << "too high! ";
                    playerChance -= 1;
                } else {
                    cout << "ERROR!\n";
                    gameOver = true;
                    break;
                } 
            }

            if (playerChance > 0) {
                cout << "Try again.\n\n";
            } else {
                cout << "\nYou lose. Correct answer: " << realAnswer << "\n";
            }
        }

        cout << "Player score: " << playerChance * 100 << "\n\n";

        char replayConf;

        cout << "Play again? (y/n)" << endl;
        cout << "Your answer: "; cin >> replayConf;

        if(replayConf == 'y'){
            cout << "Preparing for the next game... \n\n";
            continue;
        } else if(replayConf == 'n'){
            cout << "Thanks for playing!\n"; 
            break;
        } else {
            cout << "Invalid answer.\n";
            break;
        }
    }
    
    return 0;
}
