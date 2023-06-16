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
 