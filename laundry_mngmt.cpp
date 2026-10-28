#include <iostream>
#include <string>
#include <array>

using namespace std;

enum service {quit, washing, laundering, dry_cleaning, ironing};

class Laundry
{
    string name;
    string location;
    string slogan;

    public:
        void set_details()
        {
            name = "KIKAPU LAUNDRY";
            location = "Steadfast Towers, Moi Avenue, Nairobi";
            slogan = "From Your Basket to Fresh and Folded.";
            
        }
        void start_up()
        {
            set_details();
            cout << "======================== \n";
            cout << "\n WELCOME TO "<< name << "! \n";
            cout << slogan << endl;
            cout << "\n ======================== \n";

        }
};

class Employee
{
    array<array<string, 2>, 4> employees = {{
        {"Rebecca Mantola", "0712345678"},
        {"Alice Machoka", "0723456789"},
        {"Robert Karimu", "0734567891"},
        {"Charles Mutembei", "0745678912"}
    }};

    public:
        string att_name;
        string phone;
        string attendant(int service)
        {
            switch(service)
            {
                case quit:
                    return "";
                    break;
                case washing:
                    att_name = employees[0][0];
                    return att_name;
                    break;
                case laundering:
                    att_name = employees[3][0];
                    return att_name;
                    break; 
                case dry_cleaning:
                    att_name = employees[1][0];
                    return att_name;
                    break; 
                case ironing: 
                    att_name = employees[2][0];
                    return att_name;
                    break;
                default:
                    return "Unknown";
            }
        }
};

class Services
{
    public:
    int choice;
    int list_services()
    {
        cout << "Select your preffered service: " << endl;
        cout << "1) Wash-and-Fold" << endl;
        cout << "2) Shirt service (Laundered and Pressed)" << endl;
        cout << "3) Dry Cleaning" << endl;
        cout << "4) Ironing and Steam Pressing" << endl;
        cin >> choice;

        return choice;
    }
    
};


class Order
{
    int weight;
    int items;
    int price;
    int cost;

    public:
    int make_order(int service)
    {
        switch(service)
        {
            case quit:
                return 0;
            case washing:
                cout << "How much does your load weigh? (in kg) ";
                cin >> weight;
                price = 150;
                if (weight < 5)
                {
                    cout << "Error: Minimum weight is 5kg. Please try again!";
                    return 0;
                    break;
                }
                cost = weight * price;
                return cost;
                break;
            case laundering:
                cout << "Number of items: ";
                cin >> items;
                price = 250;
                cost = items * price;
                return cost;
                break; 
            case dry_cleaning:
                cout << "Number of items: ";
                cin >> items;
                price = 250;
                cost = items * price;
                return cost;           
                break; 
            case ironing: 
                cout << "Number of items: ";
                cin >> items;
                price = 50;
                cost = items * price;
                return cost;  
                break;
            default:
                return 0;
        }
    }
};

class Payment{
    public:
    void process_payment(int cost, string attendant)
    {
        cout << "Your total cost will be " << cost << endl;
        cout << attendant << " will be your attendant." << endl;
    }
};

int main(){
    Laundry laundry;
    laundry.start_up();
    Services service;
    int choice = service.list_services();
    Payment payment;
    Employee employee;
    Order order;

    int total = order.make_order(choice);
    string att = employee.attendant(choice);
    if (total == false)
    {
        cout << "Sorry! It seems like there was an error. PLease try again.";
    }
    else
    {
        payment.process_payment(total, att);
    }
}