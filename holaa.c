//Including required libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Defining macros
#define tax 0.05
//Declaration of required variables
unsigned short sourc,dest,mode,opt;
char buffe[4][100];
//Declaration and Initialization of required arrays
//List of source places
char z[5][100]={"Chennai","Sathyabama","Shollingnallur","Tambaram","T Nagar"};
//List of cab service types
char transport_mode[5][100]={"Auto","Micro","Mini","SUV"};
//List of Base Fare
float mode_price[4]={5,8,10,12};
//Distance form the respective Source to Destination
float dist[5][4]={{60,55,57,46},{60,15,45,50},{55,15,30,40},{40,45,30,70},{46,50,40,70}};
//Function definition for displaying Source Location
int place()
{
    int i;

    for(i=0;i<5;i++)
    {
       printf("%d-%s\n",i,z[i]);
    }

}
//Function definition for displaying Destination Location
int destination()
{
    int j;
    int count=1;
    for (j=0;j<5;j++)
    {

        if (j==sourc)
        {
             continue;
        }
        else
        {
            printf("%d-%s\n",count,z[j]);
            //printf("\nDistance:%f\tFare:%f",dist[i][count],fare[i]);
            strcpy(buffe[j] ,z[j]);
            count=count+1;
        }
    }

}
//Calulation of Fare according to the User Preferences
int pricing()
{
    float totalfare;
    dest=dest-1;
    totalfare=((dist[sourc][dest]-5)*mode_price[mode]+5*(2*mode_price[mode]));
    totalfare=(tax*totalfare+totalfare);
    printf("\nThe fare for %s from:",transport_mode[mode]);
    printf("\n%s to %s is:%.3f:",z[sourc],buffe[dest],totalfare);
}
//Function definition for display of Cab Services types
int mod()
{
    int x;
    for(x=0;x<4;x++)
    {
       printf("%d-%s\n",x,transport_mode[x]);
    }
}
//options after selections
int options()
{
    switch (opt)
    {
        case 1:
            printf("\nYour Booking has been confirmed!!!\nThank you for using our services!!");
            break;
        case 2:
            printf("\nPlease select the new preferences:");
            break;
        case 3:
            printf("\nThank you for using our services");
            break;


        default:
            printf("\nPlease choose a valid option!!!");
                break;
    }
}
int main()
{
    printf("Welcome to Holaa Cabs!!!\n");
    do
    {
        printf("\nChoose a pickup place:\n");
        place();
        scanf("%d",&sourc);
        printf("\nChoose a destination\n");
        destination();
        scanf("%d",&dest);
        printf("\nPlease select a cab service of your preference:\n");
        mod();
        scanf("%d",&mode);
        pricing();
        printf("\nPress 1 to Confirm the ride");
        printf("\nPress 2 to Edit the Preferences");
        printf("\nPress 3 to Cancel the Ride\n");
        scanf("%d",&opt);
        options(opt);







    }while(opt!=3 || opt!=1);
    return 0;

}