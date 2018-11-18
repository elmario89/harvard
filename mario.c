#include <cs50.h>
#include <stdio.h>

int main()
{
    printf("Enter pyramide height: \n");
    int a = get_int();

    while ((a < 0) || (a > 23))
    {
        printf("Positive and not greater than 23 please: \n");
        a = get_int();
    }

    int b = 0;
    while (b < a)
    {
        int c = 0;
        int d = a - (b + 1);

        while (d != 0)
        {
            printf(" ");
            d--;
        }

        printf("#");

        while (b >= c)
        {
            printf("#");
            c++;
        }
        printf("\n");
        b++;
    }
}