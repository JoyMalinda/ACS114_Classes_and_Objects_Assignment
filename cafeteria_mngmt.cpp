#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>

using namespace std;

struct MenuItem {
    int id;
    string name;
    int price;
};

class Cafeteria
{
    string cafe_name;
    string location;
    string slogan;

    public:
        void set_details()
        {
            cafe_name = "SIMBA & SPICE";
            location = "Steadfast Towers, Moi Avenue, Nairobi";
            slogan = "Bold Kenyan Heritage in Every Bite";
            
        }
        void start_up()
        {
            set_details();
            cout << "======================== \n";
            cout << "\n WELCOME TO "<< cafe_name << "! \n";
            cout << slogan << endl;
            cout << "\n ======================== \n";

        }
};



class Food
{
    public:
    MenuItem goat {1, "Mbuzi Choma (Grilled Goat)", 1200};
    MenuItem curry {2, "Kuku Paka (Coconut Chicken Curry)", 950};
    MenuItem fish {3, "Swahili Fish Curry (Samaki wa Kupaka)", 1100};
    MenuItem platter {4, "Simba Signature Nyama Platter", 2500};
    MenuItem beef {5, "Beef Mishkaki (Spiced Meat Skewers)", 800};
    MenuItem tilapia {6, "Tilapia Wet Fry", 900};
    MenuItem matoke {7, "Matoke ya Simba (Plantain & Beef Stew)", 750};
    MenuItem mukimo {8, "Mukimo Special", 500};
    MenuItem pilau {9, "Pilau ya Pwani", 700};
    MenuItem mahamri {10, "Mahamri & Spiced Coconut Beans (Maharagwe ya Nazi)", 450};

    MenuItem items[10];
    int count;

    Food() {
        count = 10;
        items[0] = goat;
        items[1] = curry;
        items[2] = fish;
        items[3] = platter;
        items[4] = beef;
        items[5] = tilapia;
        items[6] = matoke;
        items[7] = mukimo;
        items[8] = pilau;
        items[9] = mahamri;
    }
};

class Beverage
{
    public:
    MenuItem dawa {11, "Dawa Cocktail", 600};
    MenuItem chai {12, "Kenyan Spiced Chai", 200};
    MenuItem mojito {13, "Pineapple Mojito (Mocktail)", 600};
    MenuItem coke {14, "Coca-Cola (300ml)", 150};
    MenuItem fanta {15, "Fanta Pineapple (500ml)", 250};

    MenuItem items[5];
    int count;

    Beverage(){
        count = 5;
        items[0] = dawa;
        items[1] = chai;
        items[2] = mojito;
        items[3] = coke;
        items[4] = fanta;
    }
};

class Menu
{
    private:
    Food foodMenu;
    Beverage bevMenu;

    public:
    void displayMenu() {
        cout << "\n========== CAFETERIA MENU ==========\n";
        cout << "What would you like to have today? \n";
        cout << "--- FOOD ---\n";
        for(int i = 0; i < foodMenu.count; i++) {
            cout << foodMenu.items[i].id << ". " << foodMenu.items[i].name 
                 << " - KSh " << foodMenu.items[i].price << "\n";
        }

        cout << "\n--- BEVERAGES ---\n";
        for(int i = 0; i < bevMenu.count; i++) {
            cout << bevMenu.items[i].id << ". " << bevMenu.items[i].name 
                 << " - KSh " << bevMenu.items[i].price << "\n";
        }
        cout << "0. Finish Order & Checkout\n";
        cout << "====================================\n";
    }

    bool findItem(int choice, MenuItem &foundItem) 
    {
        for(int i = 0; i < foodMenu.count; i++) 
        {
            if(foodMenu.items[i].id == choice) 
            {
                foundItem = foodMenu.items[i];
                return true;
            }
        }
        for(int i = 0; i < bevMenu.count; i++) 
        {
            if(bevMenu.items[i].id == choice) 
            {
                foundItem = bevMenu.items[i];
                return true;
            }
        }
        return false;
    }

};

class Order
{
private:
    vector<MenuItem> cart; 

public:
    void takeOrder(Menu &menu) {
        int choice;
        menu.displayMenu();

        while (true) {
            cout << "\nEnter item number (0 to checkout): ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            MenuItem selectedItem;
            if (menu.findItem(choice, selectedItem)) {
                cart.push_back(selectedItem); 
                cout << "Added " << selectedItem.name << " to your order.\n";
            } else {
                cout << "Invalid item number. Please try again.\n";
            }
        }
    }

    bool isEmpty() {
        return cart.empty();
    }

    int getTotal() {
        int total = 0;
        for(size_t i = 0; i < cart.size(); i++) {
            total += cart[i].price;
        }
        return total;
    }

    const vector<MenuItem>& getCart() {
        return cart;
    }   
};

class Payment
{
    public:
    void processPayment(Order &order) {
        const vector<MenuItem>& cart = order.getCart();
        int totalAmount = order.getTotal();

        cout << "\n\n===============================\n";
        cout << "             RECEIPT           \n";
        cout << "           SIMBA & SPICE        \n";
        cout << "===============================\n";

        for(size_t i = 0; i < cart.size(); i++) {
            cout << left << setw(20) << cart[i].name 
                 << "KSh " << cart[i].price << "\n";
        }

        cout << "-------------------------------\n";
        cout << left << setw(20) << "TOTAL:" 
             << "KSh " << right << setw(6) << totalAmount << "\n";
        cout << "===============================\n";

        cout << "Please pay through the MPESA till number: 7654321 \n";
    }
};

int main()
{
    Cafeteria cafeteria;
    cafeteria.start_up();
    Menu menu;
    menu.displayMenu();
    Order currentOrder;

    currentOrder.takeOrder(menu);

    if (currentOrder.isEmpty()) {
        cout << "\nNo items were ordered. Thank you for visiting!\n";
    } else {
        Payment cashRegister;
        cashRegister.processPayment(currentOrder); 
        cout << "\nThank you for visiting! Enjoy your meal.\n";
    }

    return 0;
}