// check50 cs50/2017/ap/greedy => use this to test
#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_cents(float n);
void print_amount_of_coins(float dimes, float quarters, float pennies, float nickels);

int main()
{
    float change;
    int change_in_cents;
    int dime = 25, quarter = 10, penny = 5, nickel = 1;
    float dime_counter = 0, quarter_counter = 0, penny_counter = 0, nickel_counter = 0;

    printf("Enter change to give back:\n");

    do
    {
        change = get_float();
    }
    while (change < 0);

    change_in_cents = get_cents(change);

    if (change_in_cents >= dime)
    {
        if (change_in_cents == dime)
        {
            dime_counter = 1;
            print_amount_of_coins(dime_counter, quarter_counter, penny_counter, nickel_counter);
            return 0;
        }
        else
        {
            dime_counter = (change_in_cents - (change_in_cents % dime)) / dime;
            change_in_cents = change_in_cents - (dime_counter * dime);
        }
    }

    if (change_in_cents >= quarter)
    {
        if (change_in_cents == quarter)
        {
            quarter_counter = 1;
            print_amount_of_coins(dime_counter, quarter_counter, penny_counter, nickel_counter);
            return 0;
        }
        else
        {
            quarter_counter = (change_in_cents - (change_in_cents % quarter)) / quarter;
            change_in_cents = change_in_cents - (quarter_counter * quarter);
        }
    }

    if (change_in_cents >= penny)
    {
        if (change_in_cents == penny)
        {
            penny_counter = 1;
            print_amount_of_coins(dime_counter, quarter_counter, penny_counter, nickel_counter);
            return 0;
        }
        else
        {
            penny_counter = (change_in_cents - (change_in_cents % penny)) / penny;
            change_in_cents = change_in_cents - (quarter_counter * penny);
        }
    }

    if (change_in_cents >= nickel)
    {
        if (change_in_cents == nickel)
        {
            nickel_counter = 1;
            print_amount_of_coins(dime_counter, quarter_counter, penny_counter, nickel_counter);
            return 0;
        }
        else
        {
            nickel_counter = (change_in_cents - (change_in_cents % nickel)) / nickel;
            change_in_cents = change_in_cents - (nickel_counter * nickel);
        }
    }

    print_amount_of_coins(dime_counter, quarter_counter, penny_counter, nickel_counter);
}

float get_cents(float n)
{
    return roundf(n * 100.0);
}

void print_amount_of_coins(float dimes, float quarters, float pennies, float nickels)
{
    printf("%.0f\n", dimes + quarters + pennies + nickels);
}
