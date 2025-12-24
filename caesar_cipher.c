#include <stdio.h>
#include <string.h>

void caesarEncrypt(char text[], int key) {
    int i;
    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }
}

void caesarDecrypt(char text[], int key) {
    int i;
    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int key, choice;

    printf("Enter text: ");
    gets(text);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter choice (0 = Encrypt, 1 = Decrypt): ");
    scanf("%d", &choice);

    if(choice == 0) {
        caesarEncrypt(text, key);
        printf("Encrypted text: %s", text);
    }
    else if(choice == 1) {
        caesarDecrypt(text, key);
        printf("Decrypted text: %s", text);
    }
    else {
        printf("Invalid choice");
    }

    return 0;
}


