#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct City {
    char name[50];
    int population;
    struct City *left;
    struct City *right;
} City;


typedef struct Country {
    char name[50];
    City *cities;
    struct Country *next;
} Country;


City* createCity(char *name, int population) {
    City *newCity = (City*)malloc(sizeof(City));
    strcpy(newCity->name, name);
    newCity->population = population;
    newCity->left = NULL;
    newCity->right = NULL;
    return newCity;
}


City* insertCity(City *root, char *name, int population) {
    if (root == NULL) {
        return createCity(name, population);
    }
    if (population < root->population || (population == root->population && strcmp(name, root->name) < 0)) {
        root->left = insertCity(root->left, name, population);
    } else {
        root->right = insertCity(root->right, name, population);
    }
    return root;
}


Country* createCountry(char *name) {
    Country *newCountry = (Country*)malloc(sizeof(Country));
    strcpy(newCountry->name, name);
    newCountry->cities = NULL;
    newCountry->next = NULL;
    return newCountry;
}


Country* insertCountry(Country *head, char *name) {
    Country *newCountry = createCountry(name);
    if (head == NULL || strcmp(name, head->name) < 0) {
        newCountry->next = head;
        return newCountry;
    }
    Country *current = head;
    while (current->next != NULL && strcmp(name, current->next->name) > 0) {
        current = current->next;
    }
    newCountry->next = current->next;
    current->next = newCountry;
    return head;
}


void printCities(City *root) {
    if (root == NULL) {
        return;
    }
    printCities(root->left);
    printf("  %s (%d)\n", root->name, root->population);
    printCities(root->right);
}


void printCountries(Country *head) {
    while (head != NULL) {
        printf("%s:\n", head->name);
        printCities(head->cities);
        head = head->next;
    }
}


void searchCities(City *root, int population) {
    if (root == NULL) {
        return;
    }
    searchCities(root->left, population);
    if (root->population > population) {
        printf("  %s (%d)\n", root->name, root->population);
    }
    searchCities(root->right, population);
}


int main() {
    FILE *file = fopen("drzave.txt", "r");
    if (file == NULL) {
        printf("Greška pri otvaranju datoteke 'drzave.txt'!\n");
        return 1;
    }

    Country *countries = NULL;
    char countryName[50], cityFileName[50];

    
    while (fscanf(file, "%s %s", countryName, cityFileName) == 2) {
        countries = insertCountry(countries, countryName);

        
        FILE *cityFile = fopen(cityFileName, "r");
        if (cityFile == NULL) {
            printf("Greška pri otvaranju datoteke '%s'!\n", cityFileName);
            continue;
        }

        char cityName[50];
        int population;

        
        Country *currentCountry = countries;
        while (currentCountry != NULL && strcmp(currentCountry->name, countryName) != 0) {
            currentCountry = currentCountry->next;
        }

        if (currentCountry != NULL) {
            while (fscanf(cityFile, "%s %d", cityName, &population) == 2) {
                currentCountry->cities = insertCity(currentCountry->cities, cityName, population);
            }
        }

        fclose(cityFile);
    }
    fclose(file);

    
    printf("Države i gradovi:\n");
    printCountries(countries);

    
    char searchCountry[50];
    int minPopulation;

    printf("\nUnesite naziv države za pretragu: ");
    scanf("%s", searchCountry);
    printf("Unesite minimalni broj stanovnika: ");
    scanf("%d", &minPopulation);

    Country *current = countries;
    while (current != NULL && strcmp(current->name, searchCountry) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Država '%s' nije pronađena!\n", searchCountry);
    } else {
        printf("Gradovi u državi '%s' s više od %d stanovnika:\n", searchCountry, minPopulation);
        searchCities(current->cities, minPopulation);
    }

    return 0;
}
