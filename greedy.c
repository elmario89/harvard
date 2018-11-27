// check50 cs50/2017/ap/greedy => use this to test
#include <cs50.h>
#include <stdio.h>
#include <math.h>

void get_cents(float n);
int change_in_cents;
void print_amount_of_coins(int counter[4]);
void calc_coins(int coin, int counter[4], int index);

int main()
{
    float change;
    int coins[4] = {25, 10, 5, 1};
    int coins_counter[4] = {0, 0, 0, 0};

    printf("Enter change to give back:\n");

    do
    {
        change = get_float();
    }
    while (change < 0);

    get_cents(change);

    for (int i = 0; i < 4; i++)
    {
        calc_coins(coins[i], coins_counter, i);
    }

    print_amount_of_coins(coins_counter);
}

void get_cents(float n)
{
    change_in_cents = roundf(n * 100.0);
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
    counter[index] = (change_in_cents - (change_in_cents % coin)) / coin;
    change_in_cents = change_in_cents - (counter[index] * coin);
}