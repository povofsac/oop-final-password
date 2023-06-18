#include "PasswordGenerator.h"
#include "PasswordStrengthChecker.h"
#include <iostream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int strengthLevel;
    cout << "Enter desired password strength level (1 = Weak, 2 = Strong, 3 = Unbreakable): ";
    cin >> strengthLevel;

    while (strengthLevel < 1 || strengthLevel > 3) {
        cout << "Invalid strength level. Please re-enter (1 = Weak, 2 = Strong, 3 = Unbreakable): ";
        cin >> strengthLevel;
    }


 PasswordGenerator generator;
    int passwordLength = generator.getPasswordLength(strengthLevel);
    string password = generator.generatePassword(passwordLength, strengthLevel);

    cout << "Generated Password: " << password << endl;

    PasswordStrengthChecker strengthChecker(password);

    switch (strengthLevel) {
        case 1:
            if (!strengthChecker.isStrong() && !strengthChecker.isUnbreakable())
                cout << "Password strength: Weak" << endl;
            else
                cout << "Password strength: Strong" << endl;
            break;
        case 2:
            if (strengthChecker.isUnbreakable())
                cout << "Password strength: Unbreakable" << endl;
            else
                cout << "Password strength: Strong" << endl;
            break;
        case 3:
            if (strengthChecker.isUnbreakable())
                cout << "Password strength: Unbreakable" << endl;
            else if (strengthChecker.isStrong())
                cout << "Password strength: Strong" << endl;
            else
                cout << "Password strength: Weak" << endl;
            break;
    }

    return 0;
}

