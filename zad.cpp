#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct Osoba {
    char ime[50];
    char prezime[50];
    int godina_rodenja;
    struct Osoba *next;
} Osoba;


Osoba* dodajNaPocetak(Osoba *head, char *ime, char *prezime, int godina_rodenja) {
    Osoba * nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = head;
    return nova_osoba;

void ispisiListu(Osoba *head) {
    Osoba *temp = head;
    while (temp) {
        printf("Ime: %s, Prezime: %s, Godina rođenja: %d\n", temp->ime, temp->prezime, temp->godina_rodenja);
        temp = temp->next;
    }
}


Osoba* dodajNaKraj(Osoba *head, char *ime, char *prezime, int godina_rodenja) {
    Osoba * nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = NULL;

    if (head == NULL)
        return nova_osoba;

    Osoba *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = nova_osoba;
    return head;
}

Osoba* pronadiElement(Osoba *head, char *prezime) {
    Osoba *temp = head;
    while (temp) {
        if (strcmp(temp->prezime, prezime) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


Osoba* obrisiElement(Osoba *head, char *prezime) {
    Osoba *temp = head, *prev = NULL;

    while (temp && strcmp(temp->prezime, prezime) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Osoba s prezimenom %s nije pronađena.\n", prezime);
        return head;
    }

    if (!prev) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return head;
}

Osoba* dodajIza(Osoba *head, char *ime, char *prezime, int godina_rodenja, char *targetPrezime) {
    Osoba *target = pronadiElement(head,targetPrezime);
    if (!target) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = target->next;
    target->next = nova_osoba;

Osoba* dodajIspred(Osoba *head, char *ime, char *prezime, int godina_rodenja, char *targetPrezime) {
     Osoba * nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
   
     if(!head||strcmp(head->prezime,targetPrezime)==0)
     {
         nova_osoba->next = head;
         return nova_osoba;
     }

   Osoba *temp=head; 
   while(temp->next&&strcmp(temp->next->prezime, targetPrezime)!=0)
   { temp=temp->next;}


   if(!temp->next)
   {
       printf("Osoba s prezimenom %s nije pronađena\n",targetPrezime);
       free(nova_osoba);
       return head;
   }
   nova_osoba->next=temp->next;
   temp->next=nova_osoba;
   return head
}
int main() {
    Osoba *head = NULL;
    int izbor;
    char ime[50], prezime[50];
    int godina_rodenja;

    do {
        printf("\nOdaberite opciju:\n");
        printf("1. Dodaj na početak\n");
        printf("2. Ispiši listu\n");

typedef struct Osoba {
    char ime[50];
    char prezime[50];
    int godina_rodenja;
    struct Osoba *next;
} Osoba;


Osoba* dodajNaPocetak(Osoba *head, char *ime, char *prezime, int godina_rodenja) {
    Osoba *nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = head;
    return nova_osoba;
}


void ispisiListu(Osoba *head) {
    Osoba *temp = head;
    while (temp) {
        printf("Ime: %s, Prezime: %s, Godina rođenja: %d\n", temp->ime, temp->prezime, temp->godina_rodenja);
        temp = temp->next;
    }
}


Osoba* dodajNaKraj(Osoba *head, char *ime, char *prezime, int godina_rodenja) {
    Osoba *nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = NULL;

    if (head == NULL)
        return nova_osoba;

    Osoba *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = nova_osoba;
    return head;
}


Osoba* pronadiElement(Osoba *head, char *prezime) {
    Osoba *temp = head;
    while (temp) {
        if (strcmp(temp->prezime, prezime) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


Osoba* obrisiElement(Osoba *head, char *prezime) {
    Osoba *temp = head, *prev = NULL;

    while (temp && strcmp(temp->prezime, prezime) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Osoba s prezimenom %s nije pronađena.\n", prezime);
        return head;
    }

    if (!prev) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return head;
}


Osoba* dodajIzaElementa(Osoba *head, char *ime, char *prezime, int godina_rodenja, char *targetPrezime) {
    Osoba *target = pronadiElement(head, targetPrezime);
    if (!target) {
        printf("Osoba s prezimenom %s nije pronađena.\n", targetPrezime);
        return head;
    }

    Osoba *nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }

    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;
    nova_osoba->next = target->next;
    target->next = nova_osoba;

    return head;
}


Osoba* dodajIspredElementa(Osoba *head, char *ime, char *prezime, int godina_rodenja, char *targetPrezime) {
    Osoba *nova_osoba = (Osoba*)malloc(sizeof(Osoba));
    if (!nova_osoba) {
        printf("Greška pri alokaciji memorije!\n");
        return head;
    }
    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->prezime, prezime);
    nova_osoba->godina_rodenja = godina_rodenja;

    if (!head || strcmp(head->prezime, targetPrezime) == 0) {
        nova_osoba->next = head;
        return nova_osoba;
    }

    Osoba *temp = head;
    while (temp->next && strcmp(temp->next->prezime, targetPrezime) != 0) {
        temp = temp->next;
    }

    if (!temp->next) {
        printf("Osoba s prezimenom %s nije pronađena.\n", targetPrezime);
        free(nova_osoba);
        return head;
    }

    nova_osoba->next = temp->next;
    temp->next = nova_osoba;
    return head;
}


Osoba* sortirajListu(Osoba *head) {
    if (!head || !head->next) return head;

    Osoba *sorted = NULL;

    while (head) {
        Osoba *current = head;
        head = head->next;

        if (!sorted || strcmp(current->prezime, sorted->prezime) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Osoba *temp = sorted;
            while (temp->next && strcmp(temp->next->prezime, current->prezime) < 0)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}

void upisiUDatoteku(Osoba *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Greška pri otvaranju datoteke %s!\n", filename);
        return;
    }

    Osoba *temp = head;
    while (temp) {
        fprintf(file, "%s %s %d\n", temp->ime, temp->prezime, temp->godina_rodenja);
        temp = temp->next;
    }

    fclose(file);
}


Osoba* citajIzDatoteke(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Greška pri otvaranju datoteke %s!\n", filename);
        return NULL;
    }

    Osoba *head = NULL;
    char ime[50], prezime[50];
    int godina_rodenja;

    while (fscanf(file, "%s %s %d", ime, prezime, &godina_rodenja) == 3) {
        head = dodajNaKraj(head, ime, prezime, godina_rodenja);
    }

    fclose(file);
    return head;
}

int main() {
    Osoba *head = NULL;
    int izbor;
    char ime[50], prezime[50], targetPrezime[50];
    int godina_rodenja;

    do {
        printf("\nOdaberite opciju:\n");
        printf("1. Dodaj na početak\n");
        printf("2. Ispiši listu\n");
        printf("3. Dodaj na kraj\n");
        printf("4. Pronađi po prezimenu\n");
        printf("5. Obriši po prezimenu\n");
        printf("6. Dodaj iza određenog elementa\n");
        printf("7. Dodaj ispred određenog elementa\n");
        printf("8. Sortiraj listu po prezimenima\n");
        printf("9. Upisi listu u datoteku\n");
        printf("10. Čitaj listu iz datoteke\n");
        printf("0. Izlaz\n");
        printf("Izbor: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                printf("Unesite ime: ");
                scanf("%s", ime);
                printf("Unesite prezime: ");
                scanf("%s", prezime);
                printf("Unesite godinu rođenja: ");
                scanf("%d", &godina_rodenja);
                head = dodajNaPocetak(head, ime, prezime, godina_rodenja);
                break;
            case 2:
                ispisiListu(head);
                break;
            case 3:
                printf("Unesite ime: ");
scanf("%s", ime);
                printf("Unesite prezime: ");
                scanf("%s", prezime);
                printf("Unesite godinu rođenja: ");
                scanf("%d", &godina_rodenja);
                head = dodajNaKraj(head, ime, prezime, godina_rodenja);
                break;
            case 4:
                printf("Unesite prezime za pretragu: ");
                scanf("%s", prezime);
                Osoba *pronadena = pronadiElement(head, prezime);
                if (pronadena)
                    printf("Pronađena osoba - Ime: %s, Prezime: %s, Godina rođenja: %d\n", pronadena->ime, pronadena->prezime, pronadena->godina_rodenja);
                else
                    printf("Osoba s prezimenom %s nije pronađena.\n", prezime);
                break;
            case 5:
                printf("Unesite prezime za brisanje: ");
                scanf("%s", prezime);
                head = obrisiElement(head, prezime);
                break;
            case 6:
                printf("Unesite ime: ");
                scanf("%s", ime);
                printf("Unesite prezime: ");
                scanf("%s", prezime);
                printf("Unesite godinu rođenja: ");
                scanf("%d", &godina_rodenja);
                printf("Unesite prezime osobe iza koje želite dodati: ");
                scanf("%s", targetPrezime);
                head = dodajIzaElementa(head, ime, prezime, godina_rodenja, targetPrezime);
                break;
            case 7:
                printf("Unesite ime: ");
                scanf("%s", ime);
                printf("Unesite prezime: ");
                scanf("%s", prezime);
                printf("Unesite godinu rođenja: ");
                scanf("%d", &godina_rodenja);
                printf("Unesite prezime osobe ispred koje želite dodati: ");
                scanf("%s", targetPrezime);
                head = dodajIspredElementa(head, ime, prezime, godina_rodenja, targetPrezime);
                break;
            case 8:
                head = sortirajListu(head);
                printf("Lista je sortirana po prezimenima.\n");
                break;
            case 9:
                printf("Unesite ime datoteke za upis liste: ");
                char datotekaUpis[50];
                scanf("%s", datotekaUpis);
                upisiUDatoteku(head, datotekaUpis);
                printf("Lista je upisana u datoteku %s.\n", datotekaUpis);
                break;
            case 10:
                printf("Unesite ime datoteke za čitanje liste: ");
                char datotekaCitanje[50];
                scanf("%s", datotekaCitanje);
                head = citajIzDatoteke(datotekaCitanje);
                printf("Lista je učitana iz datoteke %s.\n", datotekaCitanje);
                break;
            case 0:
                printf("Izlaz iz programa.\n");
                break;
            default:
                printf("Pogrešan unos, pokušajte ponovno.\n");
        }
    } while (izbor != 0);

    
    while (head) {
        Osoba *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
}


    return 0;
}
