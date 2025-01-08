#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

float averageBy100(int a, int b);

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sent = 0;
    float CLI = 0;
    int grade;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sent++;
        }
    }
    words++;
    CLI = 0.0588 * averageBy100(letters, words) - 0.296 * averageBy100(sent, words) - 15.8;
    grade = round(CLI);
    if (CLI < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (CLI > 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %i\n", grade);
    return 0;
}

float averageBy100(int a, int b)
{
    return 100.0 * a / b;
}
