#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH);
    scanf("%s", username);

    printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    // Save on file
    FILE *file = fopen("ra.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", username, password);
        fclose(file);
        printf("User registered successfully.\n");
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
    } else {
        printf("Error: Unable to open file for writing.\n");
    }
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Check the match
    FILE *file = fopen("ra.txt", "r");
    if (file != NULL) {
        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
            if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
                printf("Login successful., %s\n", username);
                found = 1;
                break;
            }
        }

        fclose(file);

        if (!found) {
            printf("Invalid username or password. \n");
        }
    } else {
        printf("file can't found\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Visit Us Again.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}