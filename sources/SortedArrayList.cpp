// #include "SortedArrayList.h"

// template <class type>
// SortedArrayList<type>::SortedArrayList() : ArrayList<type>() {
//     // Initialisations spécifiques à SortedArrayList
// }

// template <class type>
// SortedArrayList<type>::SortedArrayList(const SortedArrayList<type>& c1) : ArrayList<type>(c1) {
//     // Copie des éléments spécifiques à SortedArrayList
//     // Utilisez le constructeur de copie d'ArrayList pour copier les éléments de la liste de l'objet c1
// }

// template <class type>
// SortedArrayList<type>::~SortedArrayList() {
//     // Nettoyage des ressources spécifiques à SortedArrayList
//     // Laissez le destructeur d'ArrayList gérer la suppression des éléments de la liste
// }

// template <class type>
// void SortedArrayList<type>::insereElement(type n) {
//     if (this->pListe == nullptr || n < this->pListe->valeur) {
//         this->pListe = new noeud<type>(n, this->pListe);
//         return;
//     }

//     noeud<type>* courant = this->pListe;
//     while (courant->suiv != nullptr && courant->suiv->valeur < n) {
//         courant = courant->suiv;
//     }

//     courant->suiv = new noeud<type>(n, courant->suiv);
// }
