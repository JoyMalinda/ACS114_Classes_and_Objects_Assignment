#include <iostream>
#include <string>
#include <array>

using namespace std;

class Bank
{
    string bank_name;
    string location;
    string slogan;

    public:
        void set_details()
        {
            bank_name = "STEADFAST BANK";
            location = "Steadfast Towers, Moi Avenue, Nairobi";
            slogan = "Banking That Moves with Your Hustle";
            
        }
        void start_up()
        {
            set_details();
            cout << "======================== \n";
            cout << "\n WELCOME TO "<< bank_name << "! \n";
            cout << slogan << endl;
            cout << "\n ======================== \n";

        }
};

class Customer
{
    public:
    string cust_name;
    int age;

    bool validation(int)
    {
        if (age > 17)
            return true;
        else
            return false;
    }

    void set_cust_det()
    {
        cout << "What is your name? ";
        cin >> cust_name;
        cout << "How old are you? ";
        cin >> age;

        bool result = validation(age);

        if (result == true)
            cout << "Hello " << cust_name << endl;
        else
            cout<< "Sorry, you are not of age. Please contact us when you reach 18.";
    }

};

class Account
{

    public:
        double balance = 125000;
        int loan_bal = 15000;
        int selection = 0;
        enum services {quit, deposit, withdraw, take_loan, repay_loan, check_balance};

        void bal_notice()
        {
            cout << "Your account balance is " << balance << endl;
        }
    
        int service_select()
        {
            cout << "Which action would you like? " << endl;
            cout << "1) Deposit" << endl;
            cout << "2) Withdraw" << endl;
            cout << "3) Take out a loan" << endl;
            cout << "4) Pay back a loan" << endl;
            cout << "5) Check Balance" << endl;
            cout << "0) Quit" << endl;
            cin >> selection;
            return selection;
        }

};

class Employee: public Account
{
    string name;
    string att_name;
    string serve_till;
    array<array<string, 3>, 4> employees = {{
        {"Rebecca Mantola", "Till 1", "Banker"},
        {"Alice Machoka", "Till 2", "Loan Agent"},
        {"Robert Karimu", "Till 3", "Loan Agent"},
        {"Charles Mutembei", "Till 4", "Banker"}
    }};
    struct EmployeeData {
        string employee_name;
        string employee_till; 
    };

    public:
        EmployeeData attendant(int service)
        {
            switch(service)
            {
                case deposit:
                    att_name = employees[0][0];
                    serve_till = employees[0][1];
                    return {att_name, serve_till};
                    break;
                case withdraw:
                    att_name = employees[3][0];
                    serve_till = employees[3][1];
                    return {att_name, serve_till};
                    break; 
                case take_loan:
                    att_name = employees[1][0];
                    serve_till = employees[1][1];
                    return {att_name, serve_till};
                    break; 
                case repay_loan: 
                    att_name = employees[2][0];
                    serve_till = employees[1][1];
                    return {att_name, serve_till};
                    break;
                default:
                    return {"Unknown", "No assigned till"};
            }
        }

};

class Loan: public Account
{
    double loan_amt;
    int repay_amt;
    Employee employee;


    public:
        void process_loan(int num)
        {
            if (num == 3)
                {
                    cout << "How much would you like to borrow? " << endl;
                    cout << "Balance: " << loan_bal << endl;
                    cin >> loan_amt;
                    loan_bal += loan_amt;
                    cout << "You have succesfully borrowed " << loan_amt << endl;
                    cout << "Your loan balance is now " << loan_bal << endl;
                    cout << "Your account balance is now " << balance << endl;
                    cout << "\n";
                    cout << "Please proceed to " << employee.attendant(3).employee_till << endl;
                    cout << "You will be attended to by " << employee.attendant(3).employee_name << endl;
                }
            else
                {
                    cout << "How much would you like to pay back? " << endl;
                    cout << "Loan Balance: " << loan_bal << endl;
                    cin >> repay_amt;
                    loan_bal -= loan_amt;
                    cout << "You have succesfully paid back " << repay_amt << endl;
                    cout << "Your loan balance is now " << loan_bal << endl;
                    cout << "Your account balance is now " << balance << endl;
                    cout << "\n";
                    cout << "Please proceed to " << employee.attendant(4).employee_till << endl;
                    cout << "You will be attended to by " << employee.attendant(4).employee_name << endl;
                }
        }
        void check_loan()
        {
            cout << "\n Your outstanding loan balance is Ksh " << loan_bal;
        }

};

class Transaction: public Account
{
    double dep_amt;
    int withdraw_amt;
    int bal_select;

    public:
        Loan loan;
        Employee employee;
        void selection()
        {
            switch(service_select())
            {
            case quit:
                cout << "\t ======================== \n";
                cout << "\n \tThank you for banking with us. \n";
                cout << "\t ======================== \n";
                break;
            case deposit:
                cout << "How much would you like to deposit? ";
                cin >> dep_amt;
                balance += dep_amt;
                cout << "You have succesfully deposited " << dep_amt << endl;
                cout << "Your account balance is now " << balance << endl;
                cout << "\n";
                cout << "Please proceed to " << employee.attendant(1).employee_till << endl;
                cout << "You will be attended to by " << employee.attendant(1).employee_name << endl;
                break;
            case withdraw:
                cout << "How much would you like to withdraw? ";
                cin >> withdraw_amt;
                balance -= withdraw_amt;
                cout << "You have succesfully withdrawn " << withdraw_amt << endl;
                cout << "Your account balance is now " << balance << endl;
                cout << "\n";
                cout << "Please proceed to " << employee.attendant(2).employee_till << endl;
                cout << "You will be attended to by " << employee.attendant(2).employee_name << endl;
                break;
            case take_loan:
                loan.process_loan(3);
                break;
            case repay_loan:
                loan.process_loan(4);
                break;
            case check_balance:
                cout << "Which balance would you like to check? " << endl;
                cout << "1) Account Balance" << endl;
                cout << "2) Loan Balance" << endl;
                cin >> bal_select;
                if (bal_select == 1)
                    bal_notice();
                else if (bal_select == 2)
                    loan.check_loan();
                else
                    cout<< "Invalid input. Please try again.";
                break;
            default:
                cout << "Invalid selection. Please try again.";
            }
        }
};




int main()
{
    Bank start;
    start.start_up();
    Customer details;
    details.set_cust_det();
    Transaction transact;
    transact.selection();
}