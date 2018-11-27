// check50 cs50/2017/ap/caesar
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter the security key!\n");
        return 1;
    }

    char *p;
    int key = strtol(argv[1], &p, 10);

    printf("Print your message please: \n");
    string s = get_string();
    int length = strlen(s);

    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        if (s[i] < 97)
        {
            printf("%c", (char) (s[i] + key - 64) % 26 + 64);
        }
        else
        {
            printf("%c", (char) (s[i] + key - 96) % 26 + 96);
        }
    }
    printf("\n");
}
