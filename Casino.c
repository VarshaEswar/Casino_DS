#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ATTEMPTS 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100
int main() {
    int secret_number, guess;
    int attempts = 0;
    int guesses[MAX_ATTEMPTS];
    srand(time(0));
    secret_number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    printf("Welcome to the Casino Number Guessing Game!\n");
    printf("Guess the secret number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have %d attempts.\n\n", MAX_ATTEMPTS);
    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("Please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
            continue;
        }
        guesses[attempts] = guess;
        attempts++;

        if (guess == secret_number) {
            printf("Congratulations! You guessed the secret number %d in %d attempts.\n",
                   secret_number, attempts);
            break;
        } else if (guess < secret_number) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }
    if (guess != secret_number) {
        printf("\nSorry, you've used all %d attempts.\n", MAX_ATTEMPTS);
        printf("The secret number was %d.\n", secret_number);
    }
    printf("\nYour guesses were: ");
    for (int i = 0; i < attempts; i++) {
        printf("%d ", guesses[i]);
    }
    printf("\n");
    return 0;
}
