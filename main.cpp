#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "classes.h"

// Fonction pour lire les créneaux à partir du fichier
std::vector<Creneau> lireCreneauxDepuisFichier(const std::string &nomFichier)
{
    std::ifstream fichier(nomFichier);
    std::vector<Creneau> creneaux;

    if (fichier)
    {
        std::string ligne;
        int nombreCreneaux = 0;
        int ligneActuelle = 0;

        while (std::getline(fichier, ligne))
        {
            ++ligneActuelle;

            if (ligneActuelle == 1)
            {
                nombreCreneaux = std::stoi(ligne);
            }
            else if (ligneActuelle <= nombreCreneaux + 1)
            {
                std::stringstream ss(ligne);
                std::string token;
                std::vector<std::string> tokens;
                while (std::getline(ss, token, ';'))
                {
                    tokens.push_back(token);
                }

                if (tokens.size() == 5)
                { // Assurez-vous que la ligne contient toutes les informations requises
                    // Convertir les chaînes en types nécessaires
                    int id = std::stoi(tokens[0].substr(3)); // Ignore "Cr_" dans le numéro de créneau
                    Heure debut;
                    Heure fin;
                    size_t posTiret = tokens[1].find('-');
                    if (posTiret != std::string::npos)
                    {
                        // Extraire la partie avant et après le tiret
                        int heureDebut = stoi(tokens[1].substr(0, posTiret));
                        int heureFin = stoi(tokens[1].substr(posTiret + 1));

                        debut.mettreAJourHh(heureDebut);
                        fin.mettreAJourHh(heureFin);
                    }
                    std::string type = tokens[2];
                    int priorite = std::stoi(tokens[3]);
                    int score = std::stoi(tokens[4]);

                    // Créer un objet Creneau et l'ajouter au vecteur
                    Creneau creneau(id, debut, fin, type, priorite, score);
                    creneaux.push_back(creneau);
                }
            }
            else{
                break;
            };
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return creneaux;
}

// Fonction pour lire les bénévoles à partir du fichier
std::vector<Benevole> lireBenevolesDepuisFichier(const std::string& nomFichier, int nombreCreneaux) {
    std::ifstream fichier(nomFichier);
    std::vector<Benevole> benevoles;

    if (fichier) {
        std::string ligne;
        int nombreBenevoles = 0;
        int ligneActuelle = 0;

        // Ignorer les lignes des créneaux
        for (int i = 0; i < nombreCreneaux + 1; ++i) {
            std::getline(fichier, ligne);
        }

        while (std::getline(fichier, ligne)) {
            ++ligneActuelle;

            if (ligneActuelle == nombreCreneaux + 2) {
                nombreBenevoles = std::stoi(ligne);
            } else if (ligneActuelle <= nombreCreneaux + nombreBenevoles + 1) {
                std::stringstream ss(ligne);
                std::string token;
                std::vector<std::string> tokens;
                while (std::getline(ss, token, ';')) {
                    tokens.push_back(token);
                }

                if (tokens.size() == 6) { // Assurez-vous que la ligne contient toutes les informations requises
                    // Convertir les chaînes en types nécessaires
                    int id = std::stoi(tokens[0].substr(4)); // Ignore "ben_" dans le numéro de bénévole
                    int coequipier1 = (tokens[1] == "nochoice") ? -1 : std::stoi(tokens[1].substr(4)); // Ignore "ben_" dans le choix de coéquipier
                    int coequipier2 = (tokens[2] == "nochoice") ? -1 : std::stoi(tokens[2].substr(4)); // Ignore "ben_" dans le choix de coéquipier
                    std::string mission1 = tokens[3];
                    std::string mission2 = tokens[4];
                    std::string mission3 = tokens[5];

                    // Créer un objet Benevole et l'ajouter au vecteur
                    Benevole benevole(id, coequipier1, coequipier2, mission1, mission2, mission3);
                    benevoles.push_back(benevole);
                }
            } else {
                break; // Sortie de la boucle après avoir lu les bénévoles
            }
        }
        fichier.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return benevoles;
}

int main()
{
    // Création d'un vecteur de Creneaux
    std::vector<Creneau> creneaux = lireCreneauxDepuisFichier("data/Pb0.txt");

    // Tri des Creneaux en utilisant la fonction de comparaison personnalisée
    std::sort(creneaux.begin(), creneaux.end(), Creneau::compareCreneaux);

    // Affichage des Creneaux triés
    for (const Creneau &c : creneaux)
    {
        std::cout << "Score: " << c.getScore() << std::endl;
    }

    return 0;
}
