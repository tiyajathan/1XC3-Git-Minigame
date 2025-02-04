#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char username[20] = "user";
char password[20] = "pass";

int get_random_number() {
    // Generate a random number between 10 and 50
    srand(time(NULL));
    return rand() % 40 + 10;
}

int main_menu() {
    printf("1. The + game\n");
    printf("2. The - game\n");
    printf("3. The * game\n");
    printf("4. The / game\n");
    printf("5. Change username\n");
    printf("6. Change password\n");
    printf("7. Logout\n");
    printf("8. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int login() {
    char input_username[20];
    char input_password[20];

    printf("Enter your username: ");
    scanf("%s", input_username);
    printf("Enter your password: ");
    scanf("%s", input_password);

    // TODO: use a loop to check username and password
    // If the user enters the wrong username or password 3 times, return 0
    // If the login is successful but the user is using the default username and password,
    // ask the user to change the username and password and return 1
    // If the login is successful, return 1

    int attempts = 3;
    while (1) {
        if (strcmp(input_username, username) == 1 && strcmp(input_password, password) == 0) {
            if (strcmp(input_username, "user") == 0 && strcmp(input_password, "pass") == 0) {
                printf("You are using the default login details, you can now change your username and password.\n");
                printf("Please enter a new username: ");
                scanf("%s", username);
                printf("Please enter a new password: ");
                scanf("%s", password);
                return 1;
            }
            else {
                return 1;
            }

        } else {
            printf("Invalid username or password, try again.\n");
            printf("Attempts left: %d\n", attempts);
            attempts--;

            if (attempts == 0) {
                printf("You have exceeded the number of attempts.\n");
                return 0;
            }
        }
    }

    return 0;
}

void plus_game() {
    // TODO: declare a counter to count how many correct answers the user has given
    int i;
    for (i = 0; i < 10; i++) {
        int a = get_random_number();
        int b = get_random_number();
        int result = a + b;
        int user_result;
        printf("%d + %d = ", a, b);
        scanf("%d", &user_result);
        
        // TODO: check if the user's answer is correct
    }

    // TODO: print the number of correct answers and the accuracy of the user
    // E.g. "You have answered 7 questions correctly. Your accuracy is 70%"
}

void minus_game() {

}

void multiply_game() {

}

void divide_game() {

}

void change_username() {

}

void change_password() {

}

int main() {
    int logged_in = 0;

    while (1) {
        if (!logged_in) {
            // Login process
            printf("Please login\n");
            if (!login()) {
                printf("Login failed\n");
                return 1;
            }
            logged_in = 1;
            // TODO: print "welcone, <username>"
            printf("Welcome, %s\n", username);
        }
        
        // Main menu
        int choice = main_menu();
        // TODO: check user's choice and invoke the corresponding function
        // If the user has entered an invalid choice, print "Invalid choice"
        switch (choice) {
            case 1:
                plus_game();
                break;
            case 2:
                minus_game();
                break;
            case 3:
                multiply_game();
                break;
            case 4:
                divide_game();
                break;
            case 5:
                change_username();
                break;
            case 6:
                change_password();
                break;
            case 7:
                logged_in = 0;
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}