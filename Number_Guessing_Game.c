#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main () {
    //Open max file
    FILE *fp = fopen("player_max.txt", "r");
    int max = atoi(fprintf(fp, ""));
    //Create quit condition
    int quit = 0;
    //Set default max
    if (max < 1) {
        max = 10;
    }
    fclose(fp);
    //Begin loop
    while (quit == 0) {
        char input;
        //create random number between 1 and 10
        time_t t;
        srand((unsigned) time(&t));
        int randomNum = rand() % max;
        //increment random number
        randomNum += 1;
        //Print options to the screen.
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        //Get char inputs
        input = getchar();
        //if input 1 start game
        if (input=='1') {
            char gameInput[3];
            int gameOver = 0;
            //start game loop
            while (gameOver == 0) {
                //ask user for number and scan for input
                printf("Please enter your number or press Q to quit.\n");
                //flush stdin because my 'gets' keeps catching input from somewhere else. maybe the line aboe it or an enter somewhere.
                fflush(stdin);
                gets(gameInput);
                //if input equal, congratulate and break
                if (atoi(gameInput) == randomNum) {
                    printf("Great Job!\n");
                    gameOver = 1;
                }
                //if input q, break
                else if (gameInput[0] == 'q') {
                    gameOver = 1;
                }
                //else, give high/low notification
                else {
                    if (atoi(gameInput) > randomNum) {
                       printf("Try a lower number.\n");
                   }
                   else if (atoi(gameInput) < randomNum) {
                       printf("Try a higher number.\n");
                   }
                }
            //end game loop
            }
        }
        //if input 2, ask user for new number
        else if (input=='2') {
            int maxCandidate;
            printf("Please enter the maximum number that you would like to use.\n");
            //update the random number variable with one within the specified range.
            scanf("%d", &maxCandidate);
            if (maxCandidate < 1000) {
                fp = fopen("player_max.txt", "w+");
                char tempValue[3] = strcpy("%d", maxCandidate);
                fputs(tempValue, fp);
                fclose(fp);
                max = maxCandidate;
                printf("New max of %d successfully set.\n", max);
            }
            else if (maxCandidate < 1) {
                printf("Please enter a number greater than zero.\n");
            }
            else {
                printf("Please enter a number less than 1000.\n");
            }
        }
        //if input is 3, set quit to 1
        else if (input=='3') {
            quit = 1;
            printf("Thanks for playing!\n");
        }
        fflush(stdin);
    }
}