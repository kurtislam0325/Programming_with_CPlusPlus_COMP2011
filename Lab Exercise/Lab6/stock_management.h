// A struct that contains all the information about a type of fruit.
#include <iostream>
using namespace std;

const unsigned int MAX_FRUIT_NUM = 5;
const int MAX_LENGTH = 50;

struct Fruit
{
   char  name[MAX_LENGTH];
   float unit_price;
   int   total_count;
   int   sold_count;
};