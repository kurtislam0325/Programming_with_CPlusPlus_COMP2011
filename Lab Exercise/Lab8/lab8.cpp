// COMP2011 Fall 2022
// skeleton.cpp -- lab 8
#include <iostream>
using namespace std;
const int MAX_LENGTH = 50;

struct Fruit
{
    int id;
    char  name[MAX_LENGTH];
    float unit_price;
    int   total_count;
    int   sold_count;
    Fruit* next;
};

// Build a linked list to maintain all fruits.
void warehousing(Fruit* fruit, Fruit* all_fruits)
{
    Fruit* new_fruit = new Fruit;
    new_fruit = fruit;

    Fruit* current = all_fruits;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new_fruit;
}

// Print (name, total_count) pairs of each kind of fruit.
void stock_checking(const Fruit* all_fruits)
{
    for (const Fruit* p = all_fruits; p != nullptr; p = p->next)
    {
        cout << p->name << ": " << p->total_count << endl;
    }
}

// Print the name and count of each kind of fruit
void stock_updating(Fruit* all_fruits, int fruit_id_to_sell, int number_to_sell)
{
    for (Fruit* p = all_fruits; p != nullptr; p = p->next)
    {
        if (p->id == fruit_id_to_sell)
        {
            p->sold_count += number_to_sell;
            p->total_count -= number_to_sell;
        }
    }
}

// Calculate selling amount
float selling_amount_calculating(const Fruit* all_fruits)
{
    int selling_amount = 0;
    for (const Fruit* p = all_fruits; p != nullptr; p = p->next)
    {
        selling_amount += p->unit_price * p->sold_count;
    }
    return selling_amount;
}

int main() 
{
    Fruit* all_fruits;
    Fruit fruit1 = {0,"Apple", 5, 50, 0, nullptr};
    all_fruits = &fruit1;
    Fruit fruit2 = {1, "Banana", 3, 30, 0, nullptr};
    warehousing(&fruit2, all_fruits);        
    Fruit fruit3 = {2, "Strawberry", 10, 40, 0, nullptr};
    warehousing(&fruit3, all_fruits);
    Fruit fruit4 = {3, "Peach", 8, 30, 0, nullptr};
    warehousing(&fruit4, all_fruits);
    Fruit fruit5 = {4, "watermelon", 30, 10, 0, nullptr};
    warehousing(&fruit5, all_fruits);
    unsigned int fruit_id_to_sell, number_to_sell, selling_amount;
    int reply;

    do {
        cout << "===========================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Check stock" << endl;
        cout << "2: Sell" << endl;
        cout << "3: Calculate selling amount" << endl;
        cout << "4: Quit" << endl;
        cin >> reply;

        switch(reply) {
        case 1:
            stock_checking(all_fruits);
            break;
        case 2:
            cout << "Please enter the id of a fruit bought by a customer: \n" ;
            cout << "0: Apple; 1: Banana; 2: Strawberry; 3: Peach; 4: watermelon \n";
            cin >> fruit_id_to_sell;
            cout << "How many are sold?\n";
            cin >> number_to_sell;
            stock_updating(all_fruits, fruit_id_to_sell, number_to_sell);
            stock_checking(all_fruits);
            break;
        case 3:
            selling_amount = selling_amount_calculating(all_fruits);
            cout << "Selling amount of the day is: " << selling_amount << " HKD!!!\n";
            break;
        default:
            break;
        }

    } while (reply != 4);

    return 0;
}


