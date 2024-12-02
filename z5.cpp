#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Greška: Nema dovoljno memorije.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}


int pop(Node** top) {
    if (*top == NULL) {
        printf("Greška: Stog je prazan.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}


int isEmpty(Node* top) {
    return top == NULL;
}


int evaluatePostfix(char* expression) {
    Node* stack = NULL; 

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == ' ') {
            continue;
        }
        if (isdigit(ch)) {
            int num = 0;

            
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; 
            push(&stack, num);
        } 
     
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (ch) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Greška: Dijeljenje s nulom.\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, val1 / val2); 
                    break;
                default:
                    printf("Greška: Nevažeći operator '%c'.\n", ch);
                    exit(EXIT_FAILURE);
            }
        }
    }
    int result = pop(&stack);

    if (!isEmpty(stack)) {
        printf("Greška: Nevažeći izraz.\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

int main() {
    char filename[100];
    printf("Unesite naziv datoteke: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Greška: Nije moguće otvoriti datoteku %s.\n", filename);
        return EXIT_FAILURE;
    }

    char expression[1000];
    if (!fgets(expression, sizeof(expression), file)) {
        printf("Greška: Nevažeći sadržaj datoteke.\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    int result = evaluatePostfix(expression);
    printf("Rezultat postfiksnog izraza je: %d\n", result);

    return 0;
}
