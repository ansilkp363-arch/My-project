#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesarCipher(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            text[i] = ((text[i] - 'A' + shift + 26) % 26) + 'A';
        }
        else if (islower(text[i])) {
            text[i] = ((text[i] - 'a' + shift + 26) % 26) + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift, choice;

    while (1) {
        printf("\n--- Caesar Cipher ---\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        getchar();   // clear newline from buffer

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter message: ");
        fgets(text, sizeof(text), stdin);

        printf("Enter shift value: ");
        scanf("%d", &shift);
        getchar();   // clear newline

        if (choice == 1) {
            caesarCipher(text, shift);
            printf("Encrypted message: %s", text);
        }
        else if (choice == 2) {
            caesarCipher(text, -shift);
            printf("Decrypted message: %s", text);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}