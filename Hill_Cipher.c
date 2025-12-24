#include <stdio.h>
#include <string.h>

void hillEncrypt(char text[], int key[2][2], int len) {
    int i, a, b;

    for(i = 0; i < len; i++)
        text[i] = text[i] - 'A';

    for(i = 0; i < len; i += 2) {
        a = text[i];
        b = text[i + 1];

        text[i]     = (a * key[0][0] + b * key[0][1]) % 26;
        text[i + 1] = (a * key[1][0] + b * key[1][1]) % 26;
    }

    for(i = 0; i < len; i++)
        text[i] = text[i] + 'A';

    printf("Encrypted text: %s\n", text);
}

void hillDecrypt(char text[], int invKey[2][2], int len) {
    int i, a, b;

    for(i = 0; i < len; i++)
        text[i] = text[i] - 'A';

    for(i = 0; i < len; i += 2) {
        a = text[i];
        b = text[i + 1];

        text[i]     = (a * invKey[0][0] + b * invKey[0][1]) % 26;
        text[i + 1] = (a * invKey[1][0] + b * invKey[1][1]) % 26;
    }

    for(i = 0; i < len; i++)
        text[i] = (text[i] + 26) % 26 + 'A';

    printf("Decrypted text: %s\n", text);
}

int main() {
    int key[2][2] = {{2,3},{1,4}};
    int invKey[2][2]={{6,15},{5,16}};

    char text[100];
    int len, ch;

    printf("Enter text: ");
    gets(text);

    len = strlen(text);

    if(len % 2 != 0) {
        text[len] = 'X';
        text[len + 1] = '\0';
        len++;
    }

    printf("1. Encrypt  2. Decrypt: ");
    scanf("%d", &ch);

    if(ch == 1)
        hillEncrypt(text, key, len);
    else if(ch == 2)
        hillDecrypt(text, invKey, len);
    else
        printf("Invalid choice");

    return 0;
}
