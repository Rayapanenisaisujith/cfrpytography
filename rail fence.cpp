#include <stdio.h>
#include <string.h>

void encryptRailFence(char *text, int railKey, char *cipherText) {
    int len = strlen(text);
    int k = 0;

    for (int i = 0; i < railKey; ++i) {
        int j = i;
        while (j < len) {
            cipherText[k++] = text[j];

            if (i != 0 && i != railKey - 1) {
                int temp = j + 2 * (railKey - i - 1);
                if (temp < len)
                    cipherText[k++] = text[temp];
            }
            j += 2 * (railKey - 1);
        }
    }
    cipherText[k] = '\0';
}


void decryptRailFence(char *cipherText, int railKey, char *decryptedText) {
    int len = strlen(cipherText);
    int k = 0;

    for (int i = 0; i < railKey; ++i) {
        int j = i;
        while (j < len) {
            decryptedText[j] = cipherText[k++];
            
            if (i != 0 && i != railKey - 1) {
                int temp = j + 2 * (railKey - i - 1);
                if (temp < len)
                    decryptedText[temp] = cipherText[k++];
            }
            j += 2 * (railKey - 1);
        }
    }
    decryptedText[len] = '\0';
}

int main() {
    char text[100], cipherText[100], decryptedText[100];
    int railKey;

    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    printf("Enter the rail key: ");
    scanf("%d", &railKey);

    encryptRailFence(text, railKey, cipherText);
    printf("Encrypted text: %s\n", cipherText);

    decryptRailFence(cipherText, railKey, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}

