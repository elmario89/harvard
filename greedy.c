// check50 cs50/2017/ap/greedy => use this to test
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int change;
void print_amount_of_coins(int counter[4]);
void calc_coins(int coin, int counter[4], int index);

int main()
{
    int coins[4] = {25, 10, 5, 1};
    int coins_counter[4] = {0, 0, 0, 0};

    printf("Enter change to give back:\n");

    do
    {
        change = roundf(get_float() * 100.0);
    }
    while (change < 0);

    for (int i = 0; i < 4; i++)
    {
        calc_coins(coins[i], coins_counter, i);
    }

    print_amount_of_coins(coins_counter);
}

void print_amount_of_coins(int counter[4])
{
    int result = 0;

    for (int i = 0; i < 4; i++)
        result = result + counter[i];

    printf("%d\n", result);
}

void calc_coins(int coin, int counter[4], int index)
{
    counter[index] = (change - (change % coin)) / coin;
    change = change - (counter[index] * coin);
}