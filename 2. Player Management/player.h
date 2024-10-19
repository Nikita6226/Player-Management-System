#include<stdio.h>
#include<string.h>
#include <ctype.h>  // for tolower()

typedef struct PlayerManagementSystem
{
    int playerID;
    char player_Name[20];
    char team_Name[20];   
    int run;
    double matchesPlayed;
    double wicket;
} PlayerManagementSystem;  

int hardCoded(PlayerManagementSystem*, int);
void storePlayers(PlayerManagementSystem*, int);
void displayAllPlayers(PlayerManagementSystem*, int);
void deletePlayer(PlayerManagementSystem*, int*, int);
void updatePlayer(PlayerManagementSystem*, int);
void sortPlayers(PlayerManagementSystem*, int);
int searchByID(PlayerManagementSystem*, int, int);
void searchByName(PlayerManagementSystem*, int, char*);
void search(PlayerManagementSystem*, int);
void displayOnePlayer(PlayerManagementSystem*, int);
char* strcasestr(const char* , const char* );

