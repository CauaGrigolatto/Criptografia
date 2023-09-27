/*
    -------  Projeto 1 -----

    Cauã Grigolatto Domingos
    Gabriel VEntura Pires
*/

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define CIFER_POSITIONS 3 //letter + 3
#define TRUE 1
#define FALSE 0

void encrypt(char message[100], char ciferMessage[100]);
void initializeCiferAlphabet(char alphabetCipher[ALPHABET_SIZE], char letter);
void initializeAlphabet(char alphabetLetters[ALPHABET_SIZE], char letter);
void printLetters(char letters[ALPHABET_SIZE]); //for tests only

int main()
{
    char message[100];
    char ciferMessage[100];

    printf("Informe a mensagem: ");
    scanf("%[^\n]", message);
    getchar();

    encrypt(message, ciferMessage);
    printf("\n\n");
    printf("Mensagem original......: %s\n", message);
    printf("Mensagem criptografada.: %s\n", ciferMessage);

    return 0;
}

void encrypt(char message[100], char ciferMessage[100]) {    
    char upperLetters[ALPHABET_SIZE];
    char lowerLetters[ALPHABET_SIZE];
    
    char lowerCiferLetters[ALPHABET_SIZE];
    char upperCiferLetters[ALPHABET_SIZE];

    initializeAlphabet(upperLetters, 'A');
    initializeAlphabet(lowerLetters, 'a');

    initializeCiferAlphabet(lowerCiferLetters, ('a' + CIFER_POSITIONS));
    initializeCiferAlphabet(upperCiferLetters, ('A' + CIFER_POSITIONS));

    int i = 0;
    int j;
    char currentLetter, ciferLetter;

    int letterExists;

    while (message[i] != '\0') {
        j = 0;
        currentLetter = message[i];
        letterExists = FALSE;

        while ((j < ALPHABET_SIZE) && (! letterExists)) {
            
            if (currentLetter == upperLetters[j]) {
                ciferLetter = upperCiferLetters[j];
                letterExists = TRUE;
            }
            else if (currentLetter == lowerLetters[j]) {
                ciferLetter = lowerCiferLetters[j];
                letterExists = TRUE;
            }
            else {
                ciferLetter = currentLetter;
            }

            j++;
        }

        ciferMessage[i] = ciferLetter;
        i++;
    }

    ciferMessage[i] = '\0';
}

void initializeCiferAlphabet(char alphabetCipher[ALPHABET_SIZE], char letter) {
    char lastUpperLetter = 'Z', firstUpperLetter = 'A';
    char lastLowerLetter = 'z', firstLowerLetter = 'a';

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        alphabetCipher[i] = letter;

        if (letter == lastUpperLetter) {
            letter = firstUpperLetter;
        }
        else if (letter == lastLowerLetter) {
            letter = firstLowerLetter;
        }
        else {
            letter++;
        }
    }
}

void initializeAlphabet(char alphabetLetters[ALPHABET_SIZE], char letter) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        alphabetLetters[i] = letter;
        letter++;
    }  
}

void printLetters(char letters[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");
}