#include <stdio.h>
#include <ctype.h>              //DECLARING ALL THE LIBRARIRES USED
#include <string.h>

//MAKING A CONSTANT FOR NUMBER OF WORDS AVAILABLE IN DICTIONARY FOR EASE UPDATE IN FUTURE
#define TOTAL_WORDS 84099 

//MAKING A STRUCT TO STORE ALL THE WORDS LOADED FROM THE DICTIONARY
typedef struct 
{
    char scrab[50];
}word;

//DECLARING THE STRUCT NAME AND SIZE
word scrabble[TOTAL_WORDS];

//DECLARING THE FUNCTION USE TO COMPARE THE SCORES
int compute_score(char p1[], char p2[]);

//DECLARING THE FUNCTIONS TO CHANGE COLOURS OF TEXT IN TERMINAL
void green();
void red();
void yellow();
void reset();


int main()
{
    //DECLARING ALL THE VARIABLES USED IN MAIN FUNCTION
    char player1[50], player2[50];
    int i, result;

    //OPENING THE DICTIONARY TEXT FILE FOR WORD VERIFICATION
    FILE *fp = fopen("DICTIONARY.txt", "r");

    //CHECKING JUST INCASE THE FILE DOES NOT EXISTS
    if (fp == NULL)
    {
        red();
        printf("\nThe dictionary for checking the words not found\n\n");
        reset();
        return 1;
    }

    //STORING ALL THE WORDS FROM DICTIONARY TO THE STRUCT CALLED SCRABBLE
    for (i = 0; i < TOTAL_WORDS; i++)
    {
        fscanf(fp, "%s", scrabble[i].scrab);
    }

    //DECLARING A GOTO POINT TO COME BACK TO INCASE THE WORD ENTERED BY PLAYER 1 DOES NOT EXISTS
    incorrect1:

    //TAKING PLAYER 1 WORD
    yellow();
    printf("\nEnter your words\n");
    printf("\n\nplayer 1 :");
    reset();
    scanf("%s", &player1);

    //CHECKING IF THE WORD EXIST
    for(i = 0; i < TOTAL_WORDS; i++)
    {
        if (strcmp(strupr(player1), strupr(scrabble[i].scrab)) == 0)
        {
            goto correct1;           //IF WORDS EXIST GOING TO GET THE PLAYER 2 WORD
        }
   
    }

    //DECLARING THE PROGRAM TO GO BACK TO GET INPUT FOR PLAYER 1 AS THEIR WORD DIDNT EXIST
    goto incorrect1;

    //PLAYER 1 WORD EXISTS THE ASKING THE COMPILERTO READ THE PROGRAM FROM HERE ON
    correct1:

    //DECLARING A GOTO POINT TO COME BACK TO INCASE THE WORD ENTERED BY PLAYER 2 DOES NOT EXISTS
    incorrect2:

    //TAKING PLAYER 2 WORD
    yellow();
    printf("\n\nplayer 2 :");
    reset();
    scanf("%s", &player2);


    //CHECKING IF THE WORD EXIST
    for(i = 0; i < TOTAL_WORDS; i++)
    {
        if (strcmp(strupr(player1), strupr(scrabble[i].scrab)) == 0)
        {
            goto correct2;      //IF WORD EXISTS TELLING THE PROGRAM TO GO TO COMPUTE SCORE
        }
   
    }


    //TELLING IT TO GO BACK AND GET ANOTHER WORD FROM PLAYER 2 AS THEIR WORD DIDN'T EXISTED
    goto incorrect2;


    //GOTO DESTINATION IN CASE PLAYER 2 WORD EXISTS
    correct2:


    //CALLING THE FUNCTION DECLARED TO COMPUTE THE SCORES OF BOTH PLAYERS
    result = compute_score(player1, player2);

    //PRINTING THE RESULT ON BASIS OF THE RETURN VALUE GIVEN BY THE FUNCTION compute_score
    if (result == 1)
    {
        green();
        printf("\nPlayer 1 wins\n");
        reset();
    }
    else if(result == 2)
    {
        green();
        printf("\nPlayer 2 wins\n");
        reset();
    }
    else
    {
        yellow();
        printf("\nIts a tie\n");
        reset();
    }
    
}




//FUUNCTION FOR COMPUTING THE SCORE OF EACH PLAYER
int compute_score(char p1[], char p2[])
{

    //DECLARING ALL THE VARIABLES USE IN THE FUNCTION
    int result1, i;
    int score1 = 0;
    int score2 = 0;
    char check1[20], check2[20];


    //GETTING SCORE OF PLAYER 1
    for ( i = 0 ; i<strlen(p1) ; i++)
    {
        check1[i] = toupper(p1[i]);
        if (check1[i] == 'A'|| check1[i] == 'E' || check1[i] == 'I' || check1[i] == 'L' || check1[i] == 'N' || check1[i] == 'O' || check1[i] == 'R' || check1[i] == 'S' || check1[i] == 'T' || check1[i] == 'U' )
        {
            score1 = score1 + 1;
        }
        else if (check1[i] == 'D' || check1[i] == 'G')
        {
            score1 = score1 + 2;
        }
        else if (check1[i] == 'B' || check1[i]== 'C' || check1[i]== 'M' || check1[i] == 'P')
        {
            score1 = score1 + 3;
        }
        else if (check1[i]== 'F' || check1[i] == 'H' || check1[i] == 'V' || check1[i] == 'W' || check1[i] == 'Y')
        {
            score1 = score1 + 4; 
        }
        else if (check1[i]== 'K')
        {
            score1 = score1 + 5;   
        }
        else if (check1[i]== 'J' || check1[i] == 'X')
        {
            score1 = score1 + 8;   
        }
        else if (check1[i]== 'Q' || check1[i] == 'Z')
        {
            score1 = score1 + 10;   
        }
        
    }


    //GETTING SCORE OF PLAYER 2
    for (int i = 0 ; i<strlen(p2) ; i++)
    {
        check2[i] = toupper(p2[i]);
        if (check2[i] == 'A'|| check2[i] == 'E' || check2[i] == 'I' || check2[i] == 'L' || check2[i] == 'N' || check2[i] == 'O' || check2[i] == 'R' || check2[i] == 'S' || check2[i] == 'T' || check2[i] == 'U' )
        {
            score2 = score2 + 1;
        }
        else if (check2[i] == 'D' || check2[i] == 'G')
        {
            score2 = score2 + 2;
        }
        else if (check2[i] == 'B' || check2[i]== 'C' || check2[i]== 'M' || check2[i] == 'P')
        {
           score2 = score2 + 3;
        }
        else if (check2[i]== 'F' || check2[i] == 'H' || check2[i] == 'V' || check2[i] == 'W' || check2[i] == 'Y')
        {
            score2 = score2 + 4; 
        }
        else if (check2[i]== 'K')
        {
            score2 = score2 + 5;   
        }
        else if (check2[i]== 'J' || check2[i] == 'X')
        {
            score2 = score2 + 8;   
        }
        else if (check2[i]== 'Q' || check2[i] == 'Z')
        {
            score2 = score2 + 10;   
        }
   
    }

    //COMPARING SCORE OF EACH PLAYER TO DECIDE THE VALUE GETTING RETURNED BY THE FUNCTION TO THE MAIN FUNCTION
    if (score1 > score2)
    {
        result1 = 1;
    }
    else if (score2 > score1)
    {
        result1 = 2; 
    }
    else
    {
        result1 = 3;
    }


    //RETURNING THE VALUE
    return result1;
  

}



//CODE FOR ALL THE COLOURS USED IN THE PROGRAM
void red()
{
    printf("\033[0;31m");
}

void yellow()
{
    printf("\033[0;33m");
}

void green()
{
    printf("\033[0;32m");
}

void reset()
{
    printf("\033[0m");
}
