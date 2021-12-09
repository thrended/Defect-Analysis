/*
Original outline of defective code
Specification for Program calc_coin_value

Inputs : number_of_coins(integer)
Outputs : number_of_dollars(integer),
number_of_cents(integer)

Sample C++ implementation
Version 1.0 - base code converted to C++ (nonfunctionally defective)
*/
/*****************************************************************
program calculate_coin_values  calculates the dollar and cents
value of a set of coins of different dominations input by the user
denominations are pennies, nickels, dimes, quarters, half dollars,
and dollars
*****************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int total_coin_value;
    int number_of_coins = 0;
    int number_of_dollars = 0;
    int number_of - cents = 0;
    int coin_values = { 1,5,10,25,25,100 };
    {
        int  i = 1;
        while (i < 6)
        {
            printf("input number of coins\n");
            scanf("%d", &number_of_coins);
            total_coin_value = total_coin_value +
                (number_of_coins * coin_value{ i]);
            }
            i = i + 1;
            number_of_dollars = total_coin_value / 100;
            number_of_cents = total_coin_value - (100 * number_of_dollars);
            printf("%d\n", number_of_dollars);
            printf("%d\n", number_of - cents);
        }

        /****************************************************************/