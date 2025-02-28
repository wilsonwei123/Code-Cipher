#include "affine.hpp"

using namespace std;

int encrypt() {
    unordered_map<char, long long> alphabet;
    unordered_map<long long, char> alphabet_inverse;

    for (long long i = 0; i < 26; ++i) {
        alphabet['a' + i] = i;
        alphabet_inverse[i] = 'a' + i;
    }

    long long a, b;
    string input;
    
    cout << "Enter your 0-25 integer that is coprime to 26 for the value a: ";
    cin >> a;

    while (a < 0 || a > 25 || gcd(a, 26) != 1) {
        cout << "Invalid input, try again: ";
        cin >> a;
    }

    cout << "Enter your 0-25 integer for the value b: ";
    cin >> b;

    while (b < 0 || b > 25) {
        cout << "Invalid input, try again: ";
        cin >> b;
    }

    cout << "Enter your message to encrypt (only alphabetical characters): ";
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        cout << alphabet_inverse[(alphabet[input[i]] * a) + b];
    }

    cout << "\n";
    return 0;
}

int decrypt() {
    unordered_map<char, long long> alphabet;
    unordered_map<long long, char> alphabet_inverse;

    for (long long i = 0; i < 26; ++i) {
        alphabet['a' + i] = i;
        alphabet_inverse[i] = 'a' + i;
    }

    long long a, b;
    string input;
    
    cout << "Enter your 0-25 integer that is coprime to 26 for the value a: ";
    cin >> a;

    while (a < 0 || a > 25 || gcd(a, 26) != 1) {
        cout << "Invalid input, try again: ";
        cin >> a;
    }

    cout << "Enter your 0-25 integer for the value b: ";
    cin >> b;

    while (b < 0 || b > 25) {
        cout << "Invalid input, try again: ";
        cin >> b;
    }

    cout << "Enter your message to decrypt (only alphabetical characters): ";
    cin >> input;

    //tbc
}

int home_affine() {

}
