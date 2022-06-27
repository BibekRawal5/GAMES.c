//DECLARING ALL THE LIBRARIES INCLUDE IN THE PROGRAM

#include <stdio.h>
#include <string.h>
#include <ctype.h>                     
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//MAKING A STRUCT TO STORE ALL THE WORDS LOADED FROM THE DICTIONARY
typedef struct 
{
    char scrab[50];
}word;

//MAKING A CONSTANT FOR NUMBER OF WORDS AVAILABLE IN DICTIONARY FOR EASE UPDATE IN FUTURE
#define TOTAL_WORDS 84099 

//DECLARING THE STRUCT NAME AND SIZE
word scrabble[TOTAL_WORDS];



//DECLARING A STRUCT TO STORE ALL THE QUESTIONS AND ANSWERS FROM FILE (FOR QUIZ)
typedef struct 
{                                                               
    char question[300];
    char answer[100];

}QUIZ1;

//MAKING A CONSTANT FOR NUMBER OF WORDS AVAILABLE IN DICTIONARY FOR EASE UPDATE IN FUTURE
#define SIZE 55

//DECLARING THE STRUCT NAME AND SIZE
QUIZ1 quiz [SIZE];



// MAKING A CONSTANT FOR TOTAL WORDS WE HAVE AVAILABLE (FOR WORDLE)
#define TOTALWORDS 5757

typedef struct
{
    char wordleword[6];
}wordle;

//DECLARING THE STRUCT NAME AND SIZE
wordle allwords[TOTALWORDS];


//DECLARING THE FUNCTIONS TO CHANGE COLOURS OF TEXT IN TERMINAL
void green();
void red();
void yellow();
void reset();

//DECLARING THE FUNCTION USE TO COMPARE THE SCORES
int compute_score(char p1[], char p2[]);


//DECLARING FUNCTIONS OF EACH INDIVIDUAL GAME
int scrabble1();
int wordle1 ();
int quiz2();
int rps();



int main()
{
    //DECLARING ALL VARIABLE USED
    int game, ret;
    char again;

    //DECLARING A GOTO LABEL
    start:

    //ADKING USER WHICH GAME THEY WANT TO PLAY
    printf("What game do you want to play ? (Press the  number of the game written on the left)\n");
    printf("1. WORDLE\n");
    printf("2. Rock Paper Scissors (against AI)\n");
    printf("3. Basic GK and IQ quiz\n");
    printf("4. Scrabble\n");
    ret = scanf("%d",&game);
    fflush(stdin);

    //IF USER INPUTS ANYTHING ELSE THAN GAMES AVAILABLE TAKING THEM BACK TO START
    if ( ret != 1 || game > 4 || game < 1)
    {
        goto start;
    }

    //USER CHOOSE TO PLAY WORDLE
    if(game == 1)
    {
        wordle1();
        yellow();
        printf("Do You want to play anything else or same game again? ");
        reset();
        scanf("%c", &again);
        fflush(stdin);
        if (again == 'y' || again == 'Y')
        {
            goto start;
        }
        else
        {
            red();
            printf("Thank you for playing and giving it your time.\n");
            reset();
            return 0;
        }
    }

    //USER CHOSE TO PLAY ROCK, PAPER SCISSORS
    else if(game == 2)
    {
        rps();
        yellow();
        printf("Do You want to play anything else or same game again? ");
        reset();
        scanf("%c", &again);
        fflush(stdin);
        if (again == 'y' || again == 'Y')
        {
            goto start;
        }
        else
        {
            red();
            printf("Thank you for playing and giving it your time.\n");
            reset();
            return 0;
        }
    }

    //USER CHOOSE TO PLAY QUIZ
    else if(game == 3)
    {
        quiz2();
        yellow();
        printf("Do You want to play anything else or same game again? ");
        reset();
        scanf("%c", &again);
        fflush(stdin);
        if (again == 'y' || again == 'Y')
        {
            goto start;
        }
        else
        {
            red();
            printf("Thank you for playing and giving it your time.\n");
            reset();
            return 0;
        }
    }

     //USER CHOOSE TO PLAY SCRABBLE
    else
    {
        scrabble1();
        yellow();
        printf("Do You want to play anything else or same game again? ");
        reset();
        scanf("%c", &again);
        fflush(stdin);
        if (again == 'y' || again == 'Y')
        {
            goto start;
        }
        else
        {
            red();
            printf("Thank you for playing and giving it your time.\n");
            reset();
            return 0;
        }
    }

    
}    




//CODE FOR ROCK PAPER SCIZZOR
int rps()
{
      
     //DECLARING ALL THE VARIABLES USED
     int ran, mode, ret;
     char rps1;
     char rps2;
     char choice;
     
     green();
     printf("\nWelcome to Rock Paper Scissors\n");
     reset();
     
     // MAKING A DO LOOP INCASE USER WANTS TO PLAY AGAIN WITHOUT RE-RUNNING THE PROGRAM
     do
     { 
        //ASKING USER WHICH MODE THEY WANT TO PLAY
          do
          {
               printf("\nWhich mode do you want to play? (Press the number assigend on the left)\n");
               printf("1. VERSUS AI\n");
               printf("2. Human vs Human\n");
               ret = scanf("%i", &mode);
               fflush(stdin);
          }while (ret != 1 || mode > 2 || mode < 1);


          if(mode == 1)
          {
               //SENDING IT TO HUMAN VS AI SECTION OF THE GAME
               goto AI;
          }
          else
          {
               //SENDING IT TO THE HUMAN VS HUMAN SECTION
               goto HUMAN;
          }


        //VERSUS AI
        //AI LABEL FOR GOTO STATEMENT
         AI:
          
          //ASKING THE USER MOVE AND NOT ACCEPTING ANYTHING OTHER THAN ROCK, PAPER AND SCISSORS
          do
          {
               printf("Enter you move: ");
               scanf("%c", &rps1);
               fflush(stdin);
               if (rps1 == 'r' || rps1 == 'p' || rps1 == 's')
               {
                    break;
               }
          }while(1);

          //GENERATING A RANDOM NUMBER BETWEEN 1 TO 3 WHICH REPRESENT COMPUTER MOVES
          srand(time(NULL));
          ran = 1 + rand() % 3;

    
          //COMPARING THE COMPUTER GENERATED MOVE WITH THE USER GENERATED
    

          //WHEN COMPUTER CHOOSE ROCK
          if (ran == 1)
          {
               if (rps1 == 's')
               {
                    red();
                    printf("\nYou loose, computer choose rock\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    yellow();
                    printf("\nYou drew, computer choose rock\n\n");
                    reset();
               }
               else if (rps1 == 'p')
               {
                    green();
                    printf("\nYou won, computer choose rock\n\n");
                    reset();
               }
          }


          //WHEN COMPUTER choose PAPER
          else if (ran == 2)
          {
               if (rps1 == 's')
               {
                    green();
                    printf("\nYou won, computer choose paper\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    red();
                    printf("\nYou loose, computer choose paper\n\n");
                    reset();
               }
               else if (rps1 == 'p')
               {
                    yellow();
                    printf("\nYou drew, computer choose paper\n\n");
                    reset();
               }
          }


          //WHEN COMPUTER choose SCISSOR
          else if (ran == 3)
          {
               if (rps1 == 's')
               {    
                    yellow();
                    printf("\nYou drew, computer choose scissor\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    green();
                    printf("\nYou won, computer choose scissor\n\n");
                    reset();
               }
               else if(rps1 == 'p')
               {
                    red();
                    printf("\nYou loose, computer choose scissor\n\n");
                    reset();
               }
          }

        //SENDING THE COMPILER DIRECT TO END SO IT DOEST EXECUTE THE HUMAN CODE TOO
        goto END;


        //HUMAN LABEL FOR GOT STATMENT

          HUMAN:
          //HUMAN VERSUS HUMAN
          //ASKING THE USER MOVE AND NOT ACCEPTING ANYTHING OTHER THAN ROCK, PAPER AND SCISSORS
          //PLAYER 1 MOVE

          printf("Payer 1, ");     
           do
          {
               printf("Enter you move: ");
               rps1 = getch();
               printf("*** \n");
               fflush(stdin);

          }while(rps1 != 'r' && rps1 != 'p' && rps1 != 's');


          //PLAYER 2 move
          printf("Payer 2, ");     
           do
          {
               printf("Enter you move: ");
               rps2 = getch();
               printf("*** \n");
               fflush(stdin);

          }while(rps2 != 'r' && rps2 != 'p' && rps2 != 's');


           //WHEN PLAYER 2 CHOOSES ROCK
          if (rps2 == 'r')
          {
               if (rps1 == 's')
               {
                    green();
                    printf("\nPlayer 2 wins, he choose rock against scissors.\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    yellow();
                    printf("\nYou drew, both choose rock.\n\n");
                    reset();
               }
               else if (rps1 == 'p')
               {
                    green();
                    printf("\nPlayer 1 win, he choose paper against rock.\n\n");
                    reset();
               }
          }


              //WHEN PLAYER 2 CHOOSES PAPER
          if (rps2 == 'p')
          {
               if (rps1 == 's')
               {
                    green();
                    printf("\nPlayer 1 wins, he choose scissor against paper.\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    green();
                    printf("\nPlayer 2 wins, he choose paper against rock.\n\n");
                    reset();
               }
               else if (rps1 == 'p')
               {
                    yellow();
                    printf("\nYou drew, both choose paper.\n\n");
                    reset();
               }
          }


          //WHEN PLAYER 2 CHOOSES PAPER
          if (rps2 == 's')
          {
               if (rps1 == 's')
               {
                    yellow();
                    printf("\nYou drew, both choose scissor.\n\n");
                    reset();
               }
               else if(rps1 == 'r')
               {
                    green();
                    printf("\nPlayer 1 wins, he choose rock against scissor.\n\n");
                    reset();
               }
               else if (rps1 == 'p')
               {
                    green();
                    printf("\nPlayer 2 wins , he choose scissor against paper.\n\n");
                    reset();
               }
          }


        //END LABEL FOR GOTO STATEMENT
          END:


          printf("Do you want to play again ? (y/n) : ");
          scanf("%c", &choice);
          fflush(stdin);
    }while((choice == 'y') || (choice == 'Y'));
     
    return 0;
}



//CODE FOR QUIZ
int quiz2()
{
    // INITIALIZING ALL THE VARIABLE USED IN THE PROGRAM
    int i;
    char *guess;
    char ch;
    FILE *fp;

    //ALLOCATING SPACE FOR OUR POINTER
    guess = malloc(sizeof(char) * 100);

    //OPENING AND LOADING ALL QUESTION AND ANSWERS IN THE STRUCt
    fp = fopen("QUIZ.txt", "r");

    //CHECKING JUST IN CASE THE FILE DOES NOT EXIST
    if (fp == NULL)
    {
        printf("QUIZ.txt not found for questions and answers\n");
        return 1;
    }

    for(i = 0; i < SIZE; i++)
    {
        fscanf(fp, "%[^\n] ", quiz[i].question);
        fscanf(fp, "%[^\n] ", quiz[i].answer);
    }

    fclose(fp);


    //ADDING A LOOP JUST IN CASE THE USER WANTS TO PLAY AGAIN
    do
    {   
        // USING SRAND AND RAND TO GENERATE A RANDOM NUMBER FOR QUESTION
        srand(time(NULL));
        i = rand() % SIZE;

        //PRINTING QUESTION AND LETTING USER GIVE AN INPUT
        printf("\n%s\n", quiz[i].question);
        scanf("%[^\n]s", guess);
        fflush(stdin);

        //COMPARING THE GUESS AND ANSWER
        if (strcmp(strupr(guess), strupr(quiz[i].answer)) == 0)
        {
            green();
            printf("\nCONGRATULATIONS ON THE CORRECT ANSWER\n\n");
            reset();
        }

        else
        {
            red();
            printf("\nThe correct answer : %s\n\n", quiz[i].answer);
            reset();
        }

        printf("Do you want to play again (Y/N): ");
        scanf("%c", &ch);
        fflush(stdin);
    
    }while(ch == 'y' || ch == 'Y');

    //RELEASING THE ALLOCATED MEMORY FOR GUESS AND CLOSING THE FILE
    free(guess);

    return 0;
}



//CODE FOR WORDLE
int wordle1 ()
{
    char guess[10];
    char word[6];
    int i = 0;

    //OPENING THE WORDLE TEXT FILE FOR SELECTING A RANDOM WORD
    FILE *fp;
    fp = fopen("wordle.txt", "r");

    if ( fp == NULL)
    {
        printf("\nError reading the file\n");
        return 1;
    }
    
    for (int k = 0; k < TOTALWORDS; k++)
    {
        fscanf(fp, "%s", allwords[k].wordleword);
    }
    fclose(fp);

    //GENERATING A RANDOM WORD OUT OF ALL THE WORDS WE HAVE
    srand(time(NULL));
    int random = rand() % TOTALWORDS;
    strcpy(word, allwords[random].wordleword);

    green();
    printf("\nWELCOME TO WORDLE\n");
    reset();

    do
    {
        //TAKING THE USER FIRST GUESS AND CHECKING IF FITS IS 5 LETTER WORD
        do
        {
            printf("Guess no %d: ", i+1);
            scanf("%s", guess);
            fflush(stdin);
        }while(strlen(guess) != 5);

        //MAKING THE USER GIVEN WORD IN UPPERCASE TO COMPARE IT WITH THE RANDOM SELECTED WORD BY COMPUTER FROM FILE
        for (int j = 0; j < strlen(guess); j++)
        {
            guess[j] = toupper(guess[j]);
        }


        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (guess[i] == word[i])
                {
                    green();
                    printf("%c", guess[i]);
                    reset();
                    goto jump;
                }
                else if (guess[i] == word[j])
                {
                    yellow();
                    printf("%c", guess[i]);
                    reset();
                    goto jump;                            // SETTINGUP A GOTO TO  GET OUT OF NESTED LOOP NESTED LOOP
                }
                
            }
            
            printf("%c", guess[i]);

            jump: ;                                      // GOTO jump posotion
        
        }
        printf("\n");

        //CHECKING IF USER HAS GUESSED THE CORRECT WORD
        if (strcmp(guess, word) == 0)
        {
            green();
            printf("CONGRATULATION ON GUESSING THE CORRECT WORD\n");
            reset();
            return 0;
        }
        i++;
    }while( i < 5); 

    // PRINTING THE CORRECT ANSWER FOR THE USER AFTER 5 FAIL ATTEMPT
    red();
    printf("The corect word: %s\n", word);
    reset();
    return 0;
    
}


int scrabble1()
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
    fflush(stdin);

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
    fflush(stdin);


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
