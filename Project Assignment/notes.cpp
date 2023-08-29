#include <iostream>
using namespace std;

class Employee
{
   public:
      Employee() { id = salary = 0; cout << "Employee(" << id << ")" << endl; }
      ˜Employee() { cout << "˜Employee(" << id << ")" << endl; }
      void set(int sid, int s) { id = sid; salary = s; }
   private:
      int id;
      int salary;
   };
class Company
{
   public:
      Company(int n)
      {
         num_employees = n; employee = new Employee[n];
         cout << "Company(" << num_employees << ")" << endl;
         for (int i = 0; i < num_employees; i++)
            employee[i].set(100 + i, 10000);
      }
      ˜Company() { delete [] employee; cout << "˜Company()" << endl; }
      private:
         int num_employees;
         Employee *employee;
};

int main()
{
   Company c_ga_ga(2);
   return 0;
}