#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    vector<string> history;
    string input;

    cout << "===== Calculator =====\n";
    cout << "Enter q to quit or h to show last 10 calculations.\n";

    while (true) {
        double a, b, result;
        char op;

        cout << "\nEnter first number: ";

        if (!(cin >> a)) {
            cin.clear();
            cin >> input;

            if (input == "q" || input == "Q")
                break;

            if (input == "h" || input == "H") {
                cout << "\n--- Last 10 Calculations ---\n";
                if (history.empty())
                    cout << "No calculations yet.\n";
                else
                    for (const string& item : history)
                        cout << item << endl;
                continue;
            }

            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cout << "Enter operator (+, -, *, /, %, ^): ";
        cin >> op;

        if (op != '+' && op != '-' && op != '*' &&
            op != '/' && op != '%' && op != '^') {
            cout << "Invalid operator!\n";
            continue;
        }

        cout << "Enter second number: ";

        if (!(cin >> b)) {
            cin.clear();
            cin >> input;
            cout << "Invalid number! Please try again.\n";
            continue;
        }

        bool valid = true;

        switch (op) {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                if (b == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                    valid = false;
                } else {
                    result = a / b;
                }
                break;

            case '%':
                if (b == 0) {
                    cout << "Error: Cannot use zero for modulus.\n";
                    valid = false;
                } else {
                    result = fmod(a, b);
                }
                break;

            case '^':
                result = pow(a, b);
                break;
        }

        if (valid) {
            cout << "Result = " << result << endl;

            string calculation =
                to_string(a) + " " + op + " " +
                to_string(b) + " = " + to_string(result);

            history.push_back(calculation);

            if (history.size() > 10)
                history.erase(history.begin());
        }
    }

    cout << "\nCalculator closed. Goodbye!\n";
    return 0;
}
