#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool check(string email, string pwd)
{
    ifstream keys ("keys.txt");

    string em;
    string pd;
    map<string, string> all;

    while (keys.good()) {
        keys >> em >> pd;

        all[em] = pd;
    }

    if (all[email] == pwd) {
        return true;
    } else {
        return false;
    }

    keys.close();
}

bool reg(string email, string pwd)
{
    ifstream keysCheck ("keys.txt");

    string em;
    string pd;
    map<string, string> all;

    while (keysCheck.good()) {
        keysCheck >> em >> pd;

        all[em] = pd;
    }

    keysCheck.close();

    ofstream keys;

    keys.open("keys.txt", std::ios_base::app);

    if (all[email] == "") {
        keys << "\n" << email << " " << pwd;
        
        return true;
    } else {
        return false;
    } 
}

int main()
{
    bool superCond = true;

    while (superCond == true) {
        int choice;
        cout << "LOGIN [1]\tREGISTER [2]\n";
        cin >> choice;

        if (choice == 1) {
            string emailCheck;
            cout << "\nINSERT EMAIL\n";
            cin >> emailCheck;

            string pwdCheck;
            cout << "\nINSERT PASSWORD\n";
            cin >> pwdCheck;

            bool cond = check(emailCheck, pwdCheck);

            if (cond == true) {
                cout << "\nLOGGED IN\n";
                superCond = false;
            } else {
                cout << "\nEMAIL OR PASSWORD INCORRECT\n\n";
            }
        } else if (choice == 2) {
            string emailCreate;
            cout << "\nINSERT EMAIL\n";
            cin >> emailCreate;

            string pwdCreate;
            cout << "\nINSERT PASSWORD\n";
            cin >> pwdCreate;

            bool con = reg(emailCreate, pwdCreate);

            if (con == true) {
                cout << "ACCOUNT CREATED\n";
            } else {
                cout << "\nACCOUNT ALREADY EXISTS\n\n";
            }
        } else if (choice == 3) {
            superCond = false;
        } else {
            cout << "TRY AGAIN\n\n";
        }
    }
}