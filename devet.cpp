#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


int replace(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = replace(root->left);
    int rightSum = replace(root->right);
    int oldValue = root->value;
    root->value = leftSum + rightSum;
    return oldValue + root->value;
}

void inorder(Node *root, FILE *file) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, file);
    fprintf(file, "%d ", root->value);
    inorder(root->right, file);
}

int main() {
    /
    int array[] = {2, 5, 7, 8, 11, 1, 4, 2, 3, 7};
    int n = sizeof(array) / sizeof(array[0]);
    Node *root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, array[i]);
    }


    replace(root);

    
    srand(time(NULL));
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Greška pri otvaranju datoteke!\n");
        return 1;
    }

    fprintf(file, "Inorder prolazak nakon zamjene:\n");
    inorder(root, file);
    fprintf(file, "\n");

    
    Node *randomRoot = NULL;
    for (int i = 0; i < n; i++) {
        int randomValue = rand() % 81 + 10; 
        randomRoot = insert(randomRoot, randomValue);
    }

    fprintf(file, "Inorder prolazak sa slučajnim brojevima:\n");
    inorder(randomRoot, file);

    fclose(file);

    printf("Program uspješno izvršen! Rezultati su zapisani u datoteku 'output.txt'.\n");
    return 0;
}
