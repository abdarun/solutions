#include<stdio.h>
#include<stdbool.h>

int currentStatusOfCarRace(int carDistance[10] , int totalRaceDistance, int totalNoOfCars) {
    int start = 0, flag = 0, carNumber = -1;
    printf("Current Status of Cars in Race...\n");
    while(start<totalNoOfCars) {
        if(carDistance[start] >= totalRaceDistance) {
            flag = 1;
        }
        printf("[Car %d ] ", start+1);
        int raceMarkUnit = 0;
        while(raceMarkUnit<carDistance[start] && raceMarkUnit <= totalRaceDistance) {
            printf("=");
            raceMarkUnit +=1;
        }
        printf(">\n");
        if(flag == 1 && carNumber == -1) {
            carNumber = start;
        }
        start+=1;
    }
    printf("\n\n");
    if(flag == 1) {
        return carNumber;
    }
    return -1;
}

void updateCarSpeeds(int carSpeed[10], int carDistance[10], int totalUnits[10], int totalNoOfCars, int carKeyNumber) {
    int start = 0;
    while(start < totalNoOfCars) {
        if(start == carKeyNumber-1) {
            carSpeed[start] *=2;
            carDistance[start] = carSpeed[start]+carDistance[start];
        }
        else {
            carDistance[start]+=1;
        }
        totalUnits[start]+=1;
        start+=1;
    }
}

void raceWinner(int carDistance[10], int totalUnits[10], int totalNoOfCars, int totalDistance) {
    int start = 0;
    while(start < totalNoOfCars) {
        if(carDistance[start] >= totalDistance) {
            printf("Race winner [car %d] with %d unit of seconds", start+1, totalUnits[start]);
        }
        start+=1;
    }
}

int main() {

    int carDistance[10], carSpeed[10], totalUnits[10];
    int totalNoOfCars, totalDistanceMeters;
    printf("Enter total no of cars in a race\n");
    scanf("%d",&totalNoOfCars);
    printf("Enter total Distance in Car race\n");
    scanf("%d",&totalDistanceMeters);
    for(int i=0;i<totalNoOfCars;i++) {
        carDistance[i] = 1;
        carSpeed[i] = 1;
        totalUnits[i] = 1;
    }

    printf("Starting position of %d Cars\n", totalNoOfCars);
    currentStatusOfCarRace(carDistance, totalDistanceMeters, totalNoOfCars);
    if(totalDistanceMeters <= 1) {
        printf("Car race is drawn\n");
        return 0;
    }

    while(1) {
        int carKeyNumber;
        printf("Enter car key\n");
        scanf("%d",&carKeyNumber);
        updateCarSpeeds(carSpeed, carDistance, totalUnits, totalNoOfCars, carKeyNumber);
        int carNumber = currentStatusOfCarRace(carDistance, totalDistanceMeters, totalNoOfCars);
        if(carNumber != -1) {
            raceWinner(carDistance, totalUnits, totalNoOfCars, totalDistanceMeters);
            break;
        }
    }
}
