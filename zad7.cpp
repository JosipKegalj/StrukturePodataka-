#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Directory {
    char name[100];
    struct Directory* parent;
    struct Directory* subdirectories;
    struct Directory* next;
} Directory;

Directory* createDirectory(char* name, Directory* parent) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->parent = parent;
    newDir->subdirectories = NULL;
    newDir->next = NULL;
    return newDir;
}

void makeDirectory(Directory* current, char* name) {
    Directory* newDir = createDirectory(name, current);
    if (!current->subdirectories) {
        current->subdirectories = newDir;
    } else {
        Directory* temp = current->subdirectories;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newDir;
    }
}

Directory* changeDirectory(Directory* current, char* name) {
    if (strcmp(name, "..") == 0) {
        return current->parent ? current->parent : current;
    }

    Directory* temp = current->subdirectories;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    printf("Direktorij '%s' ne postoji!\n", name);
    return current;
}

void listDirectory(Directory* current) {
    printf("Sadržaj direktorija '%s':\n", current->name);
    Directory* temp = current->subdirectories;
    if (!temp) {
        printf("(prazno)\n");
    } else {
        while (temp) {
            printf("%s\n", temp->name);
            temp = temp->next;
        }
    }
}

int main() {
    char command[10], name[100];
    Directory* root = createDirectory("root", NULL);
    Directory* current = root;

    while (1) {
        printf("\nTrenutni direktorij: %s\n", current->name);
        printf("Opcije:\n1. md <ime>\n2. cd <ime>\n3. cd..\n4. dir\n5. izlaz\n");
        printf("Unesite naredbu: ");
        scanf("%s", command);

        if (strcmp(command, "md") == 0) {
            scanf("%s", name);
            makeDirectory(current, name);
        } else if (strcmp(command, "cd") == 0) {
            scanf("%s", name);
            current = changeDirectory(current, name);
        } else if (strcmp(command, "cd..") == 0) {
            current = changeDirectory(current, "..");
        } else if (strcmp(command, "dir") == 0) {
            listDirectory(current);
        } else if (strcmp(command, "izlaz") == 0) {
            break;
        } else {
            printf("Nepoznata naredba!\n");
        }
    }

    return 0;
}
