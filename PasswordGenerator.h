
#ifndef PasswordGenerator_h
#define PasswordGenerator_h

#include <string>
#include <random>
using namespace std;
class PasswordGenerator {
private:

    string lowercaseChars;
    string uppercaseChars;
    string digitChars;
    string specialChars;

public:
  PasswordGenerator() {
        lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
        uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        digitChars = "0123456789";
        specialChars = "!@#$%^&*()";
    }
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
        string characters = lowercaseChars + uppercaseChars;

        if (strengthLevel >= 2) {
            characters += digitChars;
        }

        if (strengthLevel >= 3) {
            characters += specialChars;
        }

        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(0, characters.length() - 1);

        string password;
        for (int i = 0; i < length; i++) {
            int index = distribution(generator);
            password += characters[index];
        }

        return password;
    }
};
#endif
