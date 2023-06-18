#ifndef PasswordStrengthChecker_h
#define PasswordStrengthChecker_h
#include <ctime>
#include <string>
#include <regex>
#include <cstdlib>
using namespace std;

class PasswordStrengthChecker {
private:
      string password;
public:
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

    PasswordStrengthChecker(const string& pass) : password(pass) {}

    bool isUnbreakable() {
        regex uppercase("[A-Z]");
        regex lowercase("[a-z]");
        regex digit("[0-9]");
        regex special("[!@#$%^&*(),.?:{}|<>]");

        if (password.length() < 14||
        !regex_search(password, uppercase)||
        !regex_search(password, lowercase)||
        !regex_search(password, digit)||
        !regex_search(password, special))
            return false;

        return true;
    }

    bool isStrong() {
        regex uppercase("[A-Z]");
        regex lowercase("[a-z]");
        regex digit("[0-9]");

        if (password.length() < 10||
        !regex_search(password, uppercase)||
        !regex_search(password, lowercase)||
        !regex_search(password, digit))
            return false;

        return true;
    }
     bool isWeak() {
        regex uppercase("[A-Z]");
        regex lowercase("[a-z]");

        if (password.length() < 6||
        !regex_search(password, uppercase)||
        !regex_search(password, lowercase))
            return false;

        return true;
    }
};
 #endif
 
 
