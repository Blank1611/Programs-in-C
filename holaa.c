//Including required libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Defining macros
#define tax 0.05
//Declaration of required variables
unsigned short sourc,dest,mode,opt;
//Declaration and Initialization of required arrays
//List of source places
char places[5][100]={"Chennai","Sathyabama","Shollingnallur","Tambaram","T Nagar"},response;
//List of cab service types
char transport_mode[5][100]={"Auto","Micro","Mini","SUV"};
//List of Base Fare
float mode_price[4]={5,8,10,12};
<<<<<<< HEAD
//Distance from the respective Source to Destination
float dist[5][4]={
        {60,55,57,46},
        {60,15,45,50},
        {55,15,30,40},
        {40,45,30,70},
        {46,50,40,70}
        };
//Average speed
float speed[5]={25,45,45,40};
=======
//Distance form the respective Source to Destination
float dist[5][4]={{60,55,57,46},
                  {60,15,45,50},
                  {55,15,30,40},
                  {40,45,30,70},
                  {46,50,40,70}
                 };
>>>>>>> ed2e18ed9215cc7763e4b0830dbd8c57d0d5b3fc
//Function definition for displaying Source Location
int place()
{
    int i;
    for(i=0;i<5;i++)
    {
       printf("%d-%s\n",i,places[i]);
    }
    scanf("%d",&sourc);
    if(sourc>=4)
    {
        printf("\nPlease select a valid source!!!\n");
        place();
    }
}
//Function definition for displaying Destination Location
int destination()
{
    int j;
    for (j=0;j<5;j++)
    {
        if (j==sourc)
        {
             continue;
        }
        else
        {
            printf("%d-%s\n",j,places[j]);
        }
    }
    scanf("%d",&dest);
    if(dest==sourc)
    {
        printf("\nPlease Select a valid Destination!!!\n");
        destination();
    }
}
//Calulation of Fare according to the User Preferences
int pricing()
{
    float totalfare,time;
    totalfare=((dist[sourc][dest]-5)*mode_price[mode]+5*(2*mode_price[mode]));
    totalfare=(tax*totalfare+totalfare);
    time=(dist[sourc][dest]/speed[mode]);
    printf("\nThe fare for %s from ",transport_mode[mode]);
    printf("%s to %s is:%.3f:",places[sourc],places[dest],totalfare);
    printf("\nAverage Time for journey:%.3f",time);
}
//Function definition for display of Cab Services types
int mod()
{
    int x;
    for(x=0;x<4;x++)
    {
       printf("%d-%s\n",x,transport_mode[x]);
    }
    scanf("%d",&mode);
    if(mode>=3)
    {
        printf("\nPlease select a valid service!!!\n");
        mod();
    }
}
//options after selections
int options()
{
        scanf("%d",&opt);
        if (opt==1)
        {
           printf("\nYour Booking has been confirmed!!!\nWould you like to book another ride?(Y/N):");
            scanf("\n%c",&response);
            if(response=='N')
            {
                printf("\n\nThank you for using our services!!");
                printf("\n-----------------------------------------------");
            }
            else{
                opt=2;
            }
        }
        else if(opt==2)
        {
            printf("\nPlease select the new preferences:");
        }
        else if(opt==3)
        {
            printf("\nThank you for using our services!!!");
            printf("\n-----------------------------------------------");
        }
        else
        {
            printf("\nPlease Select a valid option!!");
        }
}
int main()
{
    printf("--------Welcome to Holaa Cabs!!!--------\n");
    do
    {
        printf("\nChoose a pickup place:\n");
        place();
        printf("\nChoose a destination\n");
        destination();
        printf("\nPlease select a cab service of your preference:\n");
        mod();
        pricing();
        printf("\nPress 1 to Confirm the ride");
        printf("\nPress 2 to Edit the Preferences");
        printf("\nPress 3 to Cancel the Ride\n");
        options();
    }while(opt==2);
    return 0;
}
