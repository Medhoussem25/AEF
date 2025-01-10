#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node in the linked list
typedef struct Node {
    char letterOrDigit;
    struct Node *next;
} Node;

// Definition of the Automaton structure
typedef struct Automaton {
    Node *head;
} Automaton;

// Function prototypes
Automaton *createAutomaton();
void addCharacter(Automaton *automaton, char inputChar);
void displayAutomaton(Automaton *automaton);
void freeAutomaton(Automaton *automaton);
void processInput(Automaton *automaton, const char *inputWord);

int main(void) {
    printf("Project: Finite State Automaton (FSA) using ArrayList.\n");
    printf("Houssem Bouagal\n\n");

    char inputWord[255];
    while (1) {
        printf("Veuillez entrer un mot à tester (ou 'exit' pour quitter) : ");
        if (scanf("%254s", inputWord) != 1) {
            printf("Erreur lors de la saisie.\n");
            return EXIT_FAILURE;
        }

        if (strcmp(inputWord, "exit") == 0) {
            printf("Fin du programme.\n");
            break;
        }

        Automaton *myAutomaton = createAutomaton();
        processInput(myAutomaton, inputWord);
        freeAutomaton(myAutomaton);
    }

    return 0;
}

// Function to create a new Automaton
Automaton *createAutomaton() {
    Automaton *automaton = malloc(sizeof(*automaton));
    if (!automaton) {
        perror("Échec d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    automaton->head = NULL;
    return automaton;
}

// Function to add a character to the Automaton
void addCharacter(Automaton *automaton, char inputChar) {
    Node *newNode = malloc(sizeof(*newNode));
    if (!newNode) {
        perror("Échec d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    newNode->letterOrDigit = inputChar;
    newNode->next = NULL;

    if (!automaton->head) {
        automaton->head = newNode;
    } else {
        Node *current = automaton->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the Automaton
void displayAutomaton(Automaton *automaton) {
    if (!automaton || !automaton->head) {
        printf("Automate vide.\n");
        return;
    }
    Node *current = automaton->head;
    while (current) {
        printf("%c -> ", current->letterOrDigit);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the Automaton
void freeAutomaton(Automaton *automaton) {
    if (!automaton) return;
    Node *current = automaton->head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(automaton);
}

// Function to process the input word and display results
void processInput(Automaton *automaton, const char *inputWord) {
    int sum = 0;
    size_t length = strlen(inputWord);

    for (size_t i = 0; i < length; i++) {
        addCharacter(automaton, inputWord[i]);
    }

    printf("Automate construit :\n");
    displayAutomaton(automaton);

    Node *current = automaton->head;
    while (current) {
        if (isalpha(current->letterOrDigit)) {
            sum += 1;
        } else if (isdigit(current->letterOrDigit)) {
            sum -= 1;
        }

        if (sum == 2 || sum == -2) {
            break;
        }
        current = current->next;
    }

    if (sum == 0) {
        printf("\nMot reconnu comme un pseudo-identifiant bien formé !\n");
    } else if (sum == 2) {
        printf("\nERREUR : Deux lettres consécutives dans l'entrée !\n");
    } else if (sum == -2) {
        int hasLetter = 0;
        Node *lastNode = automaton->head;

        while (lastNode->next) {
            if (isalpha(lastNode->letterOrDigit)) {
                hasLetter = 1;
            }
            lastNode = lastNode->next;
        }

        if (hasLetter) {
            printf("\nERREUR : Entrée mixte non valide (lettres et chiffres) !\n");
        } else if (strchr("13579", lastNode->letterOrDigit)) {
            printf("\nEntrée reconnue : Nombre impair !\n");
        } else {
            printf("\nERREUR : Nombre pair !\n");
        }
    }
}
