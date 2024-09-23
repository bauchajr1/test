#include <stdio.h>
#include <stdlib.h>

void game(int p1, int p2) {
    if ((p1 == 1 && p2 == 3) || 
        (p1 == 2 && p2 == 1) || 
        (p1 == 3 && p2 == 2)) {
        printf("Player 1 wins!\n");
    } 
    else if ((p2 == 1 && p1 == 3) || 
             (p2 == 2 && p1 == 1) || 
             (p2 == 3 && p1 == 2)) {
        printf("Player 2 wins!\n");
    } 
    else {
        printf("It's a tie\n");
    }
}

int main() {
    int p1, p2, reSTRT;

    do {
        printf("// Enter 1 for Rock //\n");
        printf("// Enter 2 for Paper //\n");
        printf("// Enter 3 for Scissors //\n");
        printf("/////////////////////////////////////////\n");

        printf("Player 1: ");
        scanf("%d", &p1);
        system("clear"); 

        printf("// Enter 1 for Rock //\n");
        printf("// Enter 2 for Paper //\n");
        printf("// Enter 3 for Scissors //\n");
        printf("/////////////////////////////////////////\n");

        printf("Player 2: ");
        scanf("%d", &p2);
        system("clear");

        if ((p1 == 1 || p1 == 2 || p1 == 3) && (p2 == 1 || p2 == 2 || p2 == 3)) {
            game(p1, p2);
        } else {
            printf("Invalid input! Try again!\n");
        }
        printf("Enter 1 to restart or any other key to exit: ");
        scanf("%d", &reSTRT);
        system("clear");

    } while (reSTRT == 1);

    return 0;
}