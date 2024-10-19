#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    int size = 20;
    PlayerManagementSystem player[20];
    int ctr = 0;

    ctr = hardCoded(player, ctr); 
    printf("\nNumber of players after hard coding: %d\n", ctr);

    if (ctr > 0)
    {
        printf("\nDisplaying all hardcoded players:\n");
        displayAllPlayers(player, ctr);
    }
    else
    {
        printf("\nNo players available to display.\n");
    }

    int ch;
    do
    {
        printf("\n1. Add Player\n2. Display All Players\n3. Search Player\n4. Delete Player\n5. Update Player\n6. Sort Players\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (ctr < size)
            {
                storePlayers(player, ctr);
                ctr++;
            }
            else
            {
                printf("Insufficient memory!\n");
            }
            break;

        case 2:
            if (ctr > 0)
            {
                displayAllPlayers(player, ctr);
            }
            else
            {
                printf("No players present!\n");
            }
            break;

        case 3:
            search(player, ctr);
            break;

        case 4:
            {
                int playerID;
                printf("\nEnter Player ID you want to delete: ");
                scanf("%d", &playerID);
                int i = searchByID(player, ctr, playerID);
                if (i == -1)
                {
                    printf("\nPlayer not found!\n");
                }
                else
                {
                    deletePlayer(player, &ctr, i);
                    printf("\nPlayer deleted successfully!\n");
                }
            }
            break;

        case 5:
            if (ctr != 0)
            {
                updatePlayer(player, ctr);
            }
            else
            {
                printf("No players to update!\n");
            }
            break;

        case 6:
            if (ctr != 0)
            {
                sortPlayers(player, ctr);
                printf("\nPlayers sorted by player ID!\n");
            }
            else
            {
                printf("No players to sort!\n");
            }
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }

    } while (ch != 0);

    return 0;
}

