#include <stdio.h>

int P10[10] = {3,5,2,7,4,10,1,9,8,6};
int P8[8]  = {6,3,7,4,8,5,10,9};
int P4[4]  = {2,4,3,1};
int IP[8]  = {2,6,3,1,4,8,5,7};
int IPinv[8] = {4,1,3,5,7,2,8,6};
int EP[8]  = {4,1,2,3,2,3,4,1};

int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

void permute(int in[], int out[], int p[], int n) {
    for(int i=0;i<n;i++) out[i] = in[p[i]-1];
}

void leftShift(int k[]) {
    int t1=k[0], t2=k[1];
    for(int i=0;i<4;i++) k[i]=k[i+1];
    k[4]=t1; k[5]=t2;
}

void sbox(int in[], int out[], int box[4][4]) {
    int row = in[0]*2 + in[3];
    int col = in[1]*2 + in[2];
    int val = box[row][col];
    out[0] = (val & 2) >> 1;
    out[1] =  val & 1;
}

void fk(int in[], int out[], int key[]) {
    int L[4], R[4], ER[8], A[8], s0i[4], s1i[4], P4out[4];

    for(int i=0;i<4;i++) L[i]=in[i];
    for(int i=0;i<4;i++) R[i]=in[i+4];

    permute(R, ER, EP, 8);

    for(int i=0;i<8;i++) A[i] = ER[i] ^ key[i];

    sbox(A,   s0i, S0);
    sbox(A+4, s1i, S1);

    int s[4] = {s0i[0], s0i[1], s1i[0], s1i[1]};
    permute(s, P4out, P4, 4);

    for(int i=0;i<4;i++)
        out[i] = L[i] ^ P4out[i];

    for(int i=0;i<4;i++)
        out[i+4] = R[i];
}

void getKey(char key10[], int K1[], int K2[]) {
    int key[10], p10[10];

    for(int i=0;i<10;i++) key[i] = key10[i]-'0';

    permute(key, p10, P10, 10);

    int L[5], R[5];
    for(int i=0;i<5;i++){ L[i]=p10[i]; R[i]=p10[i+5]; }

    leftShift(L); leftShift(R);

    int LS1[10];
    for(int i=0;i<5;i++){ LS1[i]=L[i]; LS1[i+5]=R[i]; }
    permute(LS1, K1, P8, 8);

    leftShift(L); leftShift(R);

    int LS2[10];
    for(int i=0;i<5;i++){ LS2[i]=L[i]; LS2[i+5]=R[i]; }
    permute(LS2, K2, P8, 8);
}

int main() {
    char key10[11], plaintext[9];
    int K1[8], K2[8];
    int pt[8], ip[8], fk1[8], sw[8], fk2[8], cipher[8];

    printf("Enter 10-bit key: ");
    scanf("%s", key10);

    printf("Enter 8-bit plaintext: ");
    scanf("%s", plaintext);

    getKey(key10, K1, K2);

    for(int i=0;i<8;i++) pt[i] = plaintext[i] - '0';

    permute(pt, ip, IP, 8);

    fk(ip, fk1, K1);

    for(int i=0;i<4;i++){ sw[i]=fk1[i+4]; sw[i+4]=fk1[i]; }

    fk(sw, fk2, K2);

    permute(fk2, cipher, IPinv, 8);

    printf("Ciphertext = ");
    for(int i=0;i<8;i++) printf("%d", cipher[i]);
    printf("\n");

    return 0;
}