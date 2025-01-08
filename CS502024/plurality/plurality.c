#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winners[candidate_count][2];
    winners[0][0] = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > winners[0][0])
        {
            winners[0][0] = candidates[j].votes; // Votes
            winners[0][1] = j;                   // Index
        }
        else if (candidates[j].votes == winners[0][0])
        {
            winners[j][0] = candidates[j].votes;
            winners[j][1] = j;
        }
    }

    printf("%s\n", candidates[winners[0][1]].name);
    for (int j = 1; j < candidate_count; j++)
    {
        if (winners[j][0] == winners[0][0])
        {
            printf("%s\n", candidates[winners[j][1]].name);
        }
    }
    return;
}
