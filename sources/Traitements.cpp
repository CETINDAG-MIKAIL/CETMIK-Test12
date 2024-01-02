#include <math.h>
#include <iostream>
#include <cstring>

#include "Traitements.h"
using namespace std;

/////////////////////////////////// GET

// On cree une nouvelle image binaire et on la remplie des valeurs true ou false de l'image reçu
ImageB Traitements::Seuillage(const ImageNG& image, int seuil) {
    ImageB imageB;
    imageB.setDimension(image.getDimension()); 

    for (int i = 0; i < image.getDimension().getHauteur(); i++)
    {
        for (int j = 0; j < image.getDimension().getLargeur(); j++)
        {
            if (image.getPixel(i, j) <= seuil) 
            	imageB.setPixel(i, j, true); 
            else 
                imageB.setPixel(i, j, false);    
        }
    }
    // Obtenez le nom de l'image
    std::string nomImage = image.getNom();


    // Concaténez le seuil au nom de l'image
    nomImage += "-seuil" + std::to_string(seuil);


    // Mettez à jour le nom de l'image avec la nouvelle valeur
    imageB.setNom(nomImage.c_str());


    return imageB;
}
ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille) {
    if ((taille % 2) != 0) { // Vérifie si la taille est impaire
        ImageNG imageN;
        imageN.setDimension(imageIn.getDimension()); // Crée une nouvelle image avec les mêmes dimensions

        int hauteur = imageIn.getDimension().getHauteur();
        int largeur = imageIn.getDimension().getLargeur();

        for (int i = 0; i < largeur; i++) {
            for (int j = 0; j < hauteur; j++) {
                int moyenne = 0;
                int compteur = 0;

                for (int k = -taille / 2; k <= taille / 2; k++) {
                    for (int l = -taille / 2; l <= taille / 2; l++) {
                        int voisinI = i + k;
                        int voisinJ = j + l;

                        if (voisinI >= 0 && voisinI < largeur && voisinJ >= 0 && voisinJ < hauteur) {
                            moyenne += imageIn.getPixel(voisinI, voisinJ);
                            compteur++;
                        }
                    }
                }

                int valeurMoyenne = moyenne / compteur;
                imageN.setPixel(i, j, valeurMoyenne);
            }
        }
	         // Obtenez le nom de l'image
	    std::string nomImage = imageIn.getNom();


	    // Concaténez le moyenne au nom de l'image
	    nomImage += "-moyenne" + std::to_string(taille);


	    // Mettez à jour le nom de l'image avec la nouvelle valeur
	    imageN.setNom(nomImage.c_str());
        return imageN; // Retourne l'image avec le filtre appliqué
    } else {
        
        return imageIn; 	// Si la taille est paire, retourne l'image d'entrée sans modification
    }
}

ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille) {

    if ((taille % 2) == 0) {
        std::cout << "La taille du filtre est paire." << std::endl;
        return imageIn;
    }

    ImageNG imageOut;
    imageOut.setDimension(imageIn.getDimension());

    int hauteur = imageIn.getDimension().getHauteur();
    int largeur = imageIn.getDimension().getLargeur();

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            ArrayList<int> values;

            for (int k = -taille / 2; k <= taille / 2; k++) {
                for (int l = -taille / 2; l <= taille / 2; l++) {
                    int voisinI = i + k;
                    int voisinJ = j + l;

                    if (voisinI >= 0 && voisinI < hauteur &&
                        voisinJ >= 0 && voisinJ < largeur) {
                        values.insereElement(imageIn.getPixel(voisinI, voisinJ));
                    }
                }
            }
			
            if (values.estVide()  ==  'N' )
            {
                values.trier(); // Trie les valeurs dans l'ArrayList
                int medianIndex = values.getNombreElements() / 2;
                int medianValue = values.getElement(medianIndex);
                imageOut.setPixel(i, j, medianValue);
            }

        }
    }

    return imageOut;
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille) {

    if ((taille % 2) == 0) {
        std::cout << "La taille du filtre est paire." << std::endl;
        return imageIn;
    }

    ImageNG imageOut;
    imageOut.setDimension(imageIn.getDimension());

    int hauteur = imageIn.getDimension().getHauteur();
    int largeur = imageIn.getDimension().getLargeur();

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            ArrayList<int> values;

            for (int k = -taille / 2; k <= taille / 2; k++) {
                for (int l = -taille / 2; l <= taille / 2; l++) {
                    int voisinI = i + k;
                    int voisinJ = j + l;

                    if (voisinI >= 0 && voisinI < hauteur &&
                        voisinJ >= 0 && voisinJ < largeur) {
                        values.insereElement(imageIn.getPixel(voisinI, voisinJ));
                    }
                }
            }
			
            if (values.estVide()  ==  'N' )
            {
                values.trier(); // Trie les valeurs dans l'ArrayList
                int medianValue = values.getElement(1);
                imageOut.setPixel(i, j, medianValue);
            }

        }
    }

    return imageOut;
}
ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille) {

    if ((taille % 2) == 0) {
        std::cout << "La taille du filtre est paire." << std::endl;
        return imageIn;
    }
    ImageNG imageOut;
    imageOut.setDimension(imageIn.getDimension());
    int hauteur = imageIn.getDimension().getHauteur();
    int largeur = imageIn.getDimension().getLargeur();

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            ArrayList<int> values;

            for (int k = -taille / 2; k <= taille / 2; k++) {
                for (int l = -taille / 2; l <= taille / 2; l++) {
                    int voisinI = i + k;
                    int voisinJ = j + l;

                    if (voisinI >= 0 && voisinI < hauteur &&
                        voisinJ >= 0 && voisinJ < largeur) {
                        values.insereElement(imageIn.getPixel(voisinI, voisinJ));
                    
                    }
                }
            }
			
            if (values.estVide()  ==  'N' )
            {
                values.trier(); // Trie les valeurs dans l'ArrayList
                int val = values.getNombreElements()-1; // on commence l'indice a 1 dans getNombreElem
                int medianValue = values.getElement(val-1); // pour ne pas sortir de la liste
                imageOut.setPixel(i, j, medianValue);
            }

        }
    }

    return imageOut;
}
ImageNG Traitements::Negatif(const ImageNG& imageIn) {

    ImageNG imageOut;
    imageOut.setDimension(imageIn.getDimension());
    int hauteur = imageIn.getDimension().getHauteur();
    int largeur = imageIn.getDimension().getLargeur();

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
        	imageOut.setPixel(i,j,255-imageIn.getPixel(i,j));
        }
    }


   	const char* nomImageIn = imageIn.getNom();
	const char* suffixe = "-negatif";

	char nomImage[100];  // Taille suffisamment grande pour contenir les deux noms concaténés
	strcpy(nomImage, nomImageIn);
	strcat(nomImage, suffixe);
	imageOut.setNom(nomImage);

    return imageOut;
}