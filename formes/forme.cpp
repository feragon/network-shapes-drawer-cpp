#include <exceptions/GroupeException.h>
#include <memory.h>
#include <sstream>
#include "forme.h"
#include "groupe.h"

Forme::Forme(const std::string& couleur) :
    _couleur(couleur),
    _groupe(nullptr) {

}

Forme::Forme(const Forme& forme) :
    _couleur(forme._couleur),
    _groupe(nullptr) {

    setGroupe(forme._groupe);

}

Forme::~Forme() {
    setGroupe(nullptr);
}

std::string Forme::couleurAffichee() const {
    const Groupe* first = groupe();

    if(first == nullptr) {
        return couleur();
    }
    else {
        while(first->groupe() != nullptr) {
            first = first->groupe();
        }

        return first->couleur();
    }
}

void Forme::setCouleur(const std::string couleur) {
    _couleur = couleur;
}

void Forme::setGroupe(Groupe* groupe) {
    if(_groupe != nullptr) {
        _groupe->removeForme(this);
    }

    _groupe = groupe;

    if(_groupe != nullptr) {
        _groupe->addForme(this);
    }
}

std::ostream& operator<<(std::ostream& o, const Forme& base) {
    o << "Forme(couleur=" << base._couleur << "; " << base.toString() << ")";

    return o;
}

Forme* Forme::modifierNouveau(const ModificateurForme& modificateurForme) const {
    return modificateurForme.modifier(this);
}

Forme::operator std::string() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

Forme& Forme::operator=(const Forme& other) {
    _couleur = other.couleur();
    _groupe = nullptr;
    setGroupe(other._groupe);
}
