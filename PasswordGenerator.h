
#ifndef PasswordGenerator_h
#define PasswordGenerator_h

#include <string>
#include <random>

class PasswordGenerator {
private:
    std::string password;
    std::mt19937 generator;

    char getRandomChar(int strengthLevel) {
        std::uniform_int_distribution<int> distribution(0, 255);

        int type = distribution(generator) % 4;
        if (type == 0 && strengthLevel == 3)
            return "!@#$%^&*(),.?\":{}|<> "[distribution(generator) % 18];  // Add special characters here
        else if (type == 2 && strengthLevel == 2)
            return '0' + distribution(generator) % 10;
        else if (type == 1)
            return 'a' + distribution(generator) % 26;
        else
            return 'A' + distribution(generator) % 26;
    }

public:
    PasswordGenerator() {
        std::random_device rd;
        generator.seed(rd());
    }

    std::string generatePassword(int strengthLevel) {
        int length = 0;
        switch(strengthLevel)
        {
        case 1:
            length = 8;
            for (int i = 0; i < length; ++i) {
                password += getRandomChar(1);
            }
            break;
        case 2:
            length = 12;
            for (int i = 0; i < length; ++i) {
                password += getRandomChar(2);
            }
            break;
        case 3:
            length = 15;
            for (int i = 0; i < length; ++i) {
                password += getRandomChar(3);
            }
            break;
        default:
            break;
        }
        return password;
    }
};

#endif