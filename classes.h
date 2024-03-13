// classes.h

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class Heure {
private:
    int hh;
    int mm;

public:
    Heure();
    Heure(int hh, int mm);
    void afficherDetails();
    int getHh();
    int getMm();
    void mettreAJourMm(int nouveauMm);
    void mettreAJourHh(int nouveauHh);
};

class Creneau {
private:
    int id;
    Heure debut;
    Heure fin;
    std::string type;
    int priorite;
    int score;

public:
    Creneau(int id, Heure h_debut, Heure h_fin, std::string type, int priorite, int score);
    void afficherDetails();
    void mettreAJourDebut(Heure nouveauDebut);
    void mettreAJourFin(Heure nouveauFin);
    void mettreAJourType(std::string nouveauType);
    void mettreAJourPriorite(int nouvellePriorite);
    int getScore() const;
    static bool compareCreneaux(const Creneau& a, const Creneau& b);
};

class Benevole {
private:
    int id;
    int choixCoequipier[2];
    std::string choixMission[3];

public:
    Benevole();
    Benevole(int id, int coequipier1, int coequipier2, std::string choixMission1, std::string choixMission2, std::string choixMission3);
    void afficherChoixCoequipier();
    void afficherChoixMission();
};

class Binome {
private:
    Benevole benevole1;
    Benevole benevole2;
    Creneau* creneau;
    int score;

public:
    Binome(Benevole benevole1, Benevole benevole2);
    Benevole getBenevole1();
    Benevole getBenevole2();
};

#endif // CLASSES_H
