#include <iostream>
#include <fstream>
#include "lab7.h"

using namespace std;

// TODO1: Reorder the linked list so that VIP customers come first
// Your would need to reorder the entries in the given array, with VIP customers comes first
//      Both the VIP customers and the normal customers would be then ordered by their ID repectively
//      Example: ID0_VIP, ID1_Non_VIP, ID2_VIP => ID0_VIP, ID2_VIP, ID1_Non_VIP
void reorder_customer(Customer* queue [], int num_customer) {
    //Customer* queue[] = &queue;

    //
    for (int i = 0; i < num_customer; i++)
        for (int j = i+1; j < num_customer; j++)
            if ((*queue[i]).vip == false && (*queue[j]).vip == true)
            {
                Customer temp = *queue[i];
                *queue[i] = *queue[j];
                *queue[j] = temp;
            }

    for (int i = 0; i < num_customer; i++)
        for (int j = i+1; j < num_customer; j++)
        {
            if ((*queue[i]).vip == (*queue[j]).vip && (*queue[i]).id > (*queue[j]).id)
            {
                Customer temp = *queue[i];
                *queue[i] = *queue[j];
                *queue[j] = temp;
            }
        }

    return;
}

// TODO2: Let customers check out from the store, and get the money
// Customers comes in the ordered of the array
// For each of the customers' needs, if the store can satisfy it, sell the corresponding amount and get the paid money, otherwise skip this need (sell nothing and earn nothing)
//      Example: If a customer need 5 Apples and 5 Bananas and the store have 10 Apples and 2 Bananas left, then sell 5 Apples (and 0 Bananas) to the customer
// You don't need to delete the pointers to customers in this TODO
int check_out(Fruit fruits [], const Customer* const queue [], int num_fruit, int num_customer) {

    int Revenue = 0;
    for (int i = 0; i < num_customer; i++)
    {
        for (int j = 0; j < num_fruit; j++)
        {
            if ((*queue[i]).need[j] <= fruits[j].total_count)
            {
                fruits[j].total_count -= (*queue[i]).need[j];
                fruits[j].sold_count  += (*queue[i]).need[j];
            }
            else continue;
        }
    }
    for (int i = 0; i < FRUIT_NUM; i++)
    {
        fruits[i].total_count += fruits[i].sold_count;
        Revenue += (fruits[i].sold_count * fruits[i].unit_price);
    }

    if (Revenue > 0)
        return Revenue;

    return 0;
}