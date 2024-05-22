#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    srand(time(NULL));
    int randomNumber = rand() % 10 + 1;
    int num;
    int i, chance = 3;
    for (i = 1; i <= 3; i++)
    {
        printf("chances: %d", chance);
        printf("\nenter  a positive number from 1-10 :");
        scanf("%d", &num);
        if (num == randomNumber)
        {
            printf("\ncongratulation ur guess was correct");
            break;
        }
        else if (num > 10 || num < 1)
        {
           system("clear");
            printf("invalid input\n ");
            --chance;
        }
        else
        {
            printf("incorrect guess try again");
            chance--;
            clrscr();
        }
    }
    return 0;
}