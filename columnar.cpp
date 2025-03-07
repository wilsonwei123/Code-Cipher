#include "columnar.hpp"

using namespace std;

long long return_greatest_pos (vector<long long> arr) {
    long long greatest = 0;
    for (long long i = 0; i < arr.size(); i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }

    return greatest;
}

vector<long long> order(vector<long long> ar) {
    vector<pair<long long, long long>> indexed_ar;
    
    for (long long i = 0; i < ar.size(); i++) {
        indexed_ar.push_back({ar[i], i});
    }

    sort(indexed_ar.begin(), indexed_ar.end());

    vector<long long> result(ar.size());
    long long counter = 1;

    for (const auto& pair : indexed_ar) {
        result[pair.second] = counter++;
    }

    return result;
}


int encrypt() {
    string word_input;
    vector<long long> ar_to_work;
    unordered_map<char, long long> alphabet = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
        {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10},
        {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15},
        {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20},
        {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25},
        {'z', 26}
    };
    cout << "Enter your encryption key: ";
    cin >> word_input;
    for (char c : word_input) {
        ar_to_work.push_back(alphabet[c]);
    }

    vector<long long> encryption_key = order(ar_to_work);

    string input;
    cout << "Enter your message (no spaces) to encrypt: ";
    cin >> input;
    string remainder_grid;
    vector<string> grid;
    unordered_map<long long, long long> encryption_map;
    long long encryption_len = encryption_key.size(), greatest_ek = return_greatest_pos(encryption_key), col_num;
    col_num = input.size() / encryption_len;

    for (long long i = 0; i < greatest_ek; i++) {
        encryption_map.insert({encryption_key[i], i});
    }

    while (input.size() > encryption_len) {
        string dummy_string = "";
        for (long long i = 0; i < encryption_len; i++) {
            dummy_string.push_back(input[0]);
            input.erase(0, 1);
        }
        grid.push_back(dummy_string);
    }

    remainder_grid = input;
    for (long long i = 0; i < (greatest_ek - input.size()); i++) {
        remainder_grid += 'X';
    }

    for (long long i = 1; i <= greatest_ek; i++) {
        for (long long j = 0; j < col_num; j++) {
            cout << grid[j][encryption_map[i]];
        }

        if (remainder_grid[encryption_map[i]] != 'X') {
            cout << remainder_grid[encryption_map[i]];
        }
    }

    cout << "\n";
    return 0;
}

int decrypt() {
    string word_input;
    vector<long long> ar_to_work;
    unordered_map<char, long long> alphabet = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
        {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10},
        {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15},
        {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20},
        {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25},
        {'z', 26}
    };
    cout << "Enter your decryption key: ";
    cin >> word_input;
    for (char c : word_input) {
        ar_to_work.push_back(alphabet[c]);
    }

    string input, messy_remainder = "", remainder = "";
    cout << "Enter your string to decrypt: ";
    cin >> input;

    vector<long long> decryption_key = order(ar_to_work);

    unordered_map<long long, long long> decryption_map, decryption_map_inverse;
    vector<string> messy_grid, ordered_grid;
    long long grid_remainder = input.size() % decryption_key.size(), greatest_dk = return_greatest_pos(decryption_key), col_num = input.size() / decryption_key.size();
    for (long long i = 0; i < greatest_dk; i++) {
        decryption_map.insert({decryption_key[i], i});
        decryption_map_inverse.insert({i, decryption_key[i]});
    }

    for (long long i = 1; i <= greatest_dk; i++) {
        string to_add = "";
        for (long long j = 0; j < col_num; j++) {
            to_add += input[0];
            input.erase(0, 1);
        }

        if (decryption_map[i] < grid_remainder) {
            messy_remainder += input[0];
            input.erase(0, 1);
        } else {
            messy_remainder += "_";
        }

        messy_grid.push_back(to_add);
    }

    for (long long i = 0; i < greatest_dk; i++) {
        ordered_grid.push_back(messy_grid[(decryption_map_inverse[i]) - 1]);
    }


    for (long long i = 0; i < col_num; i++) {
        for (long long j = 0; j < greatest_dk; j++) {
            cout << ordered_grid[j][i];
        }
    }

    for (int i = 0; i < greatest_dk; i++) {
        if (messy_remainder[decryption_map_inverse[i] - 1] != '_') {
            remainder.push_back(messy_remainder[decryption_map_inverse[i] - 1]);
        }
    }

    cout << remainder << "\n";

    return 0;
}

int home_columnar() {
    int ans;
    cout << "Encrypt (enter 1) or Decrypt (enter 2): ";
    cin >> ans;
    if (ans == 1) {
        encrypt();
    } else if (ans == 2) {
        decrypt();
    }
    
    /* else if (ans == 3) {
        long long key_size;
        vector<long long> passkey;
        cin >> key_size;
        for (long long i = 0; i < key_size; i++) {
            long long dummy_var;
            cin >> dummy_var;
            passkey.push_back(dummy_var);
        }

        for (long long  num : order(passkey)) {
            cout << num;
        }
        cout << "\n";
    }
    */

    return 0;
}
