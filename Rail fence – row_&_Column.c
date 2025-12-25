#include <stdio.h>
#include <string.h>

void encrypt(char *text, int row, int col, char *cipher) {
    int len = strlen(text);
    char grid[row][col];
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < len)
                grid[i][j] = text[k++];
            else
                grid[i][j] = 'X';
        }
    }
    k = 0;
    for (int j = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipher[k++] = grid[i][j];
    cipher[k] = '\0';
}

void decrypt(char *cipher, int row, int col, char *plain) {
    char grid[row][col];
    int k = 0;
    for (int j = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            grid[i][j] = cipher[k++];
    k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            plain[k++] = grid[i][j];
    plain[k] = '\0';
}

int main() {
    char text[100], cipher[100], plain[100];
    int row, col;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    encrypt(text, row, col, cipher);
    printf("Encrypted Text: %s\n", cipher);

    decrypt(cipher, row, col, plain);
    printf("Decrypted Text: %s\n", plain);

    return 0; 
}