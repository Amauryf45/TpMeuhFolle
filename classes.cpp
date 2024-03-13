// classes.cpp

#include "classes.h"

// Définition des membres de la classe Heure
Heure::Heure() : hh(0), mm(0) {}

Heure::Heure(int hh, int mm) {
    this->hh = (hh >= 0 && hh <= 23) ? hh : 0;
    this->mm = (mm >= 0 && mm <= 59) ? mm : 0;
}

void Heure::afficherDetails() {
    std::cout << "hh: " << hh << ", mm: " << mm << std::endl;
}

int Heure::getHh() {
    return hh;
}

int Heure::getMm() {
    return mm;
}

void Heure::mettreAJourMm(int nouveauMm) {
    mm = (nouveauMm >= 0 && nouveauMm <= 59) ? nouveauMm : 0;
}

void Heure::mettreAJourHh(int nouveauHh) {
    hh = (nouveauHh >= 0 && nouveauHh <= 23) ? nouveauHh : 0;
}

// Définition des membres de la classe Creneau
Creneau::Creneau(int id, Heure h_debut, Heure h_fin, std::string type, int priorite, int score) {
    this->id = id;
    debut = h_debut;
    fin = h_fin;
    this->type = type;
    this->priorite = priorite;
    this->score = score;
}

void Creneau::afficherDetails() {
    std::cout << "ID: " << id << ", Type: " << type << ", Priorite: " << priorite << std::endl;
    std::cout << "Debut: ";
    debut.afficherDetails();
    std::cout << "Fin: ";
    fin.afficherDetails();
    std::cout << "Score: " << score;
}

void Creneau::mettreAJourDebut(Heure nouveauDebut) {
    debut = nouveauDebut;
}

void Creneau::mettreAJourFin(Heure nouveauFin) {
    fin = nouveauFin;
}

void Creneau::mettreAJourType(std::string nouveauType) {
    type = nouveauType;
}

void Creneau::mettreAJourPriorite(int nouvellePriorite) {
    priorite = nouvellePriorite;
}

int Creneau::getScore() const {
    return score;
}

bool Creneau::compareCreneaux(const Creneau& a, const Creneau& b) {
    // Comparaison des scores
    return a.getScore() < b.getScore();
}

// Définition des membres de la classe Benevole
Benevole::Benevole() : id(0) {}

Benevole::Benevole(int id, int coequipier1, int coequipier2, std::string choixMission1, std::string choixMission2, std::string choixMission3) {
    this->id = id;
    choixCoequipier[0] = coequipier1;
    choixCoequipier[1] = coequipier2;
    choixMission[0] = choixMission1;
    choixMission[1] = choixMission2;
    choixMission[2] = choixMission3;
}

void Benevole::afficherChoixCoequipier() {
    std::cout << "Choix de coéquipiers pour le bénévole " << id << ":" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << choixCoequipier[i] << " ";
    }
    std::cout << std::endl;
}

void Benevole::afficherChoixMission() {
    std::cout << "Choix de missions pour le bénévole " << id << ":" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << choixMission[i] << " ";
    }
    std::cout << std::endl;
}

// Définition des membres de la classe Binome
Binome::Binome(Benevole benevole1, Benevole benevole2) {
    this->benevole1 = benevole1;
    this->benevole2 = benevole2;
}

Benevole Binome::getBenevole1() {
    return benevole1;
}

Benevole Binome::getBenevole2() {
    return benevole2;
}
