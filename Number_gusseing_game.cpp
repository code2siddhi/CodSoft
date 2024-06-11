#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void printBanner() {
    const string red = "\033[1;31m";
    const string green = "\033[1;32m";
    const string yellow = "\033[1;33m";
    const string blue = "\033[1;34m";
    const string magenta = "\033[1;35m";
    const string cyan = "\033[1;36m";
    const string reset = "\033[0m";

    cout << blue;
    cout << "       =====================================" << endl;
    cout << "       |       " << red << "N" << yellow << "u" << green << "m" << cyan << "b" << magenta << "e" << red << "r" << " " 
         << yellow << "G" << green << "u" << cyan << "e" << magenta << "s" << red << "s" << yellow << "i" << green << "n" 
         << cyan << "g" << " " << magenta << "G" << red << "a" << yellow << "m" << green << "e" << blue << "       |" << endl;
    cout << "       =====================================" << reset << endl;
}

int main() {
    const string red = "\033[1;31m";
    const string green = "\033[1;32m";
    const string blue = "\033[1;34m";
    const string cyan = "\033[1;36m";
    const string magenta = "\033[1;35m";
    const string yellow = "\033[1;33m";
    const string reset = "\033[0m";

    printBanner();
    cout << cyan << "\n\t\t\tWelcome to the " << magenta << "GuessTheNumber" << cyan << " game!" << reset << endl;
    cout << yellow << "You have to guess a number between 1 and 100. You'll have limited choices based on the level you choose. Good Luck!" << reset << endl;

    while (true) {
        cout << cyan << "\nEnter the difficulty level: \n" << reset;
        cout << "1 for " << green << "easy!" << reset << "\t";
        cout << "2 for " << blue << "medium!" << reset << "\t";
        cout << "3 for " << red << "difficult!" << reset << "\t";
        cout << "0 to " << magenta << "end the game!" << reset << "\n" << endl;

        // select the level of difficulty
        int difficultyChoice;
        cout << yellow << "Enter the number: " << reset;
        cin >> difficultyChoice;

        // generating the secret number
        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;

        if (difficultyChoice == 1) {
            cout << green << "\nYou have 10 choices for finding the secret number between 1 and 100." << reset;
            int choicesLeft = 10;
            for (int i = 1; i <= 10; i++) {
                cout << cyan << "\n\nEnter the number: " << reset;
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << green << "Well played! You won, " << playerChoice << " is the secret number!" << reset << endl;
                    cout << magenta << "\t\t\tThanks for playing...." << reset << endl;
                    cout << blue << "Play the game again with us!!\n\n" << reset << endl;
                    break;
                } else {
                    cout << red << "Nope, " << playerChoice << " is not the right number." << reset << endl;
                    if (playerChoice > secretNumber) {
                        cout << yellow << "The secret number is smaller than the number you have chosen." << reset << endl;
                    } else {
                        cout << yellow << "The secret number is greater than the number you have chosen." << reset << endl;
                    }
                    choicesLeft--;
                    cout << blue << choicesLeft << " choices left." << reset << endl;
                    if (choicesLeft == 0) {
                        cout << red << "You couldn't find the secret number, it was " << secretNumber << ". You lose!!" << reset << endl;
                        cout << blue << "Play the game again to win!!!\n\n" << reset << endl;
                    }
                }
            }
        } else if (difficultyChoice == 2) {
            cout << blue << "\nYou have 7 choices for finding the secret number between 1 and 100." << reset;
            int choicesLeft = 7;
            for (int i = 1; i <= 7; i++) {
                cout << cyan << "\n\nEnter the number: " << reset;
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << green << "Well played! You won, " << playerChoice << " is the secret number!" << reset << endl;
                    cout << magenta << "\t\t\tThanks for playing...." << reset << endl;
                    cout << blue << "Play the game again with us!!\n\n" << reset << endl;
                    break;
                } else {
                    cout << red << "Nope, " << playerChoice << " is not the right number." << reset << endl;
                    if (playerChoice > secretNumber) {
                        cout << yellow << "The secret number is smaller than the number you have chosen." << reset << endl;
                    } else {
                        cout << yellow << "The secret number is greater than the number you have chosen." << reset << endl;
                    }
                    choicesLeft--;
                    cout << blue << choicesLeft << " choices left." << reset << endl;
                    if (choicesLeft == 0) {
                        cout << red << "You couldn't find the secret number, it was " << secretNumber << ". You lose!!" << reset << endl;
                        cout << blue << "Play the game again to win!!!\n\n" << reset << endl;
                    }
                }
            }
        } else if (difficultyChoice == 3) {
            cout << red << "\nYou have 5 choices for finding the secret number between 1 and 100." << reset;
            int choicesLeft = 5;
            for (int i = 1; i <= 5; i++) {
                cout << cyan << "\n\nEnter the number: " << reset;
                cin >> playerChoice;

                if (playerChoice == secretNumber) {
                    cout << green << "Well played! You won, " << playerChoice << " is the secret number!" << reset << endl;
                    cout << magenta << "\t\t\tThanks for playing...." << reset << endl;
                    cout << blue << "Play the game again with us!!\n\n" << reset << endl;
                    break;
                } else {
                    cout << red << "Nope, " << playerChoice << " is not the right number." << reset << endl;
                    if (playerChoice > secretNumber) {
                        cout << yellow << "The secret number is smaller than the number you have chosen." << reset << endl;
                    } else {
                        cout << yellow << "The secret number is greater than the number you have chosen." << reset << endl;
                    }
                    choicesLeft--;
                    cout << blue << choicesLeft << " choices left." << reset << endl;
                    if (choicesLeft == 0) {
                        cout << red << "You couldn't find the secret number, it was " << secretNumber << ". You lose!!" << reset << endl;
                        cout << blue << "Play the game again to win!!!\n\n" << reset << endl;
                    }
                }
            }
        } else if (difficultyChoice == 0) {
            cout << magenta << "Thanks for playing! Goodbye!" << reset << endl;
            break;
        } else {
            cout << red << "Wrong choice, enter a valid choice to play the game! (0,1,2,3)" << reset << endl;
        }
    }
    return 0;
}

