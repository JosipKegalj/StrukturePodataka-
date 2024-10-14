#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string ime;
    string prezime;
    int bodovi;
};

int brojRedakaUDatoteci(const string& nazivDatoteke) {
    ifstream datoteka(nazivDatoteke);
    string linija;
    int brojRedaka = 0;

    if (datoteka.is_open()) {
        while (getline(datoteka, linija)) {
            brojRedaka++;
        }
        datoteka.close();
    }

    return brojRedaka;
}

void ucitajStudente(Student* studenti, int brojStudenata, const string& nazivDatoteke, int& maxBodovi) {
    ifstream datoteka(nazivDatoteke);
    maxBodovi = 0;

    if (datoteka.is_open()) {
        for (int i = 0; i < brojStudenata; i++) {
            datoteka >> studenti[i].ime >> studenti[i].prezime >> studenti[i].bodovi;
            if (studenti[i].bodovi > maxBodovi) {
                maxBodovi = studenti[i].bodovi;
            }
        }
        datoteka.close();
    }
}

void ispisiStudente(const Student* studenti, int brojStudenata, int maxBodovi) {
    for (int i = 0; i < brojStudenata; i++) {
        double relativniBodovi = (double)studenti[i].bodovi / maxBodovi * 100;
        cout << studenti[i].ime << " " << studenti[i].prezime
             << " - Apsolutni bodovi: " << studenti[i].bodovi
             << ", Relativni bodovi: " << relativniBodovi << "%" << endl;
    }
}

int main() {
    string nazivDatoteke = "studenti.txt";
    int brojStudenata = brojRedakaUDatoteci(nazivDatoteke);

    if (brojStudenata == 0) {
        cout << "Datoteka je prazna ili ne postoji." << endl;
        return 1;
    }

    Student* studenti = new Student[brojStudenata];
    int maxBodovi = 0;

    ucitajStudente(studenti, brojStudenata, nazivDatoteke, maxBodovi);
    ispisiStudente(studenti, brojStudenata, maxBodovi);

    delete[] studenti;

    return 0;
}
