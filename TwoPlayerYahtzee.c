//
//  Final Project - Yahtzee.c
//  Purpose: to perform a two person game of yahtzee while displaying scores and dice rolls
//  Authors: Aspen Clements and Austin Ryan
//  Date Modified: 4/29/15.
//
//  Begin Program - this program will begin and display the rules once
//  Display Rules
//  (ROLL 1)
//  Player 1 rolls 5 dice of values 1 through 6
//  Conditions are set to correctly set values to each current scoring option
//  A scoresheet graphic is displayed below the dice graphic showing current score options and your permanent scores
//  Player 1 is given the option to end your turn and choose a current score as your permanent score, or reroll certain dice.
//      If player chooses to end turn, you must choose a permanent scoring option that has not already been chosen
//      BREAK TO PLAYER TWO'S FIRST ROLL
//      (ROLL 2)
//      If player 1 rerolls (FIRST REROLL) the player will reroll the chosen specific dice
//          When dice are rerolled, the new randomly rolled values of dice are displayed in a graphic and new current score options are calculated and displayed below the second roll.
//          Player 1 is given the option to end your turn and choose a current score as your permanent score, or reroll once more
//              If player chooses to end turn, you must choose a permanent scoring option that has not already been chosen
//              BREAK TO PLAYER TWO'S FIRST ROLL
//              (ROLL 3)
//              If player 1 rerolls (SECOND AND LAST REROLL) the player will reroll the chosen specific dice
//              When dice are rerolled, the new randomly rolled values of dice are displayed in a graphic and new current score options are calculated and displayed below the third roll.
//                  Player 1 now MUST choose a permanent scoring option that has not already been chosen
//                  PLAYER TWO BEINGS THEIR TURN
//  Player 2's turn is exactly the same, but provides different permanent score values.
//  Provide a loop that loops 13 times for both player 1 and player 2 so that all permanent scores are set for each player.
//  After the all turns are finished (loop is finished), add up the total sum of ones, twos, threes, fours, fives, and sixes score
//      if that score is greater than or equal to 63, add a bonus of 35 to the total score
//  calculate a total score for each player by adding up all permanent scores for each player
//  display final scorecards for each player with sum, bonus, and total.
//  display a graphic that tells who won the game and the final total scores for each player.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void DisplayRules();
void PrintDiceAndScore();
void ReRoll();
void ScoreCard();
void ScoreCardFinal(); 
void PrintDicePlayerTwo();
void PrintDiceAndScorePlayerTwo();
void ReRollPlayerTwo();
void ScoreCardPlayerTwo();
void ScoreCardFinalPlayerTwo();
void PointAllocation();
void PointAllocation_PlayerTwo();
void Results();


#define numPossibleRolls 6
# define maxNumTurns 12
# define Entries 5

int entry, roll[Entries], sumOfDice = 0;
int ones_score, perm_ones_score = -1 , twos_score, perm_twos_score = -1, threes_score, perm_threes_score = -1, fours_score, perm_fours_score = -1, fives_score, perm_fives_score = -1;
int sixes_score, perm_sixes_score = -1, threeOfAKind_score, perm_threeOfAKind_Score = -1, fourOfAKind_score, perm_fourOfAKind_score = -1, yahtzee_score, perm_yahtzee_Score = -1, fullHouse1, fullHouse2;
int fullHouse_score, perm_fullHouse_score = -1, smallStraight_score, perm_smallStraight_score = -1, largeStraight_score, perm_largeStraight_score = -1;
int entry = 0;
int ones_score = 0, twos_score = 0, threes_score = 0, fours_score = 0, fives_score = 0, sixes_score = 0, fullHouse1 = 0, fullHouse2 = 0, fullHouse_score = 0;
int threeOfAKind_score = 0, fourOfAKind_score =0, smallStraight_score = 0, largeStraight_score = 0, yahtzee_score = 0;
int bonus_score = 0, chance_score = 0, perm_chance_score = -1, total_score = 0, num_turns =0;
int sum_score, numDiceChange, dieChange, changingDice, allocation_command = 0;
char command, display0, display1, display2, display3;
int sum, total, bonus;
int perm_ones_score_player_two = -1, perm_twos_score_player_two = -1, perm_threes_score_player_two = -1, perm_fours_score_player_two = -1, perm_fives_score_player_two = -1;
int perm_sixes_score_player_two = -1, perm_threeOfAKind_score_player_two = -1, perm_fourOfAKind_score_player_two = -1, perm_smallStraight_score_player_two = -1;
int perm_largeStraight_score_player_two = -1, perm_fullHouse_score_player_two = -1, perm_chance_score_player_two = -1, perm_yahtzee_score_player_two = -1;
int sum_player_two, total_player_two, bonus_player_two, num_roll = 0;

int main(void)
{
    DisplayRules();
    srand(time(NULL));
    
    for(num_turns = 0; num_turns <= maxNumTurns; num_turns ++)
    {
        for(entry = 0; entry < Entries; entry++) //initilizing array entries to randomly selected values 1 to 5
        {
            roll[entry] = rand()% numPossibleRolls + 1;
            sumOfDice = sumOfDice + roll[entry];
        }
        PrintDiceAndScore();
        
        printf("\n\nWould you like to finish your turn or roll a number of dice again? The commands are listed below. Please enter the corresponding letter to continue.");
        ReRoll();
        
        if(command != 'a')
        {
            printf("\nYou are allowed to roll the dice one more time for this turn. What would you like to do?");
            ReRoll();
        }
        
        PointAllocation();
        
        /////////////////////////////////////////////////////////////////////// PLAYER TWO/////////////////////////////////////////////////////////////////////////////////
        for(entry = 0; entry < Entries; entry++)
        {
            roll[entry] = rand()% numPossibleRolls + 1;
            sumOfDice = sumOfDice + roll[entry];
        }
        
        PrintDiceAndScorePlayerTwo();
        
        printf("\n\nWould you like to finish your turn or reroll some number of dice? \n");
        printf("\nThe commands are listed below. Please enter the corresponding letter to continue.");
        ReRollPlayerTwo();
        
        if(command != 'a')
        {
            printf("\nYou are allowed to roll the dice one more time for this turn. What would you like to do?");
            ReRollPlayerTwo();
        }
        
        PointAllocation_PlayerTwo();
            
    }
    ScoreCardFinal();
    ScoreCardFinalPlayerTwo();
    Results();
}

///////////////////////////////////////////////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////////////////////////////////////

void DisplayRules()
{
    printf("\n                       WELCOME TO YAHTZEE!"); // INTRO with rules
    printf("\n\n                          INSTRUCTIONS");
    printf("\n\n                         ****OBJECT****");
    printf("\n\nRoll dice for scoring combinations and get the highest total score");
    printf("\n\n                       ****HOW TO PLAY****");
    printf("\n\nOn your turn, you may roll the dice up to three times,");
    printf("\nalthough you may stop and score after your first or");
    printf("\nsecond roll. Your first roll is rolled for you.");
    printf("\n\nFirst roll: 5 dice are rolled for you. You may choose to");
    printf("\nreroll ANY or ALL dice, or choose to end your turn and");
    printf("\nchoose a score.");
    printf("\n\nSecond roll: You may stop and score here, or reroll ANY or ALL dice");
    printf("\nthat you choose.");
    printf("\n\nThird roll: You MUST choose to score once you have rolled three times.");
    printf("\n\n                          ****SCORING****");
    printf("\n\nThere are thirteen different scoring options, which will be");
    printf("\nautomatically calculated for you when you roll and");
    printf("\nwill be displayed in the current roll section of your score card.");
    printf("\nYou can only choose each scoring option once.");
    printf("\n\nUPPER SECTION");
    printf("\n\nOnes: Total of ones rolled");
    printf("\nTwos: Total of twos rolled");
    printf("\nThrees: Total of threes rolled");
    printf("\nFours: Total of fours rolled");
    printf("\nFives: Total of fives rolled");
    printf("\nSixes: TOtal of sixes rolled");
    printf("\n\nExample: Rolling 3 Sixes = a score of 18.");
    printf("\n\nLOWER SECTION");
    printf("\n\n3 of a kind - If dice include 3 or more of the same number, your score is the total of your five dice");
    printf("\n4 of a kind - If dice include 4 or more of the same number, your score is the total of your five dice.");
    printf("\nFull House - If dice show three of one number and two of another, you can score 25 points");
    printf("\nSmall Straight - If there is a sequence of four numbers, you can score 30 points.");
    printf("\nLarge straight - If there is a sequence of five numbers, you can score 40 points");
    printf("\nYahtzee - If dice include 5 of the same number, your can score 50 points.");
    printf("\n\nIf conditions are not met for any of these score options, the score is zero.");
    printf("\n\nChance - Total of all of your 5 dice, no conditions need to be met.");
    printf("\n\n                      ****ENDING A GAME*****");
    printf("\n\nAfter each player has filled in all 13 scoring option boxes, the game ends.");
    printf("\nYour final score card is now displayed, and the winner is the player with");
    printf("\nthe highest total score.");
    printf("\n\nThe sum section is the total number of ones, twos, threes, fours, fives, and sixes.");
    printf("\nIf the sum is greater to or equal to 63, a bonus of 35 points is added to your total.");
    printf("\nIf the sum is less than 63, the bonus is zero.");
    printf("\n\nThe total section is the total of all 13 scoring options plus the bonus.\n\n");
}

void PrintDiceAndScore()
{
    entry = 0;
    ones_score = 0, twos_score = 0, threes_score = 0, fours_score = 0, fives_score = 0, sixes_score = 0, fullHouse1 = 0, fullHouse2 = 0, fullHouse_score = 0, chance_score = 0;
    threeOfAKind_score = 0, fourOfAKind_score =0, smallStraight_score = 0, largeStraight_score = 0, yahtzee_score = 0, sumOfDice = 0;
    
    char display0[100]={'\0'};// first  line of full display
    char display1[100]={'\0'};// second line of full display
    char display2[100]={'\0'};// third  line of full display
    char display3[100]={'\0'};// fourth line of full display
    
    char digit_0_0[12] = " __ ___ __ "; //setting display for each die face
    char digit_0_1[12] = " |       | ";
    char digit_0_2[12] = " |   *   | ";
    char digit_0_3[12] = " |_ ___ _| ";
    
    char digit_1_0[12] = " __ ___ __ ";
    char digit_1_1[12] = " | *     | ";
    char digit_1_2[12] = " |       | ";
    char digit_1_3[12] = " |_ ___*_| ";
    
    char digit_2_0[12] = " __ ___ __ ";
    char digit_2_1[12] = " | *     | ";
    char digit_2_2[12] = " |   *   | ";
    char digit_2_3[12] = " |_ ___*_| ";
    
    
    char digit_3_0[12] = " __ ___ __ ";
    char digit_3_1[12] = " | *   * | ";
    char digit_3_2[12] = " |       | ";
    char digit_3_3[12] = " |_*___*_| ";
    
    
    char digit_4_0[12] = " __ ___ __ ";
    char digit_4_1[12] = " | *   * | ";
    char digit_4_2[12] = " |   *   | ";
    char digit_4_3[12] = " |_*___*_| ";
    
    char digit_5_0[12] = " __ ___ __ ";
    char digit_5_1[12] = " | *   * | ";
    char digit_5_2[12] = " | *   * | ";
    char digit_5_3[12] = " |_* __*_| ";
    
    for(entry = 0; entry < 5; entry++)
    {
        sumOfDice = sumOfDice + roll[entry];
        
        switch(roll[entry])
        {
            case 1:
                
                strcat(display0, digit_0_0); //print die face
                strcat(display1, digit_0_1);
                strcat(display2, digit_0_2);
                strcat(display3, digit_0_3);
                ones_score = ones_score + 1;
                if(ones_score == 2) //to check for full house and two of a kind
                {
                    if(twos_score == 6 || threes_score == 9  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(ones_score == 3) // to check for full house and three of a kind
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(twos_score == 4 || threes_score == 6  || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1; //to make sure we do not have false poitives with three of a kind
                }
                if(ones_score == 4) //check for of a kind
                    fourOfAKind_score = sumOfDice;
                if(ones_score == 5) //yahtzee check
                    yahtzee_score = 50;
                break;
                
            case 2:
                strcat(display0, digit_1_0); //display die face
                strcat(display1, digit_1_1);
                strcat(display2, digit_1_2);
                strcat(display3, digit_1_3);
                twos_score = twos_score + 2;
                
                if(twos_score == 4) //two of a kind or full house check
                {
                    if(ones_score == 3 || threes_score == 9  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(twos_score == 6) // three of a kind or full house check
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || threes_score == 6  || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(twos_score == 8) //four of a kind checl
                    fourOfAKind_score = sumOfDice;
                if(twos_score == 10) //yahtzee check
                    yahtzee_score = 50;
                break;
                
            case 3:
                strcat(display0, digit_2_0); //display die face
                strcat(display1, digit_2_1);
                strcat(display2, digit_2_2);
                strcat(display3, digit_2_3);
                threes_score = threes_score + 3;
                
                if(threes_score == 6) //two of a kind or full house check
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(threes_score == 9) //three of a kind or full house check
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(threes_score == 12) // four of a kind check
                    fourOfAKind_score = sumOfDice;
                if(threes_score == 15) //yahtzee check
                    yahtzee_score = 50;
                break;
                
            case 4:
                strcat(display0, digit_3_0); //display face of die
                strcat(display1, digit_3_1);
                strcat(display2, digit_3_2);
                strcat(display3, digit_3_3);
                fours_score = fours_score + 4;
                
                if(fours_score == 8) //two of a kind or full house check
                {
                    if(ones_score == 3 || twos_score == 6  || threes_score == 9 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(fours_score == 12) //three of a kind or full house check
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fives_score == 10 || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(fours_score == 16) //four of a kind check
                    fourOfAKind_score = sumOfDice;
                if(fours_score == 20) //yahtzee check
                    yahtzee_score = 50;
                break;
                
            case 5:
                strcat(display0, digit_4_0); //display die face
                strcat(display1, digit_4_1);
                strcat(display2, digit_4_2);
                strcat(display3, digit_4_3);
                fives_score = fives_score + 5;
                
                if(fives_score == 10) //two of a kind or full house check
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || threes_score == 9  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(fives_score == 15) //three of a kind or full house check
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fours_score == 8 || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(fives_score == 20) //four of a kind
                    fourOfAKind_score = sumOfDice;
                if(fives_score == 25) //yahtzee
                    yahtzee_score = 50;
                break;
                
            case 6:
                strcat(display0, digit_5_0); //display die face
                strcat(display1, digit_5_1);
                strcat(display2, digit_5_2);
                strcat(display3, digit_5_3);
                sixes_score = sixes_score + 6;
                
                if(sixes_score == 12) //two of a kind or full house check
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || fives_score == 15  || threes_score == 9)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(sixes_score == 18) //three of a kind or full house check
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fours_score == 8 || fives_score == 10)
                        fullHouse1 = 1;
                }
                if(sixes_score == 24) //four of a kind
                    fourOfAKind_score = sumOfDice;
                if(sixes_score == 30) //yahtzee
                    yahtzee_score = 50;
                break;
        }
    
        
        // large straight if statements
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            largeStraight_score = 40;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            largeStraight_score = 40;
        }
        //***small straight if statements***
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 2 && twos_score == 2 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 4 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 6 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 8)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 4 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 6 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 8 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 10)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 6 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 8 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 10 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 12)
        {
            smallStraight_score = 30;
        }
        
    }
    printf("%s\n",display0); //printing die
    printf("%s\n",display1);
    printf("%s\n",display2);
    printf("%s\n",display3);
    
    //chance check
    for(entry = 0; entry < 5; entry++)
    {
        chance_score = chance_score + roll[entry];
    }
    if(fullHouse1 == 1 && fullHouse2 == 1)
        fullHouse_score = 25;
    
    ScoreCard();

}

void ReRoll()
{

    int loop_command = 1, loop2;
    
    while(loop_command > 0)
    {
        printf("\n Command    Meaning ");
        printf("\n    a       Finish Roll");
        printf("\n    b       Roll some number of dice");
        printf("\n    c       Exit the program all together\n");
        printf("\n\n Please enter the option you would like.");
        scanf("%c", &command);
        
        switch(command)
        {
            case'a':
                loop_command = -1; //exit loop
                break;
            case'b':
                printf("How many die would you like to change (1 through 5)? Please enter that number now.");
                loop2 = 1;
                while (loop2 > 0) //to ensure invalid entries do not pass
                {
                    scanf("%i", &numDiceChange);
                    while(getchar() != '\n') {}
                    if (numDiceChange > 0 && numDiceChange < 6)
                        loop2 = -1;
                    else
                    {
                        printf("This is an invalid entry. Please enter a valid entry.");
                    }
                }
                printf("\nPlease enter the dice you would like to reroll. For example if you want to reroll the second and fifth die that appeared enter 2 5 then press enter.");
                printf("\nThe number of die is from left to right. The dice number must be seperated by a space.");
                
                for(changingDice = 0; changingDice < numDiceChange; changingDice ++)
                {
                    scanf("\n%i", &dieChange);
                    switch(dieChange) //changing entries randomly
                    {
                        case(1):
                            roll[0] = rand()% numPossibleRolls + 1;
                            break;
                        case(2):
                            roll[1] = rand()% numPossibleRolls + 1;
                            break;
                        case(3):
                            roll[2] = rand()% numPossibleRolls + 1;
                            break;
                        case(4):
                            roll[3] = rand()% numPossibleRolls + 1;
                            break;
                        case(5):
                            roll[4] = rand()% numPossibleRolls + 1;
                            break;
                            
                    }
                    dieChange = 0;
                }
                printf("\nYour new dice and scoresheet are \n");
                PrintDiceAndScore();
                loop_command = -1;
                break;
            case'c':
                printf("\nThank you for playing. The program in now terminating. \n\n");
                exit(0);
                break;
            default:
                printf("\n Error. You must enter a, b, or c. Please enter a valid command.");
                break;
        
        }
    }
    while(getchar() != '\n') {}
}


void ScoreCard() 
{
    printf("\n___________________________________________________________");
    printf("\n                   SCORECARD - PLAYER 1                    ");
    printf("\n___________________________________________________________");
    printf("\n                       Current Roll            Score       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Ones                       %i        ", ones_score);
    
    if(perm_ones_score >= 0) //when print score only when that score has been selected
           printf("            %i         ", perm_ones_score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Twos                       %i         ", twos_score);
           
    if(perm_twos_score >= 0)
           printf("           %i         ", perm_twos_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Threes                     %i         ", threes_score);
          
    if(perm_threes_score >= 0)
          printf("           %i         ", perm_threes_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fours                      %i           ", fours_score);
           
    if(perm_fours_score >= 0)
           printf("         %i         ", perm_fours_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fives                      %i           ", fives_score);
    
    if(perm_fives_score >= 0)
           printf("         %i         ", perm_fives_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Sixes                      %i         ", sixes_score);
    
    if(perm_sixes_score >= 0)
           printf("           %i         ", perm_sixes_score);
    printf("\n***********************************************************");
    printf("\n Sum                                                       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Bonus                                                     ");
    printf("\n***********************************************************");
    printf("\n Three of a kind            %i         ", threeOfAKind_score);
    
    if(perm_threeOfAKind_Score >= 0)
           printf("           %i         ", perm_threeOfAKind_Score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Four of a kind             %i          ", fourOfAKind_score);
    
    if(perm_fourOfAKind_score >= 0)
           printf("          %i         ", perm_fourOfAKind_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Full House                 %i         ", fullHouse_score);
    
    if(perm_fullHouse_score >= 0)
           printf("           %i         ", perm_fullHouse_score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Small straight             %i         ", smallStraight_score);
    
    if(perm_smallStraight_score >= 0)
           printf("           %i         ", perm_smallStraight_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Large straight             %i         ", largeStraight_score);
    
    if(perm_largeStraight_score >= 0)
           printf("           %i         ", perm_largeStraight_score);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Chance                     %i          ", chance_score);
    
    if(perm_chance_score >= 0)
           printf("         %i         ", perm_chance_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n YAHTZHEE                   %i           ", yahtzee_score);
           
    if(perm_yahtzee_Score >= 0)
           printf("         %i         ", perm_yahtzee_Score);
    printf("\n*******************|***************************************");
    printf("\n TOTAL SCORE                                               ");
    printf("\n___________________|___________________|___________________\n");
}

void PointAllocation()
{
    int loop_command = 1;
    
    while(loop_command > 0) //ensure a valid entry is inputted
    {
        printf("\n\n Where would you like your points to be allocated? To select your choice enter the command from the command list below");
        printf("\n Command    Points to ");
        printf("\n    1       Ones");
        printf("\n    2       Twos");
        printf("\n    3       Threes");
        printf("\n    4       Fours");
        printf("\n    5       Fives");
        printf("\n    6       Sixes");
        printf("\n    7       Three of a kind");
        printf("\n    8       Four of a kind");
        printf("\n    9       Full House");
        printf("\n    10      Small Straight");
        printf("\n    11      Large Straight");
        printf("\n    12      Chance");
        printf("\n    13      Yahtzee\n");
        
        scanf("%d", &allocation_command);
        while(getchar() != '\n') {}
        switch (allocation_command)
        {
            case 1:
                if(perm_ones_score == -1)//to ensure score hasnt already been set
                {
                    perm_ones_score = ones_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 2:
                if(perm_twos_score == -1) //to ensure score hasnt already been set
                {
                    perm_twos_score = twos_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 3:
                if(perm_threes_score == -1) //to ensure score hasnt already been set
                {
                    perm_threes_score = threes_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                allocation_command = -1;
                break;
            case 4:
                if(perm_fours_score == -1) //to ensure score hasnt already been set
                {
                    perm_fours_score = fours_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                
                break;
            case 5:
                if(perm_fives_score == -1) //to ensure score hasnt already been set
                {
                    perm_fives_score = fives_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 6:
                if(perm_sixes_score == -1) //to ensure score hasnt already been set
                {
                    perm_sixes_score = sixes_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 7:
                if(perm_threeOfAKind_Score == -1) //to ensure score hasnt already been set
                {
                    perm_threeOfAKind_Score = threeOfAKind_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 8:
                if(perm_fourOfAKind_score == -1) //to ensure score hasnt already been set
                {
                    perm_fourOfAKind_score = fourOfAKind_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 9:
                if(perm_fullHouse_score == -1) //to ensure score hasnt already been set
                {
                    perm_fullHouse_score = fullHouse_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 10:
                if(perm_smallStraight_score == -1) //to ensure score hasnt already been set
                {
                    perm_smallStraight_score = smallStraight_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 11:
                if(perm_largeStraight_score == -1) //to ensure score hasnt already been set
                {
                    perm_largeStraight_score = largeStraight_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 12:
                if(perm_chance_score == -1) //to ensure score hasnt already been set
                {
                    perm_chance_score = chance_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 13:
                if(perm_yahtzee_Score == -1) //to ensure score hasnt already been set
                {
                    perm_yahtzee_Score = yahtzee_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
                
                
        }
    }
}

void ScoreCardFinal()
{
    sum = perm_ones_score + perm_twos_score + perm_threes_score + perm_fours_score + perm_fives_score + perm_sixes_score;
    printf("\n___________________________________________________________");
    printf("\n                   SCORECARD - PLAYER 1                    ");
    printf("\n___________________________________________________________");
    printf("\n                       Current Roll            Score       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Ones                       %i        ", ones_score);
    
    if(perm_ones_score >= 0) //print only set scores
           printf("            %i         ", perm_ones_score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Twos                       %i         ", twos_score);
    
    if(perm_twos_score >= 0)
           printf("           %i         ", perm_twos_score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Threes                     %i         ", threes_score);
    
    if(perm_threes_score >= 0)
          printf("           %i         ", perm_threes_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fours                      %i           ", fours_score);
           
    if(perm_fours_score >= 0)
           printf("         %i         ", perm_fours_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fives                      %i           ", fives_score);
    
    if(perm_fives_score >= 0)
           printf("         %i         ", perm_fives_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Sixes                      %i         ", sixes_score);
    
    if(perm_sixes_score >= 0)
           printf("           %i         ", perm_sixes_score);
    printf("\n***********************************************************");
    printf("\n Sum               |                   |         %i         ", sum);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Bonus             |                             ");
    
    if(sum >= 63)
    {
           bonus = 35; // bonus score only applies when all number scores sum up to more than 63
           printf("     %i ", bonus);
    }
    else
    printf("0");
           
    printf("\n***********************************************************");
    printf("\n Three of a kind            %i         ", threeOfAKind_score);
    
    if(perm_threeOfAKind_Score >= 0)
           printf("           %i         ", perm_threeOfAKind_Score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Four of a kind             %i          ", fourOfAKind_score);
    
    if(perm_fourOfAKind_score >= 0)
           printf("          %i         ", perm_fourOfAKind_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Full House                 %i         ", fullHouse_score);
    
    if(perm_fullHouse_score >= 0)
           printf("           %i         ", perm_fullHouse_score);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Small straight             %i         ", smallStraight_score);
    
    if(perm_smallStraight_score >= 0)
           printf("           %i         ", perm_smallStraight_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Large straight             %i         ", largeStraight_score);
    
    if(perm_largeStraight_score >= 0)
           printf("           %i         ", perm_largeStraight_score);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Chance                     %i          ", chance_score);
    
    if(perm_chance_score >= 0)
           printf("         %i         ", perm_chance_score);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n YAHTZHEE                   %i           ", yahtzee_score);
           
    if(perm_yahtzee_Score >= 0)
           printf("         %i         ", perm_yahtzee_Score);
    printf("\n*******************|***************************************");
    total = sum + bonus + perm_threeOfAKind_Score + perm_fourOfAKind_score + perm_fullHouse_score + perm_smallStraight_score + perm_largeStraight_score + perm_chance_score + perm_yahtzee_Score;
    printf("\n TOTAL SCORE                                    %i          ", total); //total score sumation
    printf("\n___________________|___________________|___________________\n");
}

void PrintDiceAndScorePlayerTwo() //same function as player one
{
    entry = 0;
    ones_score = 0, twos_score = 0, threes_score = 0, fours_score = 0, fives_score = 0, sixes_score = 0, fullHouse1 = 0, fullHouse2 = 0, fullHouse_score = 0, chance_score = 0;
    threeOfAKind_score = 0, fourOfAKind_score =0, smallStraight_score = 0, largeStraight_score = 0, yahtzee_score = 0, sumOfDice = 0;
    
    char display0[100]={'\0'};// first  line of full display
    char display1[100]={'\0'};// second line of full display
    char display2[100]={'\0'};// third  line of full display
    char display3[100]={'\0'};// fourth line of full display
    
    char digit_0_0[12] = " __ ___ __ ";
    char digit_0_1[12] = " |       | ";
    char digit_0_2[12] = " |   *   | ";
    char digit_0_3[12] = " |_ ___ _| ";
    
    char digit_1_0[12] = " __ ___ __ ";
    char digit_1_1[12] = " | *     | ";
    char digit_1_2[12] = " |       | ";
    char digit_1_3[12] = " |_ ___*_| ";
    
    char digit_2_0[12] = " __ ___ __ ";
    char digit_2_1[12] = " | *     | ";
    char digit_2_2[12] = " |   *   | ";
    char digit_2_3[12] = " |_ ___*_| ";
    
    
    char digit_3_0[12] = " __ ___ __ ";
    char digit_3_1[12] = " | *   * | ";
    char digit_3_2[12] = " |       | ";
    char digit_3_3[12] = " |_*___*_| ";
    
    
    char digit_4_0[12] = " __ ___ __ ";
    char digit_4_1[12] = " | *   * | ";
    char digit_4_2[12] = " |   *   | ";
    char digit_4_3[12] = " |_*___*_| ";
    
    char digit_5_0[12] = " __ ___ __ ";
    char digit_5_1[12] = " | *   * | ";
    char digit_5_2[12] = " | *   * | ";
    char digit_5_3[12] = " |_* __*_| ";
    
    for(entry = 0; entry < 5; entry++)
    {
            sumOfDice = sumOfDice + roll[entry];
        
        switch(roll[entry])
        {
            case 1:
                
                strcat(display0, digit_0_0);
                strcat(display1, digit_0_1);
                strcat(display2, digit_0_2);
                strcat(display3, digit_0_3);
                ones_score = ones_score + 1;
                if(ones_score == 2)
                {
                    if(twos_score == 6 || threes_score == 9  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(ones_score == 3)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(twos_score == 4 || threes_score == 6  || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1; //to make sure we do not have false poitives with three of a kind
                }
                if(ones_score == 4)
                    fourOfAKind_score = sumOfDice;
                if(ones_score == 5)
                    yahtzee_score = 50;
                break;
                
            case 2:
                strcat(display0, digit_1_0);
                strcat(display1, digit_1_1);
                strcat(display2, digit_1_2);
                strcat(display3, digit_1_3);
                twos_score = twos_score + 2;
                
                if(twos_score == 4)
                {
                    if(ones_score == 3 || threes_score == 9  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(twos_score == 6)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || threes_score == 6  || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(twos_score == 8)
                    fourOfAKind_score = sumOfDice;
                if(twos_score == 10)
                    yahtzee_score = 50;
                break;
                
            case 3:
                strcat(display0, digit_2_0);
                strcat(display1, digit_2_1);
                strcat(display2, digit_2_2);
                strcat(display3, digit_2_3);
                threes_score = threes_score + 3;
                
                if(threes_score == 6)
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(threes_score == 9)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || fours_score == 8 || fives_score == 10  || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(threes_score == 12)
                    fourOfAKind_score = sumOfDice;
                if(threes_score == 15)
                    yahtzee_score = 50;
                break;
                
            case 4:
                strcat(display0, digit_3_0);
                strcat(display1, digit_3_1);
                strcat(display2, digit_3_2);
                strcat(display3, digit_3_3);
                fours_score = fours_score + 4;
                
                if(fours_score == 8)
                {
                    if(ones_score == 3 || twos_score == 6  || threes_score == 9 || fives_score == 15  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(fours_score == 12)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fives_score == 10 || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(fours_score == 16)
                    fourOfAKind_score = sumOfDice;
                if(fours_score == 20)
                    yahtzee_score = 50;
                break;
                
            case 5:
                strcat(display0, digit_4_0);
                strcat(display1, digit_4_1);
                strcat(display2, digit_4_2);
                strcat(display3, digit_4_3);
                fives_score = fives_score + 5;
                
                if(fives_score == 10)
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || threes_score == 9  || sixes_score == 18)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(fives_score == 15)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fours_score == 8 || sixes_score == 12)
                        fullHouse1 = 1;
                }
                if(fives_score == 20)
                    fourOfAKind_score = sumOfDice;
                if(fives_score == 25)
                    yahtzee_score = 50;
                break;
                
            case 6:
                strcat(display0, digit_5_0);
                strcat(display1, digit_5_1);
                strcat(display2, digit_5_2);
                strcat(display3, digit_5_3);
                sixes_score = sixes_score + 6;
                
                if(sixes_score == 12)
                {
                    if(ones_score == 3 || twos_score == 6  || fours_score == 12 || fives_score == 15  || threes_score == 9)
                    {
                        fullHouse2 = 1;
                        fullHouse1 = 1;
                    }
                }
                
                if(sixes_score == 18)
                {
                    threeOfAKind_score = sumOfDice;
                    fullHouse2 = 1;
                    
                    if(ones_score == 2 || twos_score == 4 || threes_score == 6 || fours_score == 8 || fives_score == 10)
                        fullHouse1 = 1;
                }
                if(sixes_score == 24)
                    fourOfAKind_score = sumOfDice;
                if(sixes_score == 30)
                    yahtzee_score = 50;
                break;
        }
    
        
        // large straight if statements
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            largeStraight_score = 40;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            largeStraight_score = 40;
        }
        //***small straight if statements***
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 2 && twos_score == 2 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 4 && threes_score == 3 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 6 && fours_score == 4)
        {
            smallStraight_score = 30;
        }
        if(ones_score == 1 && twos_score == 2 && threes_score == 3 && fours_score == 8)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 4 && threes_score == 3 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 6 && fours_score == 4 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 8 && fives_score == 5)
        {
            smallStraight_score = 30;
        }
        if(twos_score == 2 && threes_score == 3 && fours_score == 4 && fives_score == 10)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 6 && fours_score == 4 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 8 && fives_score == 5 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 10 && sixes_score == 6)
        {
            smallStraight_score = 30;
        }
        if(threes_score == 3 && fours_score == 4 && fives_score == 5 && sixes_score == 12)
        {
            smallStraight_score = 30;
        }
        
    }
    
    printf("%s\n",display0);
    printf("%s\n",display1);
    printf("%s\n",display2);
    printf("%s\n",display3);
    
    //chance
    for(entry = 0; entry < Entries; entry++)
    {
        chance_score = chance_score + roll[entry];
    }
    if(fullHouse1 == 1 && fullHouse2 == 1)
        fullHouse_score = 25;
    
    ScoreCardPlayerTwo();

}

void ReRollPlayerTwo() //same function as for palyer one
{
    int loop_command = 1, loop2;
    while (loop_command > 0)
    {
        printf("\n Command    Meaning ");
        printf("\n    a       Finish Roll");
        printf("\n    b       Roll some number of dice");
        printf("\n    c       Exit the program all together\n");
        printf("\n\n Please enter the option you would like.");
        scanf("%c", &command);
        
        switch(command)
        {
            case'a':
                loop_command = -1;
                break;
            case'b':
                printf("How many die would you like to change (1 through 5)? Please enter that number now.");
                loop2 =1;
                while (loop2 > 0)
                {
                    scanf("%i", &numDiceChange);
                    while(getchar() != '\n') {}
                    if (numDiceChange > 0 && numDiceChange < 6)
                        loop2 = -1;
                    else
                    {
                        printf("This is an invalid entry. Please enter a valid entry.");
                    }
                }
                printf("\nPlease enter the dice you would like to reroll. For example if you want to reroll the second die that appeared enter 2 then press enter.\n");
                printf("The number of die is from left to right, and there must be a space between each number.");
                
                for(changingDice = 0; changingDice < numDiceChange; changingDice ++)
                {
                    scanf("\n%i", &dieChange);
                    switch(dieChange)
                    {
                        case(1):
                            roll[0] = rand()% numPossibleRolls + 1;
                            break;
                        case(2):
                            roll[1] = rand()% numPossibleRolls + 1;
                            break;
                        case(3):
                            roll[2] = rand()% numPossibleRolls + 1;
                            break;
                        case(4):
                            roll[3] = rand()% numPossibleRolls + 1;
                            break;
                        case(5):
                            roll[4] = rand()% numPossibleRolls + 1;
                            break;
                            
                    }
                    dieChange = 0;
                }
                printf("\nYour new dice and scoresheet are \n");
                PrintDiceAndScorePlayerTwo();
                loop_command = -1;
                break;
            case'c':
                printf("\nThank you for playing. The program in now terminating.\n\n ");
                exit(0);
                break;
            default:
                printf("\n Error. You must enter a, b, or c. Please enter a valid command.");
                break;
        }
        while(getchar() != '\n') {}
    }
}


void PrintDicePlayerTwo() //sane functiona s for one
{
    char display0, display1, display2, display3;
    printf("%c\n",display0);
    printf("%c\n",display1);
    printf("%c\n",display2);
    printf("%c\n",display3);
}

void ScoreCardPlayerTwo() 
{
    printf("\n___________________________________________________________");
    printf("\n                   SCORECARD - PLAYER 2                    ");
    printf("\n___________________________________________________________");
    printf("\n                       Current Roll            Score       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Ones                       %i        ", ones_score);
    
    if(perm_ones_score_player_two >= 0)
           printf("            %i         ", perm_ones_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Twos                       %i         ", twos_score);
           
    if(perm_twos_score_player_two >= 0)
           printf("           %i         ", perm_twos_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Threes                     %i         ", threes_score);
          
    if(perm_threes_score_player_two >= 0)
          printf("           %i         ", perm_threes_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fours                      %i           ", fours_score);
           
    if(perm_fours_score_player_two >= 0)
           printf("         %i         ", perm_fours_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fives                      %i           ", fives_score);
    
    if(perm_fives_score_player_two >= 0)
           printf("         %i         ", perm_fives_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Sixes                      %i         ", sixes_score);
    
    if(perm_sixes_score_player_two >= 0)
           printf("           %i         ", perm_sixes_score_player_two);
    printf("\n***********************************************************");
    printf("\n Sum                                                       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Bonus                                                     ");
    printf("\n***********************************************************");
    printf("\n Three of a kind            %i         ", threeOfAKind_score);
    
    if(perm_threeOfAKind_score_player_two >= 0)
           printf("           %i         ", perm_threeOfAKind_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Four of a kind             %i          ", fourOfAKind_score);
    
    if(perm_fourOfAKind_score_player_two >= 0)
           printf("          %i         ", perm_fourOfAKind_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Full House                 %i         ", fullHouse_score);
    
    if(perm_fullHouse_score_player_two >= 0)
           printf("           %i         ", perm_fullHouse_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Small straight             %i         ", smallStraight_score);
    
    if(perm_smallStraight_score_player_two >= 0)
           printf("           %i         ", perm_smallStraight_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Large straight             %i         ", largeStraight_score);
    
    if(perm_largeStraight_score_player_two >= 0)
           printf("           %i         ", perm_largeStraight_score_player_two);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Chance                     %i          ", chance_score);
    
    if(perm_chance_score_player_two >= 0)
           printf("         %i         ", perm_chance_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n YAHTZHEE                   %i           ", yahtzee_score);
           
    if(perm_yahtzee_score_player_two >= 0)
           printf("         %i         ", perm_yahtzee_score_player_two);
    printf("\n*******************|***************************************");
    printf("\n TOTAL SCORE                                               ");
    printf("\n___________________|___________________|___________________\n");
}

void ScoreCardFinalPlayerTwo() 
{
    sum_player_two = perm_ones_score_player_two + perm_twos_score_player_two + perm_threes_score_player_two + perm_fours_score_player_two + perm_fives_score_player_two + perm_sixes_score_player_two;
    printf("\n___________________________________________________________");
    printf("\n                   SCORECARD - PLAYER 2                    ");
    printf("\n___________________________________________________________");
    printf("\n                       Current Roll            Score       ");
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Ones                       %i        ", ones_score);
    
    if(perm_ones_score_player_two >= 0)
           printf("            %i         ", perm_ones_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Twos                       %i         ", twos_score);
           
    if(perm_twos_score_player_two >= 0)
           printf("           %i         ", perm_twos_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Threes                     %i         ", threes_score);
          
    if(perm_threes_score_player_two >= 0)
          printf("           %i         ", perm_threes_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fours                      %i           ", fours_score);
           
    if(perm_fours_score_player_two >= 0)
           printf("         %i         ", perm_fours_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Fives                      %i           ", fives_score);
    
    if(perm_fives_score_player_two >= 0)
           printf("         %i         ", perm_fives_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Sixes                      %i         ", sixes_score);
    
    if(perm_sixes_score >= 0)
           printf("           %i         ", perm_sixes_score);
    printf("\n***********************************************************");
    printf("\n Sum               |                   |         %i         ", sum_player_two);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Bonus             |                             ");
    
    if(sum_player_two >= 63)
    {
           bonus_player_two = 35;
           printf(" %i ", bonus_player_two);
    }
    else
    printf("0");
           
    printf("\n***********************************************************");
    printf("\n Three of a kind            %i         ", threeOfAKind_score);
    
    if(perm_threeOfAKind_score_player_two >= 0)
           printf("           %i         ", perm_threeOfAKind_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Four of a kind             %i          ", fourOfAKind_score);
    
    if(perm_fourOfAKind_score_player_two >= 0)
           printf("          %i         ", perm_fourOfAKind_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Full House                 %i         ", fullHouse_score);
    
    if(perm_fullHouse_score_player_two >= 0)
           printf("           %i         ", perm_fullHouse_score_player_two);
    
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Small straight             %i         ", smallStraight_score);
    
    if(perm_smallStraight_score_player_two >= 0)
           printf("           %i         ", perm_smallStraight_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Large straight             %i         ", largeStraight_score);
    
    if(perm_largeStraight_score_player_two >= 0)
           printf("           %i         ", perm_largeStraight_score_player_two);
    printf("\n-------------------|-------------------|-------------------");
    printf("\n Chance                     %i          ", chance_score);
    
    if(perm_chance_score_player_two >= 0)
           printf("         %i         ", perm_chance_score_player_two);
           
    printf("\n-------------------|-------------------|-------------------");
    printf("\n YAHTZHEE                   %i           ", yahtzee_score);
           
    if(perm_yahtzee_score_player_two >= 0)
           printf("         %i         ", perm_yahtzee_score_player_two);
    printf("\n*******************|***************************************");
    total_player_two = sum_player_two + bonus_player_two + perm_threeOfAKind_score_player_two + perm_fourOfAKind_score_player_two + perm_fullHouse_score_player_two + perm_smallStraight_score_player_two + perm_largeStraight_score_player_two + perm_chance_score_player_two + perm_yahtzee_score_player_two;
    printf("\n TOTAL SCORE                                    %i          ", total_player_two);
    printf("\n___________________|___________________|___________________\n");
}

void PointAllocation_PlayerTwo()
{
    int loop_command = 1;
    
    while(loop_command > 0)
    {
        printf("\n\n Where would you like your points to be allocated? To select your choice enter the command from the command list below");
        printf("\n Command    Points to ");
        printf("\n    1       Ones");
        printf("\n    2       Twos");
        printf("\n    3       Threes");
        printf("\n    4       Fours");
        printf("\n    5       Fives");
        printf("\n    6       Sixes");
        printf("\n    7       Three of a kind");
        printf("\n    8       Four of a kind");
        printf("\n    9       Full House");
        printf("\n    10      Small Straight");
        printf("\n    11      Large Straight");
        printf("\n    12      Chance");
        printf("\n    13      Yahtzee\n");
        
        scanf("%d", &allocation_command);
        while(getchar() != '\n') {}
        switch (allocation_command)
        {
            case 1:
                if(perm_ones_score_player_two == -1)//to ensure score hasnt already been set
                {
                    perm_ones_score_player_two = ones_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 2:
                if(perm_twos_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_twos_score_player_two = twos_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 3:
                if(perm_threes_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_threes_score_player_two = threes_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                allocation_command = -1;
                break;
            case 4:
                if(perm_fours_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_fours_score_player_two = fours_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                
                break;
            case 5:
                if(perm_fives_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_fives_score_player_two = fives_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 6:
                if(perm_sixes_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_sixes_score_player_two = sixes_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 7:
                if(perm_threeOfAKind_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_threeOfAKind_score_player_two = threeOfAKind_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 8:
                if(perm_fourOfAKind_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_fourOfAKind_score_player_two = fourOfAKind_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 9:
                if(perm_fullHouse_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_fullHouse_score_player_two = fullHouse_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 10:
                if(perm_smallStraight_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_smallStraight_score_player_two = smallStraight_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 11:
                if(perm_largeStraight_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_largeStraight_score_player_two = largeStraight_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 12:
                if(perm_chance_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_chance_score_player_two = chance_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
            case 13:
                if(perm_yahtzee_score_player_two == -1) //to ensure score hasnt already been set
                {
                    perm_yahtzee_score_player_two = yahtzee_score;
                    loop_command = -1;
                }
                else
                    printf("\n This score has already been set. Please choose another command.\n\n");
                break;
        }
        
    }
}

void Results()
{
    if(total > total_player_two) // wille display which player one and what their score was
    {
        printf("\n***********************************************************");
        printf("\n               CONGRATULATIONS TO THE WINNER:");
        printf("\n                        PLAYER 1                           ");
        printf("\n          FINAL SCORE: PLAYER 1: %i  PLAYER 2: %i", total, total_player_two);
        printf("\n***********************************************************");
    }
    if(total_player_two > total)
    {
        printf("\n***********************************************************");
        printf("\n               CONGRATULATIONS TO THE WINNER:             ");
        printf("\n                        PLAYER 2                          ");
        printf("\n          FINAL SCORE: PLAYER 1: %i  PLAYER 2: %i", total, total_player_two);
        printf("\n***********************************************************");
    }
}