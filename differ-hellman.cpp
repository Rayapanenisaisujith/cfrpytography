#include <stdio.h>
#include <stdlib.h>

// Function to calculate (base^exponent) % modulus
long long int power(long long int base, long long int exponent, long long int modulus) {
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        long long int temp = power(base, exponent / 2, modulus);
        return (temp * temp) % modulus;
    } else {
        return (base * power(base, exponent - 1, modulus)) % modulus;
    }
}

// Function to perform the Diffie-Hellman key exchange
void diffieHellmanKeyExchange(int q, int alpha, int a_private, int b_private) {
    // Calculate public keys
    int a_public = power(alpha, a_private, q);
    int b_public = power(alpha, b_private, q);

    // Calculate the shared secret key
    int shared_secret_Alice = power(b_public, a_private, q);
    int shared_secret_Bob = power(a_public, b_private, q);

    // Display results
    printf("Publicly Shared Parameters:\n");
    printf("q (prime): %d\n", q);
    printf("alpha (primitive root): %d\n\n", alpha);

    printf("Private Keys:\n");
    printf("Alice's private key: %d\n", a_private);
    printf("Bob's private key: %d\n\n", b_private);

    printf("Public Keys:\n");
    printf("Alice's public key: %d\n", a_public);
    printf("Bob's public key: %d\n\n", b_public);

    printf("key generations:\n");
    printf("Shared secret key for Alice: %d\n", shared_secret_Alice);
    printf("Shared secret key for Bob: %d\n", shared_secret_Bob);
}

int main() {
    // Get input from the user
    int q, alpha, a_private, b_private;

    printf("Enter the prime number (q): ");
    scanf("%d", &q);

    printf("Enter the primitive root (alpha): ");
    scanf("%d", &alpha);

    printf("Enter Alice's private key x(a): ");
    scanf("%d", &a_private);

    printf("Enter Bob's private key x(b): ");
    scanf("%d", &b_private);

    diffieHellmanKeyExchange(q, alpha, a_private, b_private);

    return 0;
}

