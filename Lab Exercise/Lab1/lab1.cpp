#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Welcome to the exciting, fun, and awesome programming3 world! "
         << "Enter an odd number, and I can tell something about you! " << endl;
    cin >> number;

    if (number % 2 == 0)  
        cout << "Hmm... this is not an odd number..." << endl;
    else if (number < 0)
        cout << "You seem to be a bit negative... :( Cheer up! " << endl;
    else
        cout << "You must be very excited! Me too! :)" << endl;

    return 0;
}