#include <stdio.h>


long long modPower(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int modInverse(int e, int phi)
{
    for (int d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main()
{
    int p, q, n, phi, e, d, M, C, P, choice;

    printf("Enter first prime number: ");
    scanf("%d", &p);

    printf("Enter second prime number: ");
    scanf("%d", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter public key e: ");
    scanf("%d", &e);

 
    while (e <= 1 || e >= phi || gcd(e, phi) != 1)
    {
        printf("Invalid e! Enter again (1 < e < %d and gcd(e, %d)=1): ", phi, phi);
        scanf("%d", &e);
    }

    d = modInverse(e, phi);

    printf("\nPublic Key  = (%d, %d)", e, n);
    printf("\nPrivate Key = (%d, %d)\n", d, n);

    printf("\nEnter 0 for Encryption or 1 for Decryption: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        printf("Enter your plain text (number < %d): ", n);
        scanf("%d", &M);

        C = modPower(M, e, n);
        printf("Cipher Text = %d\n", C);
    }
    else if (choice == 1)
    {
        printf("Enter your cipher text: ");
        scanf("%d", &C);

        P = modPower(C, d, n);
        printf("Plain Text = %d\n", P);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
