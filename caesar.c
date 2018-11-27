// check50 cs50/2017/ap/caesar
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void accumulate_ascii_array(int, int array[26]);
void print_ciphered_letter(int offset, int key, int letter_in_bytes);
int ascii_upper_array[26];
int ascii_lower_array[26];

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter the security key!\n");
        return 1;
    }

    char *p;
    int key = strtol(argv[1], &p, 10);

    accumulate_ascii_array(65, ascii_upper_array);
    accumulate_ascii_array(97, ascii_lower_array);

    printf("Print your message please: \n");
    string s = get_string();
    int length = strlen(s);

    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        if (s[i] < 97)
        {
            print_ciphered_letter(64, key, s[i]);
        }
        else
        {
            print_ciphered_letter(96, key, s[i]);
        }
    }
    printf("\n");
}

void accumulate_ascii_array(int offset, int array[26])
{
    for (int i = 0; i < 26; i++)
    {
        array[i] = i + offset;
    }
}

void print_ciphered_letter(int offset, int key, int letter_in_bytes)
{
    if (letter_in_bytes != 32)
    {
        printf("%c", (char) (letter_in_bytes + key - offset) % 26 + offset);
    }
    else
    {
        printf(" ");
    }
}