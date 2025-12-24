#include <stdio.h>
#include <string.h>
#include <ctype.h>


void encrypt(char* text, char* key, char* out) {
    int n = strlen(text);
    int m = strlen(key);
    for (int i = 0, j = 0; i < n; i++) {
        if (isalpha(text[i])) {
            out[i] = ((text[i] - 'A') + (key[j % m] - 'A')) % 26 + 'A';
            j++;
        } else {
            out[i] = text[i]; 
        }
    }
    out[n] = '\0';
}


void decrypt(char* text, char* key, char* out) {
    int n = strlen(text);
    int m = strlen(key);
    for (int i = 0, j = 0; i < n; i++) {
        if (isalpha(text[i])) {
            out[i] = ((text[i] - 'A') - (key[j % m] - 'A') + 26) % 26 + 'A';
            j++;
        } else {
            out[i] = text[i]; 
        }
    }
    out[n] = '\0';
}

int main() {
    char text[101], key[101], result[101];
    int choice,text_length,key_length;
    printf("Enter text: ");
    gets(text);
    printf("Enter key: ");
    gets(key);
    text_length = strlen(text);
    key_length = strlen(key);
    for(int i=0; i<text_length; i++) {
        text[i] = toupper(text[i]);
    }
    for(int i=0; i<key_length; i++) {
        key[i] = toupper(key[i]);
    }
    
    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    if(choice == 1) {
        encrypt(text, key, result);
        printf("Encrypted Text: %s\n", result);
    } else if(choice == 2) {
        decrypt(text, key, result);
        printf("Decrypted Text: %s\n", result);
    } else {
        printf("Invalid choice\n");
    }
    
    return 0;
}