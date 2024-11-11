#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int koef;
    int exp;
} Clan;

typedef struct {
    Clan* clanovi;
    int velicina;
} Polinom;

Polinom ucitajPolinom(const char* nazivDatoteke) {
    FILE* datoteka = fopen(nazivDatoteke, "r");
    if (!datoteka) {
        printf("Greska pri otvaranju datoteke.\n");
        exit(1);
    }

    Polinom polinom;
    polinom.velicina = 0;
    polinom.clanovi = NULL;

    int koef, exp;
    while (fscanf(datoteka, "%d %d", &koef, &exp) == 2) {
        polinom.clanovi = realloc(polinom.clanovi, (polinom.velicina + 1) * sizeof(Clan));
        polinom.clanovi[polinom.velicina].koef = koef;
        polinom.clanovi[polinom.velicina].exp = exp;
        polinom.velicina++;
    }
    
    fclose(datoteka);
    return polinom;
}

Polinom zbrojiPolinome(Polinom a, Polinom b) {
    Polinom rezultat;
    rezultat.velicina = 0;
    rezultat.clanovi = NULL;

    for (int i = 0; i < a.velicina; i++) {
        int pronaden = 0;
        for (int j = 0; j < rezultat.velicina; j++) {
            if (rezultat.clanovi[j].exp == a.clanovi[i].exp) {
                rezultat.clanovi[j].koef += a.clanovi[i].koef;
                pronaden = 1;
                break;
            }
        }
        if (!pronaden) {
            rezultat.clanovi = realloc(rezultat.clanovi, (rezultat.velicina + 1) * sizeof(Clan));
            rezultat.clanovi[rezultat.velicina] = a.clanovi[i];
            rezultat.velicina++;
        }
    }

    for (int i = 0; i < b.velicina; i++) {
        int pronaden = 0;
        for (int j = 0; j < rezultat.velicina; j++) {
            if (rezultat.clanovi[j].exp == b.clanovi[i].exp) {
                rezultat.clanovi[j].koef += b.clanovi[i].koef;
                pronaden = 1;
                break;
            }
        }
        if (!pronaden) {
            rezultat.clanovi = realloc(rezultat.clanovi, (rezultat.velicina + 1) * sizeof(Clan));
            rezultat.clanovi[rezultat.velicina] = b.clanovi[i];
            rezultat.velicina++;
        }
    }

    return rezultat;
}


Polinom pomnoziPolinome(Polinom a, Polinom b) {
    Polinom rezultat;
    rezultat.velicina = 0;
    rezultat.clanovi = NULL;

    for (int i = 0; i < a.velicina; i++) {
        for (int j = 0; j < b.velicina; j++) {
            int koef = a.clanovi[i].koef * b.clanovi[j].koef;
            int exp = a.clanovi[i].exp + b.clanovi[j].exp;

  
            int pronaden = 0;
            for (int k = 0; k < rezultat.velicina; k++) {
                if (rezultat.clanovi[k].exp == exp) {
                    rezultat.clanovi[k].koef += koef;
                    pronaden = 1;
                    break;
                }
            }

            if (!pronaden) {
                rezultat.clanovi = realloc(rezultat.clanovi, (rezultat.velicina + 1) * sizeof(Clan));
                rezultat.clanovi[rezultat.velicina].koef = koef;
                rezultat.clanovi[rezultat.velicina].exp = exp;
                rezultat.velicina++;
            }
        }
    }

    return rezultat;
}

void ispisiPolinom(Polinom polinom) {
    for (int i = 0; i < polinom.velicina; i++) {
        printf("%dx^%d ", polinom.clanovi[i].koef, polinom.clanovi[i].exp);
        if (i < polinom.velicina - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Polinom polinom1 = ucitajPolinom("polinom1.txt");
    Polinom polinom2 = ucitajPolinom("polinom2.txt");

    printf("Prvi polinom: ");
    ispisiPolinom(polinom1);

    printf("Drugi polinom: ");
    ispisiPolinom(polinom2);

    Polinom suma = zbrojiPolinome(polinom1, polinom2);
    printf("Suma polinoma: ");
    ispisiPolinom(suma);

    Polinom umnozak = pomnoziPolinome(polinom1, polinom2);
    printf("Umnozak polinoma: ");
    ispisiPolinom(umnozak);

    free(polinom1.clanovi);
    free(polinom2.clanovi);
    free(suma.clanovi);
    free(umnozak.clanovi);

    return 0;
}
