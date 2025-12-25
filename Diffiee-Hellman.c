#include <stdio.h>
#include <stdlib.h>

// Function to compute (base^exp) % mod using modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform Diffie-Hellman key exchange
void diffie_hellman(long long p, long long g, long long x, long long y) {
    // Alice computes A = g^x mod p
    long long A = mod_pow(g, x, p);
    printf("Alice sends A = %lld\n", A);

    // Bob computes B = g^y mod p
    long long B = mod_pow(g, y, p);
    printf("Bob sends B = %lld\n", B);

    // Alice computes shared key = B^x mod p
    long long key_alice = mod_pow(B, x, p);
    printf("Alice computes shared key = %lld\n", key_alice);

    // Bob computes shared key = A^y mod p
    long long key_bob = mod_pow(A, y, p);
    printf("Bob computes shared key = %lld\n", key_bob);

    if (key_alice == key_bob) {
        printf("Key exchange successful! Shared key: %lld\n", key_alice);
    } else {
        printf("Key exchange failed!\n");
    }
}

int main() {
    long long p, g, x, y;

    printf("Enter a large prime number p: ");
    scanf("%lld", &p);

    printf("Enter a generator g (primitive root modulo p): ");
    scanf("%lld", &g);

    printf("Enter Alice's secret key x (1 to %lld): ", p-1);
    scanf("%lld", &x);

    printf("Enter Bob's secret key y (1 to %lld): ", p-1);
    scanf("%lld", &y);

    printf("Diffie-Hellman Key Exchange\n");
    printf("p = %lld, g = %lld\n", p, g);
    printf("Alice's secret x = %lld\n", x);
    printf("Bob's secret y = %lld\n", y);

    diffie_hellman(p, g, x, y);

    return 0;
}
