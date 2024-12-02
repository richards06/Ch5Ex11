/*
Program Title: Ch5Ex11
Programmer: Josh Richards
Date: November 27, 2024
Requirements:

Write a program that will predict the size of a population of organisms.

The program should ask the user for the starting number of organisms,

their average daily population increase (as a percentage),

and the number of days they will multiply. A loop should display the size of the population for each day.

Input Validation: Do not accept a number less than 2 for the starting size of the population.

Do not accept a negative number for average daily population increase.

Do not accept a number less than 1 for the number of days they will multiply.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int getStartingPopulation();
double getDailyIncrease();
int getNumDays();
void displayPopulationGrowth(int startingPopulation, double dailyIncrease, int numDays);


int main()
{
    int startingPopulation = getStartingPopulation();
    double dailyIncrease = getDailyIncrease();
    int numDays = getNumDays();

    displayPopulationGrowth(startingPopulation, dailyIncrease, numDays);

    return 0;
}

int getStartingPopulation(){ 
    int population;
    do {
        cout << "Enter the starting number of organisms (minimum 2): ";
        cin >> population;
        if (population < 2){
            cout << "Starting population must be at least 2. Please try again." << endl;
        }
    } while (population < 2);
    return population;
}


double getDailyIncrease() {
    double increase;
    do {
        cout << "Enter the average daily population increase (as a percentage): ";
        cin >> increase;
        if (increase < 0) {
            cout << "The daily population increase cannot be negative. Please try again." << endl;
        }
    } while (increase < 0);
    return increase;
}


int getNumDays() {
    int days;
    do {
        cout << "Enter the number of days the organisms will multiply (minimum 1): ";
        cin >> days;
        if (days < 1) {
            cout << "The number of days must be at lease 1. Please try again." << endl;
        }
    } while (days < 1);
    return days;
}

void displayPopulationGrowth(int startingPopulation, double dailyIncrease, int numDays) {
    dailyIncrease /= 100;
    cout << fixed << setprecision(2);
    cout << "\nDay-by-day population growth: \n";
    for (int day = 1; day <= numDays; ++day) {
        startingPopulation += startingPopulation * dailyIncrease;
        cout << "Day" << day << ": " << startingPopulation << " organisms" << endl;
    }
}