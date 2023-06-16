#include "PasswordGenerator.h"
#include "PasswordStrengthChecker.h"
#include <iostream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

int getPasswordLength(int strengthLevel) {
    int length;
    switch (strengthLevel) {
        case 1:
            length = 6; 
            break;
        case 2:
            length = 10; 
            break;
        case 3:
            length = 14; 
            break;
        default:
            length = 0; 
    }
    return length;
}

string generatePassword(int length, int strengthLevel) {
    string password;
    string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digitChars = "0123456789";
    string specialChars = "!@#$%^&*()";

    string characters;

    
    characters += lowercaseChars;
    characters += uppercaseChars;

    if (strengthLevel >= 2) {
        
        characters += digitChars;
    }

    if (strengthLevel >= 3) {
        
        characters += specialChars;
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, characters.length() - 1);

    for (int i = 0; i < length; i++) {
        int index = distribution(generator);
        password += characters[index];
    }

    return password;
}

int main() {
    int strengthLevel;
    cout << "Enter desired password strength level (1 = Weak, 2 = Strong, 3 = Unbreakable): ";
    cin >> strengthLevel;

    while (strengthLevel < 1 || strengthLevel > 3) {
        cout << "Invalid strength level. Please re-enter (1 = Weak, 2 = Strong, 3 = Unbreakable): ";
        cin >> strengthLevel;
    }

    int passwordLength = getPasswordLength(strengthLevel);
    string password = generatePassword(passwordLength, strengthLevel);

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
