//
//  main.cpp
//  rec03: Bank Accounts
//
//  Created by Ziqian Zhang on 2022/2/11.
//

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account1 {
    string name;
    int account_num;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class Account2{
public:
    Account2(const string& name, int account_num)
    : name(name), account_num(account_num){}
    
    const string& getName() const {
        return name;
    }
    
    int getNumber() const {
        return account_num;
    }
    
    friend ostream& operator<<(ostream& os, const Account2& account);
    
private:
    string name;
    int account_num;
};

ostream& operator<<(ostream& os, const Account2& account) {
//    os << "Name: " << account.getName() << ", Account number: "
//    << account.getNumber() << endl;
    os << "Name: " << account.name << ", Account number: "
    << account.account_num << endl;
    return os;
}

// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Transaction{
    friend ostream& operator<<(ostream& os, const Transaction& transaction);
public:
    Transaction(const string& type, int amount): type(type), amount(amount){}
private:
    string type;
    int amount;
};

class Account3{
    friend ostream& operator<<(ostream& os, const Account3& account);
public:
    Account3(const string& name, int account_num)
    : name(name), account_num(account_num),balance(0){}
    
    const string& getName() const {
        return name;
    }
    
    int getNumber() const {
        return account_num;
    }
    
    void deposit(int amount){
        tran_history.emplace_back("deposit", amount);
        balance += amount;
    }
    
    void withdrawal(int amount){
        if (balance < amount) {
            cerr << "insufficient funds" << endl;
            return;
        }
        tran_history.emplace_back("withdrawal", amount);
        balance -= amount;
    }
    
private:
    string name;
    int account_num;
    vector<Transaction> tran_history;
    int balance;
};

ostream& operator<<(ostream& os, const Transaction& transaction) {
    os << transaction.type << ' ' << transaction.amount << endl;
    return os;
}

ostream& operator<< (ostream& os, const Account3& account){
    os << "Name: " << account.name << " Account number: "<< account.account_num
    << " Account balance: " << account.balance << "\n" << "Transaction history:" << endl;
    for (const Transaction& curr_tran : account.tran_history){
        os << curr_tran;
    }
    return os;
};

// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)
class Account4{
    friend ostream& operator<<(ostream& os, const Account4& account);
public:
    class Transaction{
        friend ostream& operator<<(ostream& os, const Account4::Transaction& transaction);
    public:
        Transaction(const string& type, int amount): type(type), amount(amount){}
    private:
        string type;
        int amount;
    };
    
    Account4(const string& name, int account_num)
    : name(name), account_num(account_num),balance(0){}
    
    const string& getName() const {
        return name;
    }
    
    int getNumber() const {
        return account_num;
    }
    
    void deposit(int amount){
        tran_history.emplace_back("deposit", amount);
        balance += amount;
    }
    
    void withdrawal(int amount){
        if (balance < amount) {
            cerr << "insufficient funds" << endl;
            return;
        }
        tran_history.emplace_back("withdrawal", amount);
        balance -= amount;
    }
    
private:
    string name;
    int account_num;
    vector<Transaction> tran_history;
    int balance;
};

ostream& operator<<(ostream& os, const Account4& account){
    os << "Name: " << account.name << " Account number: "<< account.account_num
    << " Account balance: " << account.balance << "\n" << "Transaction history:" << endl;
    for (const Account4::Transaction& curr_tran : account.tran_history){
        os << curr_tran;
    }
    return os;
}

ostream& operator<<(ostream& os, const Account4::Transaction& transaction){
    os << transaction.type << ' ' << transaction.amount << endl;
    return os;
}

// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)
class Account5{
    class Transaction5{
        friend ostream& operator<<(ostream& os, const Transaction5& transaction);
    public:
        Transaction5(const string& type, int amount): type(type), amount(amount){}
    private:
        string type;
        int amount;
    };
    friend ostream& operator<<(ostream& os, const Account5& account);
    friend ostream& operator<<(ostream& os, const Transaction5& transaction);
public:
    Account5(const string& name, int account_num)
    : name(name), account_num(account_num),balance(0){}
    
    const string& getName() const {
        return name;
    }
    
    int getNumber() const {
        return account_num;
    }
    
    void deposit(int amount){
        tran_history.emplace_back("deposit", amount);
        balance += amount;
    }
    
    void withdrawal(int amount){
        if (balance < amount) {
            cerr << "insufficient funds" << endl;
            return;
        }
        tran_history.emplace_back("withdrawal", amount);
        balance -= amount;
    }
    
private:
    string name;
    int account_num;
    vector<Transaction5> tran_history;
    int balance;
};
ostream& operator<<(ostream& os, const Account5& account){
    os << "Name: " << account.name << " Account number: "<< account.account_num
    << " Account balance: " << account.balance << "\n" << "Transaction history:" << endl;
    for (const Account5::Transaction5& curr_tran : account.tran_history){
        os << curr_tran;
    }
    return os;
}

ostream& operator<<(ostream& os, const Account5::Transaction5& transaction){
    os << transaction.type << ' ' << transaction.amount << endl;
    return os;
}

void openFile(ifstream& accountFile, const string& file_name);

int main() {

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    
    //open the file, if failed, display the error message
    ifstream accountFile("accounts.txt");
    if (!accountFile){
        cerr << "failed to open the file accounts.txt" << endl;
        exit(1);
    }

    string name;
    int account_num;
    vector<Account1> accounts;
    
    // read account info, and pass the account object into vector
    while (accountFile >> name >> account_num){
        Account1 newAccount;
        newAccount.name = name;
        newAccount.account_num = account_num;
        accounts.push_back(newAccount);
    }
    
    accountFile.close();
    
    // display the objects
    for (const Account1& curr_account : accounts){
        cout << "Name: " << curr_account.name << ", Account number: "
        << curr_account.account_num << endl;
    }

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    
    accounts.clear();
    openFile(accountFile, "accounts.txt");
    
    while(accountFile >> name >> account_num){
        Account1 newAccount{name, account_num};
        accounts.push_back(newAccount);
    }
    
    accountFile.close();
    for (const Account1& curr_account : accounts){
        cout << "Name: " << curr_account.name << ", Account number: "
        << curr_account.account_num << endl;
    }

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<Account2> accounts2;
    openFile(accountFile, "accounts.txt");
    
    while(accountFile >> name >> account_num){
        Account2 newAccount(name, account_num);
        accounts2.push_back(newAccount);
    }
    accountFile.close();
    for (const Account2& curr_account : accounts2){
        cout << "Name: " << curr_account.getName() << ", Account number: "
        << curr_account.getNumber() << endl;
    }

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    accounts2.clear();
    openFile(accountFile, "accounts.txt");
    while(accountFile >> name >> account_num){
        Account2 newAccount(name, account_num);
        accounts2.push_back(newAccount);
    }
    for(const Account2& curr_account : accounts2){
        cout << curr_account;
    }
    accountFile.close();

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    accounts2.clear();
    openFile(accountFile, "accounts.txt");
    while(accountFile >> name >> account_num){
        Account2 newAccount(name, account_num);
        accounts2.push_back(newAccount);
    }
    for(const Account2& curr_account : accounts2){
        cout << curr_account;
    }
    accountFile.close();

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    accounts2.clear();
    openFile(accountFile, "accounts.txt");
    while(accountFile >> name >> account_num){
        accounts2.push_back(Account2(name, account_num));
    }
    for(const Account2& curr_account : accounts2){
        cout << curr_account;
    }
    accountFile.close();
    
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";
    accounts2.clear();
    openFile(accountFile, "accounts.txt");
    while(accountFile >> name >> account_num){
        accounts2.emplace_back(name, account_num);
    }
    for(const Account2& curr_account : accounts2){
        cout << curr_account;
    }
    accountFile.close();
    
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    ifstream tranFile;
    openFile(tranFile, "transactions.txt");
    string type;
    int amount;
    vector<Account3> accounts3;
    while (tranFile >> type) {
        if (type == "Account") {
            tranFile >> name >> account_num;
            accounts3.emplace_back(name, account_num);
        } else if (type == "Deposit") {
            tranFile >> account_num >> amount;
            for (Account3& each : accounts3){
                if (each.getNumber() == account_num){
                    each.deposit(amount);
                    break;
                }
            }
        } else {
            tranFile >> account_num >> amount;
            for (Account3& each : accounts3){
                if (each.getNumber() == account_num){
                    each.withdrawal(amount);
                    break;
                }
            }
        }
    }
    
    for(const Account3& curr_account : accounts3){
        cout << curr_account;
    }
    tranFile.close();

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";
    openFile(tranFile, "transactions.txt");
    vector<Account4> accounts4;
    while (tranFile >> type) {
        if (type == "Account") {
            tranFile >> name >> account_num;
            accounts4.emplace_back(name, account_num);
        } else if (type == "Deposit") {
            tranFile >> account_num >> amount;
            for (Account4& each : accounts4){
                if (each.getNumber() == account_num){
                each.deposit(amount);
                }
            }
        } else {
            tranFile >> account_num >> amount;
            for (Account4& each : accounts4){
                if (each.getNumber() == account_num){
                each.withdrawal(amount);
                }
            }
        }
    }
    
    for(const Account4& curr_account : accounts4){
        cout << curr_account;
    }
    tranFile.close();

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";
    openFile(tranFile, "transactions.txt");
    vector<Account5> accounts5;
    while (tranFile >> type) {
        if (type == "Account") {
            tranFile >> name >> account_num;
            accounts5.emplace_back(name, account_num);
        } else if (type == "Deposit") {
            tranFile >> account_num >> amount;
            for (Account5& each : accounts5){
                if (each.getNumber() == account_num){
                each.deposit(amount);
                }
            }
        } else {
            tranFile >> account_num >> amount;
            for (Account5& each : accounts5){
                if (each.getNumber() == account_num){
                each.withdrawal(amount);
                }
            }
        }
    }
    
    for(const Account5& curr_account : accounts5){
        cout << curr_account;
    }
    accountFile.close();
    tranFile.close();
    
}

void openFile(ifstream& accountFile, const string& file_name){
    accountFile.clear();
    accountFile.open(file_name);
    if (!accountFile){
        cerr << "failed to open the file " + file_name << endl;
        exit(1);
    }
}
