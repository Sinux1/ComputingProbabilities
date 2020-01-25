#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant values defined
#define SEVEN 7
#define ELEVEN 11
#define SNAKE_EYES 2
#define TRIALS 100
#define LOSS -1
#define SIDES 6

// This function simulates a single 7 sided die being rolled
int rollDie()
{
    // Returns values between 1 and 7
    return (rand() % SIDES) + 1;
}

// playGame takes the point as an argument and simulates 
// rolling the dice until a win or loss is achieved, returning the 
// number of rolls for a win, or -1 for a loss
// PLAYGAME() MUST BE REWRITTEN
// DOES NOT RETURN 2 WHEN SECOND ROLL WINS

/*
int playGame(int sentinel)
{
    int rolls = 1;
    int value_rolled = rollDie() + rollDie();
    int playing = 1;
    while(playing)
    {
        if (value_rolled == SEVEN || value_rolled == ELEVEN || value_rolled == SNAKE_EYES)
        {
            printf("LOSS\n");
            return LOSS;
        }
        rolls++;
        value_rolled = rollDie() + rollDie();
        printf("Roll #%d:%d \n", rolls, value_rolled);
    }
    printf("WIN\n");
    return rolls;
}
*/

// updateAverage takes the number of rools needed for the curent win, 
// the previous number of winning games, and the average in need of 
// updating as arguments, and returns the up to date average
int updateAverage(float rolls, float wins, float previous_avg)
{
    printf("Rolls: %f\t\tWins: %f\t\tPrevious average: %f\t\t\n", rolls, wins, previous_avg);
    return (((previous_avg * wins) + rolls) / (wins + 1));
}


int main()
{
    // Seed the rand() function
    srand(time(NULL));
    // point is the winning number.
    int point;
    // The number of rolls for a winning run
    int number_of_rolls;
    // This is the running average
    float avg_rolls_per_win = 0;
    // Number of winning runs
    int number_of_wins = 0;
    // This will iterate until the specified number of winning runs
    // aer attained
    while(number_of_wins < TRIALS)
    {
        printf("Number of wins: %d\n", number_of_wins);
        // Determine the point on the first roll
        point = rollDie() + rollDie();
        number_of_rolls = 1;
        printf("point: %d\n", point);
        // For a point that is not an instant win or loss...
        if(point != SEVEN && point != ELEVEN && point != SNAKE_EYES)
        {
            // Point is not an instant winner or loser then continue playing the game
            number_of_rolls = playGame(point);
            // Check win/loss
            if(number_of_rolls == LOSS)
            {
                // Losses are of no interest
                continue;
            }
            else
            {
                // Update the current average with the new values from the winning run 
                avg_rolls_per_win = updateAverage(number_of_rolls, number_of_wins, avg_rolls_per_win);
                // Increment the number of wins
                number_of_wins++;
            }
        }// For apoint that is an instant win
        else if(point == SEVEN || point == ELEVEN)
        {
            // Update the current average with the new values from the winning run  
            avg_rolls_per_win = updateAverage(number_of_rolls, number_of_wins, avg_rolls_per_win);
            number_of_wins++;
        }
        
    }
    // Present results
    printf("After %d winning runs,\nThe average number of rolls in a winning craps run is: %f", TRIALS, avg_rolls_per_win);
}
