#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct BankRecord {
    string accountNumber;
    string name;
    double balance;

    string toString() const {
        return accountNumber + "," + name + "," + to_string(balance);
    }
};


void addRecord(const string &filename) {
    BankRecord record;
    cout << "Enter Account Number: ";
    cin >> record.accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, record.name);
    cout << "Enter Balance: ";
    cin >> record.balance;

    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << record.toString() << endl;
        file.close();
        cout << "Record added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void showRecords(const string &filename) {
    cout << "\nList of Records:" << endl;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

void searchRecord(const string &filename) {
    string accountNumber;
    cout << "Enter Account Number to search: ";
    cin >> accountNumber;

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.substr(0, line.find(',')) == accountNumber) {
                cout << "Record found: " << line << endl;
                file.close();
                return;
            }
        }
        file.close();
        cout << "Record not found." << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void editRecord(const string &filename) {
    string accountNumber, line;
    cout << "Enter Account Number to edit: ";
    cin >> accountNumber;

    vector<BankRecord> records;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (line.substr(0, pos) == accountNumber) {
                BankRecord record;
                record.accountNumber = accountNumber;
                cout << "Enter new Account Holder Name: ";
                cin.ignore();
                getline(cin, record.name);
                cout << "Enter new Balance: ";
                cin >> record.balance;
                records.push_back(record);
            } else {
                size_t nextPos = line.find(',', pos + 1);
                BankRecord record;
                record.accountNumber = line.substr(0, pos);
                record.name = line.substr(pos + 1, nextPos - pos - 1);
                record.balance = stod(line.substr(nextPos + 1));
                records.push_back(record);
            }
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }

    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto &rec : records) {
            outFile << rec.toString() << endl;
        }
        outFile.close();
        cout << "Record updated successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void deleteRecord(const string &filename) {
    string accountNumber;
    cout << "Enter Account Number to delete: ";
    cin >> accountNumber;

    vector<BankRecord> records;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.substr(0, line.find(',')) != accountNumber) {
                size_t pos = line.find(',');
                size_t nextPos = line.find(',', pos + 1);
                BankRecord record;
                record.accountNumber = line.substr(0, pos);
                record.name = line.substr(pos + 1, nextPos - pos - 1);
                record.balance = stod(line.substr(nextPos + 1));
                records.push_back(record);
            }
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }

    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto &rec : records) {
            outFile << rec.toString() << endl;
        }
        outFile.close();
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void menu() {
    string filename = "bank_records.txt";
    int choice;

    do {
        cout << "\nBanking Record System" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Show Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Edit Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(filename); break;
            case 2: showRecords(filename); break;
            case 3: searchRecord(filename); break;
            case 4: editRecord(filename); break;
            case 5: deleteRecord(filename); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}


int main() {
    menu();
    return 0;
}
