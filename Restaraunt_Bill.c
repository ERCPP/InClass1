#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Begin main function
int main () {
    float input;
    time_t t;
    //Create Arrray With Prices
    float prices[4] = {9.95, 4.55, 13.25, 22.35};
    //Set a variable to a random number between 0 and 3
    srand((unsigned) time(&t));
    int randomMeal = rand() % 4;
    //Use that variable to select the price from the corresponding spot in the array.
    float randomPrice = prices[randomMeal];
    //Create tax variable and set it equal to the first argument multiplied by the price
    printf("Enter tax as percent.\n");
    scanf("%f", &input);
    float tax = randomPrice*(input*.01);
    //Create tip variable and set it equal to the second argument multiplied by the price
    printf("Enter tip as percent.\n");
    scanf("%f", &input);
    float tip = randomPrice*(input*.01);
    //Create total variable and add the original price, the tax, and the tip to it.
    float total = randomPrice+tax+tip;
    //Print all info to the screen
    printf("The cost of the meal is $%.2f\nThe tax costs $%.2f\nThe tip amount is $%.2f\nThe total cost of the meal is $%.2f\n", randomPrice, tax, tip, total);
}