#include <stdio.h>
#include <stdlib.h>
#include <time.h>
////////computer////////
void vsComputer(int player, int computer)
{
    if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2))
    {
        printf("Player wins!\n");
    }

    else if ((computer == 1 && player == 3) ||
             (computer == 2 && player == 1) ||
             (computer == 3 && player == 2))
    {
        printf("Computer Wins!\n");
    }

    else
    {
        printf("Computer chose '%d'\n", computer);
        printf("It's a tie\n");
    }
}
///////player//////////
void vsPlayer(int firstPlayer, int secondPlayer)
{
    if ((firstPlayer == 1 && secondPlayer == 3) ||
        (firstPlayer == 2 && secondPlayer == 1) ||
        (firstPlayer == 3 && secondPlayer == 2))
    {
        printf("Player 1 wins!\n");
    }
    else if ((secondPlayer == 1 && firstPlayer == 3) ||
             (secondPlayer == 2 && firstPlayer == 1) ||
             (secondPlayer == 3 && firstPlayer == 2))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie\n");
    }
}
//////////main/////////
int main()
{
    int gameType, firstPlayer, secondPlayer, player, computer, restart;
    do
    {
        printf("Enter [ 1 ] for [player vs player]\n");
        printf("Enter [ 2 ] for [player vs computer]\n");
        scanf("%d", &gameType);
        ////////////game 1////////////////////
        if (gameType == 1)
        {
            printf("\n// Enter 1 for Rock //\n");
            printf("// Enter 2 for Paper //\n");
            printf("// Enter 3 for Scissors //\n");
            printf("/////////////////////////////////////////\n");

            printf("Player 1: ");
            scanf("%d", &firstPlayer);
            system("clear");

            printf("// Enter 1 for Rock //\n");
            printf("// Enter 2 for Paper //\n");
            printf("// Enter 3 for Scissors //\n");
            printf("/////////////////////////////////////////\n");

            printf("Player 2: ");
            scanf("%d", &secondPlayer);
            system("clear");

            if ((firstPlayer == 1 || firstPlayer == 2 || firstPlayer == 3) && (secondPlayer == 1 || secondPlayer == 2 || secondPlayer == 3))
            {
                vsPlayer(firstPlayer, secondPlayer);
            }
            else
            {
                printf("Invalid input! Try again!\n");
            }
            printf("Enter 1 to restart or any other key to exit: ");
            scanf("%d", &restart);
            system("clear");
        }
        ///////////////////////////////////
        else if (gameType == 2)
        {
            printf("\n// Enter 1 for Rock //\n");
            printf("// Enter 2 for Paper //\n");
            printf("// Enter 3 for Scissors //\n");
            printf("/////////////////////////////////////////\n");

            printf("Player : ");
            scanf("%d", &player);
            system("clear");

            if (player == 1 || player == 2 || player == 3)
            {
                srand(time(0));
                computer = (rand() % 3 + 1);
                vsComputer(player, computer);
            }
            //////////////////////////////////
            else
            {
                printf("invalid input");
            }
            printf("\ninput 1 to continue: ");
            scanf("%d", &restart);
        }
    } while (restart == 1);

    return 0;
}
