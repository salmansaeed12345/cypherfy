
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;


// FUNCTION PROTOTYPES

string encrypt_easy(string s);
string decrypt_easy(string s);

string decrypt_medium(string s);
string encrypt_medium(string s);

string encrypt_diff(string s);
string decrypt_diff(string s);


// MAIN FUNCTION

int main() {


}


// FUNCTION DEFINITIONS


string encrypt_easy(string s) {
    int k = 3;
    for (int i = 0; i < s.length();i++) {

        char c = toupper(s[i]);

        if (c >= 'A' && c <= 'Z') {
            c = c + k;
            if (c > 'Z')
                c -= 26;
        }

        s[i] = c;
    }
    return s;
}


string decrypt_easy(string s) {
    int k = 3;
    for (int i = 0; i < s.length();i++) {

        char c = toupper(s[i]);

        if (c >= 'A' && c <= 'Z') {
            c = c - k;
            if (c < 'A')
                c += 26;
        }

        s[i] = c;
    }
    return s;
}


string decrypt_medium(string s) {
    int k = 5;
    for (int i = 0; i < s.length();i++) {

        char c = toupper(s[i]);

        if (c >= 'A' && c <= 'Z') {
            c = c - k;
            if (c < 'A')
                c += 26;
        }

        s[i] = c;
    }
    return s;
}


string encrypt_medium(string s) {
    int k = 5;
    for (int i = 0; i < s.length();i++) {

        char c = toupper(s[i]);

        if (c >= 'A' && c <= 'Z') {
            c = c + k;
            if (c > 'Z')
                c -= 26;
        }
        s[i] = c;
    }
    return s;
}


string encrypt_diff(string s) {
    int k = 2;
    for (int i = 0; i < s.length();i++) {

        char c = toupper(s[i]);

        if (c == 'A') {
            c = 64;
        }                                    // null in place of A

        else if (c == 'E') {
            c = 32;
        }                                   // space in place of E

        else if (c == 'I') {
            c = 46;
        }                                    // full stop for I

        else if (c == 'O') {
            c = 61;
        }                                         // = for O

        else if (c == 'U') {
            c = 86;
        }                                         // V for U

        else if (c >= 'A' && c <= 'Z') {
            c = c + k;

            if (c > 'Z')
                c -= 26;
        }

        s[i] = c;
    }
    return s;
}


string decrypt_diff(string s) {
    int k = 2;
    for (int i = 0; i < s.length();i++) {

        char c = s[i];

        if (c == 64) {
            c = 65;
        }                                    // null in place of A

        else if (c == 32) {
            c = 69;
        }                                   // space in place of E

        else if (c == 46) {
            c = 73;
        }                                    // full stop for I

        else if (c == 61) {
            c = 79;
        }                                         // = for O

        else if (c == 86) {
            c = 85;
        }                                         // V for U

        else if (c >= 'A' && c <= 'Z') {
            c = c - k;

            if (c < 'A')
                c += 26;
        }

        s[i] = c;
    }
    return s;
}
