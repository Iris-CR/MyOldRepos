#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int scores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int plScore[2] = {0, 0};
    string pl1 = get_string("Player 1: ");
    string pl2 = get_string("Player 2: ");
    for (int i = 0, j = strlen(pl1); i < j; i++)
    {
        pl1[i] = toupper(pl1[i]);
        if (pl1[i] > 64 && pl1[i] < 91)
        {
            plScore[0] += scores[pl1[i] - 65];
        }
    }
    for (int i = 0, j = strlen(pl2); i < j; i++)
    {
        pl2[i] = toupper(pl2[i]);
        if (pl2[i] > 64 && pl2[i] < 91)
        {
            plScore[1] += scores[pl2[i] - 65];
        }
    }
    if (plScore[0] > plScore[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (plScore[0] < plScore[1])
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
    return 0;
}
