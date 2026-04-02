#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

int checkPosition(int pos) {
    // Ladders
    if (pos == 3) return 22;
    if (pos == 5) return 8;
    if (pos == 11) return 26;
    if (pos == 20) return 29;

    // Snakes
    if (pos == 27) return 1;
    if (pos == 21) return 9;
    if (pos == 17) return 4;
    if (pos == 19) return 7;

    return pos;
}

int main() {
    int player = 0, dice;

    srand(time(0));

    printf("🎮 Welcome to Snake & Ladder Game!\n");

    while (player < 100) {
        printf("\nPress ENTER to roll dice...");
        getchar();

        dice = rollDice();
        printf("You rolled: %d\n", dice);

        player += dice;

        if (player > 100) {
            player -= dice;
            printf("Can't move beyond 100!\n");
        } else {
            player = checkPosition(player);
        }

        printf("Your position: %d\n", player);
    }

    printf("\n🎉 You reached 100! You win!\n");

    return 0;
}