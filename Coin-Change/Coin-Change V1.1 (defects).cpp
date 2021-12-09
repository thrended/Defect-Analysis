//  Code Version 1.1 (successfully compiles, defects present)

/*
Code Changes :
printf replaced with cout for C++
Syntax errors are fixed so the code compiles
The line “i = i + 1” is moved to inside the while loop so it properly terminates
*/

/****************************************************************/
int main()
{
    int total_coin_value;
    int number_of_coins = 0;
    int number_of_dollars = 0;
    int number_of_cents = 0;
    int coin_value[] = { 1,5,10,25,25,100 };

    int i = 1;
    while (i < 6)
    {
        cout << "input number of coins\n";
        scanf("%d", &number_of_coins);
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
