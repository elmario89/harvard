// check50 cs50/2018/spring/mario/less => test it
// style50 mario.c => check the styles
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

    int b, c, d;
    for (b = 0; b < a; b = b + 1)
    {
        for (d = a - 1; d > b; d = d - 1)
        {
            printf(" ");
        }

        printf("#");
        for (c = -1; c < b; c = c + 1)
        {
            printf("#");
        }
        printf("\n");
    }
}