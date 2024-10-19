#include "player.h"

int hardCoded(PlayerManagementSystem* player, int ctr)
{
    // Player 1
    player[ctr].playerID = 101;
    strcpy(player[ctr].player_Name, "Virat Kohli");
    strcpy(player[ctr].team_Name, "India");
    player[ctr].run = 12500;
    player[ctr].wicket = 4.0;
    player[ctr].matchesPlayed = 570;
    ctr++;

    // Player 2
    player[ctr].playerID = 102;
    strcpy(player[ctr].player_Name, "AB de Villiers");
    strcpy(player[ctr].team_Name, "South Africa");
    player[ctr].run = 12000;
    player[ctr].wicket = 2.0;
    player[ctr].matchesPlayed = 420;
    ctr++;

    // Player 3
    player[ctr].playerID = 103;
    strcpy(player[ctr].player_Name, "Joe Root");
    strcpy(player[ctr].team_Name, "England");
    player[ctr].run = 10000;
    player[ctr].wicket = 30.0;
    player[ctr].matchesPlayed = 320;
    ctr++;

    return ctr;
}


void storePlayers(PlayerManagementSystem* player, int ctr)
{
    printf("Enter Player ID: ");
    scanf("%d", &player[ctr].playerID);

    printf("Enter Player name: ");
    scanf("%s", player[ctr].player_Name);

    printf("Enter Team name: ");
    scanf("%s", player[ctr].team_Name);

    printf("Enter Run: ");
    scanf("%d", &player[ctr].run);

    printf("Enter Wicket: ");
    scanf("%lf", &player[ctr].wicket);

    printf("Enter Total Run: ");
    scanf("%lf", &player[ctr].matchesPlayed);

    printf("\nPlayer added successfully!\n");
}

void displayAllPlayers(PlayerManagementSystem* player, int ctr)
{
    int i;
    if (ctr > 0)
    {
        printf("+-----------+-----------------+---------------+---------+---------+----------+\n");
        printf("| Player ID |   Player Name   |   Team Name   |   Run   |  Wicket |  Matches |\n");
        printf("+-----------+-----------------+---------------+---------+---------+----------+\n");

        for (i = 0; i < ctr; i++)
        {
            printf("| %9d | %15s | %13s | %7d | %7.1lf | %8.1lf |\n", 
                   player[i].playerID, player[i].player_Name, player[i].team_Name, 
                   player[i].run, player[i].wicket, player[i].matchesPlayed);
        }

        printf("+-----------+-----------------+---------------+---------+---------+----------+\n");

    }
    else
    {
        printf("\nNo players to display!\n");
    }
}

void deletePlayer(PlayerManagementSystem* player, int* ctr, int ind)
{
    int i;
    for (i = ind; i < *ctr - 1; i++)
    {
        player[i] = player[i + 1];
    }
    (*ctr)--; 
}

void updatePlayer(PlayerManagementSystem* player, int ctr)
{
    int id;
    printf("\nEnter Player ID you want to update: ");
    scanf("%d", &id);

    int i = searchByID(player, ctr, id);
    if (i == -1)
    {
        printf("\nPlayer not found!!\n");
        return;
    }

    int ch;
    do
    {
        // Menu for updating different fields
        printf("\nWhat do you want to update?\n");
        printf("1. Update Player Name\n");
        printf("2. Update Team Name\n");
        printf("3. Update Run\n");
        printf("4. Update Wicket\n");
        printf("5. Update Both Run and Wicket\n");
        printf("0. Exit Update\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter new Player Name: ");
                scanf("%s", player[i].player_Name);
                printf("\nPlayer Name updated successfully!\n");
                break;

            case 2:
                printf("Enter new Team Name: ");
                scanf("%s", player[i].team_Name);
                printf("\nTeam Name updated successfully!\n");
                break;

            case 3:
                printf("Enter new Run: ");
                scanf("%d", &player[i].run);
                printf("\nRun updated successfully!\n");
                break;

            case 4:
                printf("Enter new Wicket: ");
                scanf("%lf", &player[i].wicket);
                printf("\nWicket updated successfully!\n");
                break;

            case 5:
                printf("Enter new Run: ");
                scanf("%d", &player[i].run);
                printf("Enter new Wicket: ");
                scanf("%lf", &player[i].wicket);
                printf("\nRun and Wicket updated successfully!\n");
                break;

            case 0:
                printf("\nExiting Update Menu...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }

    } while (ch != 0);  // Loop until user chooses to exit
}


void sortPlayers(PlayerManagementSystem* player, int ctr)
{
    int i, j;
    for (i = 0; i < ctr - 1; i++)
    {
        for (j = 0; j < ctr - i - 1; j++)
        {
            if (player[j].playerID > player[j + 1].playerID)
            {
                PlayerManagementSystem temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }
    }
}

int searchByID(PlayerManagementSystem* player, int ctr, int id)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        if (player[i].playerID == id)
        {
            return i;
        }
    }
    return -1;
}



void searchByName(PlayerManagementSystem* player, int ctr, char* name)
{
    int i;
    int found = 0;
    for (i = 0; i < ctr; i++)
    {
        // Case-insensitive partial name search
        if (strcasestr(player[i].player_Name, name) != NULL)
        {
            printf("\nPlayer Found! Details are as follows:\n");
            displayOnePlayer(player, i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nPlayer not found!\n");
    }
}

// Function to perform case-insensitive substring search (for search by name)
char* strcasestr(const char* haystack, const char* needle)
{
	const char* p;
    if (!*needle)
        return (char*) haystack;

    for ( p = haystack; *p != '\0'; p++)
    {
        if (tolower(*p) == tolower(*needle))
        {
            const char* h = p;
            const char* n = needle;

            while (*h && *n && tolower(*h) == tolower(*n))
            {
                h++;
                n++;
            }

            if (!*n)
                return (char*) p;  // Match found
        }
    }

    return NULL;  // No match found
}



void search(PlayerManagementSystem* player, int ctr)
{
    int id;
    char name[20];
    int ch;

    printf("\n1. Search by Player ID\n2. Search by Player Name\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter Player ID: ");
        scanf("%d", &id);
        int index = searchByID(player, ctr, id);
        if (index != -1)
        {
            displayOnePlayer(player, index);
        }
        else
        {
            printf("\nPlayer not found!\n");
        }
        break;

    case 2:
        printf("Enter Player Name: ");
        scanf("%s", name);
        searchByName(player, ctr, name);
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }
}

void displayOnePlayer(PlayerManagementSystem* player, int index)
{
    printf("\n+-----------+-----------------+---------------+---------+---------+----------+\n");
    printf("| Player ID |   Player Name   |   Team Name   |   Run   |  Wicket |  Matches |\n");
    printf("+-----------+-----------------+---------------+---------+---------+----------+\n");
    printf("| %9d | %15s | %13s | %7d | %7.1lf | %8.1lf |\n", 
           player[index].playerID, player[index].player_Name, player[index].team_Name, 
           player[index].run, player[index].wicket, player[index].matchesPlayed);
    printf("+-----------+-----------------+---------------+---------+---------+----------+\n");
}

