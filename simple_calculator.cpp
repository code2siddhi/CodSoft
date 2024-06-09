//Task 2
//SIMPLE CALCULATOR
/*
We worship the three-eyed one (Lord Shiva), who is fragrant and who nourishes and increases the vitality of all beings. 
May he liberate us from the bondage of worldly attachments and death, granting us the nectar of immortality.

*/

#include<bits/stdc++.h>
using namespace std;

void printBanner() {
    // ANSI escape codes for colors
    const string yellow = "\033[1;33m";
    const string cyan = "\033[1;36m";
    const string reset = "\033[0m";

    cout << cyan;
    cout << "       =====================================" << endl;
    cout << "       |           " << yellow << "Simple Calculator" << cyan << "       |" << endl;
    cout << "       =====================================" << reset << endl;
    
    cout<<"                    --   welcome  --              "<<endl;
}

void printBorder() {
    const string cyan = "\033[1;36m";
    const string reset = "\033[0m";

    cout << cyan << "        -------------------------------------" << reset << endl;
}

void solve() {
    double num1, num2;
    char operation;

    // Input numbers and operation from user
    printBorder();
    cout << "       | Enter first number: " << endl;
    cin >> num1;
    cout << "      | You entered first number: ";
    cout << num1 << endl;
    printBorder();

    cout << "       | Enter an operator (+, -, *, /): " << endl;
    cin >> operation;
    cout << "       | You entered: " << operation << endl;
    printBorder();

    cout << "       | Enter second number: " << endl;
    cin >> num2;
    cout << "	| You entered second number: " << num2 << endl;
    printBorder();

    // Perform the chosen operation
    const string red = "\033[1;31m";
    const string green = "\033[1;32m";
    const string reset = "\033[0m";

    switch (operation) {
        case '+':
            cout << "       | Result: " << green << num1 + num2 << reset << endl;
            break;
        case '-':
            cout << "       | Result: " << green << num1 - num2 << reset << endl;
            break;
        case '*':
            cout << "       | Result: " << green << num1 * num2 << reset << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "       | Result: " << green << num1 / num2 << reset << endl;
            } else {
                cout << "       | " << red << "Error: Division by zero is not allowed." << reset << endl;
            }
            break;
        default:
            cout << "| " << red << "	Error: Invalid input." << reset << endl;
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    printBanner();
    
    int t = 1;  // Run the calculator once
    // Comment out the next line if you want to run the calculator multiple times
    // cin >> t;  

    while (t--) {
        solve();
    }

    return 0;
}


