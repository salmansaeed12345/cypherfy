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

string check_answer(string s);

void play_game();

// MAIN FUNCTION

int main() {

    int choice;

    do {

        cout << "\n====================================";
        cout << "\n             CYPHERFY";
        cout << "\n====================================";

        cout << "\n1. Start Game";
        cout << "\n2. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {

            play_game(); // Starts the 10-level game

        }

        else if (choice == 2) {

            cout << "\nThank you for playing CYPHERFY!";

        }

        else {

            cout << "\nInvalid choice! Try again.";

        }

    } while (choice != 2); // Repeats menu until player chooses Exit

    return 0;
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

// ANSWER CHECKING FUNCTION

string check_answer(string s) {

    for (int i = 0; i < s.length(); i++) {

        s[i] = toupper(s[i]); // Makes answer comparison case-insensitive
    }

    return s;
}

// GAME FUNCTION

void play_game()
{
    string messages[10] = {
        "HELLO", "WORLD", "COMPUTER", "PROGRAMMING", "SECURITY",
        "ENCRYPTION", "KEYBOARD", "INFORMATION", "CHALLENGE", "VICTORY"
    };

    string hints[10] = {
        "A greeting", "The planet we live on", "An electronic device",
        "Writing instructions for a computer", "Protection from danger",
        "Converting information into secret code", "An input device",
        "Facts or knowledge", "A difficult task", "Winning"
    };

    int attempts;
    string encrypted, answer, guess;
    char choice;

    cout << "\n===== ENCRYPTION GAME =====\n";

    for (int level = 0; level < 10; level++)
    {
        attempts = 5;

        // Selects the encryption function according to the level
        if (level < 3)
        {
            encrypted = encrypt_easy(messages[level]);
        }
        else if (level < 6)
        {
            encrypted = encrypt_medium(messages[level]);
        }
        else
        {
            encrypted = encrypt_diff(messages[level]);
        }

        cout << "\n--------------------------";
        cout << "\nLEVEL " << level + 1;
        cout << "\nEncrypted message: " << encrypted;
        cout << "\nYou have " << attempts << " attempts.";
        cout << "\n--------------------------";

        while (attempts > 0)
        {
            cout << "\nEnter your guess (or H for hint): ";
            cin >> guess;

            // Convert the guess to uppercase
            for (int i = 0; i < guess.length(); i++)
            {
                guess[i] = toupper(guess[i]);
            }

            // Check if the player wants a hint
            if (guess == "H")
            {
                cout << "Hint: " << hints[level] << endl;
                attempts--;
                cout << "Attempts remaining: " << attempts << endl;
            }
            else if (check_answer(guess) == check_answer(messages[level]))
            {
                cout << "\nCorrect! You completed Level " << level + 1 << "!\n";
                break;
            }
            else
            {
                attempts--;
                cout << "Incorrect answer !";
                cout << "\nAttempts remaining: " << attempts << endl;
            }
        }

        // If the player runs out of attempts
        if (attempts == 0)
        {
            cout << "\nYou have run out of attempts!";
            cout << "\nThe correct answer was: " << messages[level] << endl;
        }
    }

    cout << "\n===== GAME COMPLETED =====\n";
    cout << "You have finished all 10 levels!\n";
}
