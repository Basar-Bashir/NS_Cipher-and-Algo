#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyTable[5][5];

void prepareKey(char key[]) {
    int map[26] = {0}, i, j, k = 0;
    map['J' - 'A'] = 1;
    for (i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c < 'A' || c > 'Z') continue;
        if (!map[c - 'A']) keyTable[k / 5][k % 5] = c, map[c - 'A'] = 1, k++;
    }
    for (i = 0; i < 26; i++) if (!map[i]) keyTable[k / 5][k % 5] = 'A' + i, k++;
}

void printKey() {
    int i, j;
    printf("\nKey Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) printf("%c ", keyTable[i][j]);
        printf("\n");
    }
}

void findPos(char c, int *r, int *c1) {
    int i, j;
    if (c == 'J') c = 'I';
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (keyTable[i][j] == c) *r = i, *c1 = j;
}

void process(char text[], int enc) {
    int i, r1, c1, r2, c2;
    for (i = 0; text[i]; i++) text[i] = toupper(text[i]);
    char out[100] = "";
    for (i = 0; i < strlen(text); i += 2) {
        char a = text[i], b = (i + 1 < strlen(text)) ? text[i + 1] : 'X';
        if (a == b) b = 'X';
        findPos(a, &r1, &c1); findPos(b, &r2, &c2);
        if (r1 == r2)
            sprintf(out + strlen(out), "%c%c", keyTable[r1][(c1 + enc + 5) % 5], keyTable[r2][(c2 + enc + 5) % 5]);
        else if (c1 == c2)
            sprintf(out + strlen(out), "%c%c", keyTable[(r1 + enc + 5) % 5][c1], keyTable[(r2 + enc + 5) % 5][c2]);
        else
            sprintf(out + strlen(out), "%c%c", keyTable[r1][c2], keyTable[r2][c1]);
    }
    printf("\nResult: %s\n", out);
}

int main() {
    char key[100], text[100];
    int ch;
    printf("Enter key: "); gets(key);
    prepareKey(key);
    printKey();
    printf("\n1.Encrypt 2.Decrypt: "); scanf("%d", &ch); getchar();
    printf("Enter text: "); gets(text);
    process(text, ch == 1 ? 1 : -1);
    return 0;
}
