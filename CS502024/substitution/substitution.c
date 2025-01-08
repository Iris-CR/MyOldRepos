#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    char letters[26][26] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                             'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                            {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                             '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}};
    string plainTxt;
    string cipherTxt;

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                return 1;
            }
            if (letters[1][toupper(argv[1][i]) - 65] != '0')
            {
                return 1;
            }
            else
            {
                letters[1][toupper(argv[1][i]) - 65] = argv[1][i];
            }
        }
    }

    plainTxt = get_string("plaintext:  ");
    cipherTxt = plainTxt;
    for (int i = 0; plainTxt[i] != '\0'; i++)
    {
        if (isalpha(plainTxt[i]))
        {
            if (isupper(plainTxt[i]))
            {
                cipherTxt[i] = toupper(argv[1][plainTxt[i] - 65]);
            }
            else
                cipherTxt[i] = tolower(argv[1][plainTxt[i] - 97]);
        }
        else
            cipherTxt[i] = plainTxt[i];
    }
    printf("ciphertext: %s\n", cipherTxt);
    return 0;
}
