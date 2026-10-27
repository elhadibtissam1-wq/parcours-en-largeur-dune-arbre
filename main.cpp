#include <iostream>
#include <vector>

using namespace std;
struct Noeud {
    int valeur;
    Noeud* gauche;
    Noeud* droite;
};
Noeud* creerNoeud(int x) {
    Noeud* n = new Noeud;
    n->valeur = x;
    n->gauche = nullptr;
    n->droite = nullptr;
    return n;
}
void parcoursLargeur(Noeud* racine) {
    if (racine == nullptr)
        return;

    vector<Noeud*> file;
    file.push_back(racine);
    while (!file.empty()) {
    Noeud* p = file[0];
    file.erase(file.begin());

    cout << p->valeur << " ";


if (p->gauche != nullptr)
    file.push_back(p->gauche);

 if (p->droite != nullptr)
    file.push_back(p->droite);
}
}

int main(){

     Noeud* racine = creerNoeud(7);

    // Les enfants de 7
    racine->gauche = creerNoeud(9);
    racine->droite = creerNoeud(67);

    // Les enfants du 9 situé à gauche de 7
    racine->gauche->gauche = creerNoeud(9);
    racine->gauche->gauche->gauche = creerNoeud(1);
    racine->gauche->gauche->droite = creerNoeud(28);

    // Les enfants de 28
    racine->gauche->gauche->droite->gauche = creerNoeud(29);
    racine->gauche->gauche->droite->droite = creerNoeud(2);

    // Les enfants de 67
    racine->droite->gauche = creerNoeud(8);
    racine->droite->droite = creerNoeud(10);


    // Les enfants de 8
    racine->droite->gauche->gauche = creerNoeud(57);
    racine->droite->gauche->droite = creerNoeud(40);



    // Le fils gauche de 10 reste absent
    racine->droite->droite->droite = creerNoeud(6);
    cout << "Parcours en largeur : ";
    parcoursLargeur(racine);
    cout << endl;
    return 0;
}
