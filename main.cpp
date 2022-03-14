#include "mat.hpp"

using namespace ariel;
using namespace std;

#include <string>
#include <iostream>
#include "mat.hpp"

int handleInt();

char handleChar();

int main() {

    char flag = 'y';
    string temp;
    int a;
    int b;
    char ch1;
    char ch2;
    while (flag == 'y') {
        try {
            cout << "Enter the number of characters in a row:" << endl;
            a = handleInt();
            cout << "Enter the number of characters in a column:" << endl;
            b = handleInt();
            cout << "Enter the first character:" << endl;
            ch1 = handleChar();
            cout << "Enter the second character:" << endl;
            ch2 = handleChar();

            cout << "The mat is:" << endl << ariel::mat(a, b, ch1, ch2);
        }
        catch (invalid_argument &e) {
            cout
                    << R"(An error occurred. Most probably due to incorrect input. Do you wish to try again? (type "y" for "yes" and any other character for "no"))"
                    << endl;
        }
        cout << R"(Do you wish to continue? (type "y" for "yes" and any other character for "no"))" << endl;
        cin >> flag;
    }


}

//handling of incorrect input adapted from:
//https://quick-adviser.com/does-cin-work-with-spaces/
int handleInt() {
    int ret;
    while (!(cin >> ret)) {
        cout << "ERROR: number not entered, try again" << endl;
        cin.clear(); //clear previous input
        cin.ignore(22, '\n'); //discard previous input
    }
    return ret;
}

char handleChar() {
    char ret;
    while (!(cin >> ret)) {
        cout << "ERROR: invalid character entered, try again" << endl;
        cin.clear(); //clear previous input
        cin.ignore(22, '\n'); //discard previous input
    }
    return ret;
}