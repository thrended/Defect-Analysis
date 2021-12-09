//  The final repaired code (Version 1.2) :
/*******************************************************************
Defects repaired along with documentation enhancements
*******************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int total_coin_value = 0;
    int number_of_coins = 0;
    unsigned int number_of_dollars = 0;
    unsigned int number_of_cents = 0;
    const int coin_value[] = { 1,5,10,25,50,100 };
    const string coin_names[] = { "pennies", "nickels", "dimes",
                          "quarters", "half dollars", "dollars" };
    const string* const coin = coin_names;

    int i = 0;
    while (i < 6)
    {
        cout << "input number of " << *(coin + i) << "\n";	// improve clarity
        cin >> number_of_coins;
        while (cin.fail() || number_of_coins < 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid data type. Please enter a nonnegative integer\n"
                "input number of " << *(coin + i) << "\n";
            cin >> number_of_coins;
        }
        // scanf replaced by cin
        total_coin_value = total_coin_value +
            (number_of_coins * coin_value[i]);
        i = i + 1;
    }
    number_of_dollars = total_coin_value / 100;
    number_of_cents = total_coin_value - (100 * number_of_dollars);
    cout << "\n Number of Dollars = " << number_of_dollars;
    cout << "\n Number of Cents = " << number_of_cents << "\n";

}

/****************************************************************/
