#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int points_count, total_points;


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%i", score1);
    printf("%i", score2);

    // Print out the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score1 < score2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    total_points = 0;

    int i = 0;
    while(word[i] != '\0') {

       if(word[i] < 123 && word[i] > 96) {
        points_count = word[i] - 97;

        total_points = total_points+POINTS[points_count];
        i++;
       }
        else if (word[i] < 91 && word[i] > 64) {
        points_count = word[i] - 65;

        total_points = total_points+POINTS[points_count];
        i++;
       }
       else {
        return total_points;
       }
    }
    return total_points;
}
