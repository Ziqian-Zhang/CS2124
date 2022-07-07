//
// Created by cy0194 on 6/11/2022.
//

//DISPLAY 11.3 Money ClassVersion 1
//Program to demonstrate the class Money.
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);
    friend Money add(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns the sum of the values of amount1 and amount2.

    friend bool equal(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if the amount1 and amount2 have the same value;
    //otherwise, returns false.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with the
    //dollars and cents given by the arguments. If the amount is negative,
    //then both dollars and cents must be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money( );
    //Initializes the object so its value represents $0.00.

    double getValue( );
    //Precondition: The calling object has been given a value.
    //Returns the amount of money recorded in the data of the calling object.

    void input(istream& ins);
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file. An amount of money, including a dollar sign, has been
    //entered in the input stream ins. Notation for negative amounts is -$100.00.
    //Postcondition: The value of the calling object has been set to
    //the amount of money read from the input stream ins.

    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
    //Postcondition: A dollar sign and the amount of money recorded
    //in the calling object have been sent to the output stream outs.
private:
    long allCents;
};



int digitToInt(char c);
//Function declaration for function used in the definition of Money::input:
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digitToInt('3') returns 3.


Money add(Money amount1, Money amount2)
{
    Money temp;

    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

bool equal(Money amount1, Money amount2)
{
    return (amount1.allCents == amount2.allCents);
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive


    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars*100 + cents;
}

Money::Money(long dollars) : allCents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : allCents(0)
{
    //Body intentionally blank.
}

double Money::getValue( )
{
    return (allCents * 0.01);
}
//Uses iostream, cctype, cstdlib:
void Money::input(istream& ins)
{
    char oneChar, decimalPoint,
            digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if ( oneChar != '$' || decimalPoint != '.'
         || !isdigit(digit1) || !isdigit(digit2) )


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digit1)*10 + digitToInt(digit2);

    allCents = dollars*100 + cents;
    if (negative)
        allCents = -allCents;
}

//Uses cstdlib and iostream:
void Money::output(ostream& outs)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if (allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0') );
}

ostream& operator <<(ostream& outs, const Money& amount){

    long positive_cents, dollars, cents;

    positive_cents = labs(amount.allCents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if(amount.allCents < 0){
        outs << "-$" << dollars << '.';
    }else{
        outs << "$" << dollars << ".";
    }

    if(cents < 10){
        outs << '0';
    }

    outs << cents;

    return outs;
}

//Check Class
class Check{

public:
    Check();
    Check(int number, Money amount, bool cashed);
    void setNumber(int number);
    void setAmount(Money amount);
    void setCashed(bool cashed);
    int getNumber();
    Money getAmount();
    bool getCashed();

    friend istream& operator >>(istream& ins, Check& chk);
    friend ostream& operator <<(ostream& outs, const Check& chkInfo);

private:
    int checkNumber;
    Money checkAmount;
    bool cashed;


};

Check::Check() : checkNumber(0), checkAmount(0), cashed(false) {}
Check::Check(int number, Money amount, bool cashed){
    this->checkNumber = number;
    this->checkAmount = amount;
    this->cashed = cashed;
}

void Check::setNumber(int number){
    this->checkNumber = number;
}

void Check::setAmount(Money amount){
    this->checkAmount = amount;
}

void Check::setCashed(bool cashed){
    this->cashed = cashed;
}

int Check::getNumber(){
    return this->checkNumber;
}

Money Check::getAmount(){
    return this->checkAmount;
}

bool Check::getCashed(){
    return this->cashed;
}

istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if(one_char == '-'){
        negative = true;
        ins >> one_char;
    }else{
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if(one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "The input is not valid.";
        exit(1);
    }

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    amount.allCents = dollars * 100 + cents;

    if(negative){
        amount.allCents = -amount.allCents;
    }

    return ins;
}

istream& operator >>(istream& ins, Check& chk){
    int chkno;
    Money chkamt;
    bool cashed;

    while(!(ins >> chkno) || !(ins >> chkamt) || !(ins >> cashed)){
        ins.clear();
        cin.ignore(80,'\n');
        cout << "Invalid input for check." << endl;
    }

    cin.ignore(80,'\n');
    chk.checkNumber = chkno;
    chk.checkAmount = chkamt;
    chk.cashed = cashed;

    return ins;
}


ostream& operator <<(ostream& outs, const Check& chkInfo){
    outs << "Check no: " << chkInfo.checkNumber << ", Amount: " << chkInfo.checkAmount << ", ";
    if(chkInfo.cashed){
        outs << "Cashed";
    }else{
        outs << "Not Cashed";
    }
    return outs;
}

int main() {
    const int size = 10;
    Check checks[size];
    int count = 0, k=0, j=0;
    double initBal, finalBal, deposit, checkAmts = 0, depositAmts = 0, checkCasedAmts = 0;

    double deposits[size];
    char ans;
    vector<int> uncashedChecks, cashedChecks;

    cout << "Enter the initial account balance: ";
    cin >> initBal;

    cout << "Enter deposit amount (max 5, -1 to stop):" <<endl;
    cin >> deposit;

    while(deposit != -1 && count<size){
        deposits[count] = deposit;
        count++;
        cin >> deposit;
    }

    for(int i=0; i<count; i++){
        initBal = initBal + deposits[i];
        depositAmts = depositAmts + deposits[i];
    }

    count = 0;

    do{
        cout << "Enter check details (number amount if cashed or not (using 1:cashed, 0: not cashed)): "<<endl;
        cin >> checks[count];
        cout << "Would you like to enter another checks details? (y/n): ";
        cin >> ans;
        count++;
    }while( ans == 'y' || ans == 'Y');

    for(int i = 0; i < size; i++){
        double value = (checks[i].getAmount()).getValue();
        if(checks[i].getCashed()){
            initBal = initBal - value;
            checkCasedAmts += value;
            cashedChecks.push_back(checks[i].getNumber());
        }else{
            if(checks[i].getNumber() != 0){
                uncashedChecks.push_back(checks[i].getNumber());
            }
        }
        checkAmts += value;
    }


    cout << "\nThe final balance is: $" << initBal << endl;
    cout << "The total amount of all deposits made: $" << depositAmts << endl;
    cout << "The total amount of all checks: $" << checkAmts << endl;
    cout << "The total amount of all checks cashed: $" << checkCasedAmts << endl;

    if(cashedChecks.size() > 0){
        cout << "The list of cashed checks is: " << endl;
        for(int i = 0; i < cashedChecks.size(); i++){
            cout << cashedChecks[i] << "\t";
        }
        cout << endl;
    }

    if(uncashedChecks.size() > 0){
        cout << "The list of uncashed checks is: " << endl;
        for(int i = 0; i < uncashedChecks.size(); i++){
            cout << uncashedChecks[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}

