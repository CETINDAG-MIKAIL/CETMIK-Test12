#include "mainwindowphotoshop.h"
#include "ui_mainwindowphotoshop.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QScreen>
#include <QRect>
#include <QPixmap>
#include <QColorDialog>


#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "PhotoShop.h"
#include "Iterateur.h"
#include "Traitements.h"
#include "XYException.h"
#include "MyQT.h"



MainWindowPhotoShop::MainWindowPhotoShop(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindowPhotoShop)
{
    ui->setupUi(this);
    setTitre("Mini-PhotoShop  en C++");

    // Centrage de la fenetre
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
    setFixedSize(1021,845);

    // Configuration de la table des images
    ui->tableWidgetImages->setColumnCount(4);
    ui->tableWidgetImages->setRowCount(0);
    QStringList labelsTableOptions;
    labelsTableOptions << "Id" << "Type" << "Dimension" << "Nom";
    ui->tableWidgetImages->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetImages->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetImages->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetImages->horizontalHeader()->setVisible(true);
    ui->tableWidgetImages->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetImages->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetImages->verticalHeader()->setVisible(false);
    ui->tableWidgetImages->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Intialisation des scrollArea
    
    // setImageNG("selection");
    // setImageNG("operande1");
    // setImageNG("operande2");
    // setImageNG("resultat");
    

    // ComboBox des traitements disponibles
    ajouteTraitementDisponible("Eclaircir (+ val)");
    ajouteTraitementDisponible("Eclaircir (++)");
    ajouteTraitementDisponible("Assombrir (- val)");
    ajouteTraitementDisponible("Assombrir (--)");
    ajouteTraitementDisponible("Différence");
    ajouteTraitementDisponible("Comparaison (==)");
    ajouteTraitementDisponible("Comparaison (<)");
    ajouteTraitementDisponible("Comparaison (>)");
    ajouteTraitementDisponible("Seuillage");
    ajouteTraitementDisponible("Filtre moyenneur");
    ajouteTraitementDisponible("Filtre médian");
    ajouteTraitementDisponible("Erosion");
    ajouteTraitementDisponible("Dilatation");
    ajouteTraitementDisponible("Négatif");

    // Etape 14 (TO DO)
    // Restauration bibliothèque via fichier de sauvegarde

    // TESTS DEMOS A SUPPRIMER
    ajouteTupleTableImages(3,"NG","256x256","lena.bmp");
    setResultatBoolean(1);
}

MainWindowPhotoShop::~MainWindowPhotoShop()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Méthodes de la fenêtre (ne pas modifier) ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setTitre(string titre)
{
  this->setWindowTitle(titre.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setNomImage(string nom)
{
  ui->lineEditNom->setText(QString::fromStdString(nom));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getNomImage() const
{
  return ui->lineEditNom->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setParametresImageNG(int max,int min,int luminance,float contraste)
{
  if (max == -1)
  {
    ui->lineEditMax->setText("");
    ui->lineEditMin->setText("");
    ui->lineEditLuminance->setText("");
    ui->lineEditContraste->setText("");
    return;
  }
  char tmp[20];
  sprintf(tmp,"%d",max);
  ui->lineEditMax->setText(tmp);
  sprintf(tmp,"%d",min);
  ui->lineEditMin->setText(tmp);
  sprintf(tmp,"%d",luminance);
  ui->lineEditLuminance->setText(tmp);
  sprintf(tmp,"%f",contraste);
  ui->lineEditContraste->setText(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageNG(string destination,const ImageNG* imageng)
{
    QPixmap * pixmap = NULL;
    if (imageng != NULL)
    {
      // Creation du QPixmap
      int largeur = imageng->getDimension().getLargeur();
      int hauteur = imageng->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          int valeur = imageng->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur,valeur,valeur));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageRGB(string destination,const ImageRGB* imagergb)
{
    QPixmap * pixmap = NULL;
    if (imagergb != NULL)
    {
      // Creation du QPixmap
      int largeur = imagergb->getDimension().getLargeur();
      int hauteur = imagergb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          Couleur valeur = imagergb->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur.getRouge(),valeur.getVert(),valeur.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageB(string destination,const ImageB* imageb)
{
    QPixmap * pixmap = NULL;
    if (imageb != NULL)
    {
      // Creation du QPixmap
      int largeur = imageb->getDimension().getLargeur();
      int hauteur = imageb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          bool valeur = imageb->getPixel(x,y);
          if (valeur) im1.setPixel(x,y,qRgb(ImageB::couleurTrue.getRouge(),ImageB::couleurTrue.getVert(),ImageB::couleurTrue.getBleu()));
          else im1.setPixel(x,y,qRgb(ImageB::couleurFalse.getRouge(),ImageB::couleurFalse.getVert(),ImageB::couleurFalse.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setResultatBoolean(int val)
{
  if (val == 1) // vrai
  {
    ui->checkBoxResultat->setChecked(true);
    ui->checkBoxResultat->setText("VRAI");
    ui->checkBoxResultat->setStyleSheet("background-color: lightgreen;border: 1px solid black;");
    return;
  }
  if (val == 0) // faux
  {
    ui->checkBoxResultat->setChecked(false);
    ui->checkBoxResultat->setText("FAUX");
    ui->checkBoxResultat->setStyleSheet("background-color: red;border: 1px solid black;");
    return;
  }
  // ni vrai, ni faux
  ui->checkBoxResultat->setChecked(false);
  ui->checkBoxResultat->setText("Résultat");
  ui->checkBoxResultat->setStyleSheet("background-color: lightyellow;border: 1px solid black;");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Images (ne pas modifier) ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTupleTableImages(int id,string type,string dimension,string nom)
{
    char Id[20];
    sprintf(Id,"%d",id);

    char Type[20];
    strcpy(Type,type.c_str());

    char Dimension[20];
    strcpy(Dimension,dimension.c_str());

    char Nom[200];
    strcpy(Nom,nom.c_str());

    // Ajout possible
    int nbLignes = ui->tableWidgetImages->rowCount();
    nbLignes++;
    ui->tableWidgetImages->setRowCount(nbLignes);
    ui->tableWidgetImages->setRowHeight(nbLignes-1,20);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Id);
    ui->tableWidgetImages->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Type);
    ui->tableWidgetImages->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Dimension);
    ui->tableWidgetImages->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(Nom);
    ui->tableWidgetImages->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTableImages()
{
    ui->tableWidgetImages->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::getIndiceImageSelectionnee()
{
    QModelIndexList liste = ui->tableWidgetImages->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des traitements disponibles (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTraitementDisponible(string operation)
{
    ui->comboBoxTraitements->addItem(operation.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTraitementsDisponibles()
{
    ui->comboBoxTraitements->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getTraitementSelectionne() const
{
    return ui->comboBoxTraitements->currentText().toStdString();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue (ne pas modifier) ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float MainWindowPhotoShop::dialogueDemandeFloat(const char* titre,const char* question)
{
    return QInputDialog::getDouble(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierOuvrir(const char* question)
{
  QString fileName = QFileDialog::getOpenFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierEnregistrer(const char* question)
{
  QString fileName = QFileDialog::getSaveFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueDemandeCouleur(const char* message,int* pRouge,int* pVert,int* pBleu)
{
  QColor color = QColorDialog::getColor(Qt::red,this,message);
  *pRouge = color.red();
  *pVert = color.green();
  *pBleu = color.blue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Clic sur la croix de la fenêtre ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::closeEvent(QCloseEvent *event)
{
  if (event == NULL) {} // pour éviter le warning à la compilation
  // Etape 14 (TO DO)

  QApplication::exit();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionQuitter_triggered()
{
  // Etape 14 (TO DO)

  QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageNB_triggered()
{
  // Etape 11 (TO DO)

  string fichier = dialogueDemandeFichierOuvrir("Entrez le nom de l'image");
  const char* fichier2 = fichier.c_str();
  Image* nouvelleImage = new ImageNG;

  dynamic_cast<ImageNG*>(nouvelleImage)->importFromFile(fichier2);

  nouvelleImage->setNom(fichier2);

  // Utiliser la référence à l'instance de PhotoShop
  PhotoShop& photoShop = PhotoShop::getInstance();

  // Ajouter l'image à la PhotoShop
    photoShop.ajouteImage(nouvelleImage);


  videTableImages();

    Iterateur<Image*> it(photoShop.getImages());
    it.reset();
    while(!it.end()) {
        Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur
        
        // convertir dimension en string 
        int width = image->getDimension().getLargeur();
        int height = image->getDimension().getHauteur();

        std::string widthString = std::to_string(width);
        std::string heightString = std::to_string(height);

        // Concaténez les chaînes pour obtenir la dimension complète
        std::string dimensionString = widthString + "x" + heightString;


        // // convertir char * en string         
        // cout << "image->getNom()" << image->getNom() << endl;
        std::string nomString(image->getNom());
        // cout << nomString << endl;

        ajouteTupleTableImages(image->getId(),image->getType(),dimensionString,nomString);
      it.operator++();
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageRGB_triggered()
{
  // Etape 11 (TO DO)

   string fichier = dialogueDemandeFichierOuvrir("Entrez le nom de l'image");
  const char* fichier2 = fichier.c_str();
  Image* nouvelleImage = new ImageRGB;

  dynamic_cast<ImageRGB*>(nouvelleImage)->importFromFile(fichier2);

  nouvelleImage->setNom(fichier2);

  // Utiliser la référence à l'instance de PhotoShop
  PhotoShop& photoShop = PhotoShop::getInstance();

  // Ajouter l'image à la PhotoShop
    photoShop.ajouteImage(nouvelleImage);


  videTableImages();

    Iterateur<Image*> it(photoShop.getImages());
    it.reset();
    while(!it.end()) {
        Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur
        
        // convertir dimension en string 
        int width = image->getDimension().getLargeur();
        int height = image->getDimension().getHauteur();

        std::string widthString = std::to_string(width);
        std::string heightString = std::to_string(height);

        // Concaténez les chaînes pour obtenir la dimension complète
        std::string dimensionString = widthString + "x" + heightString;


        // // convertir char * en string         
        // cout << "image->getNom()" << image->getNom() << endl;
        std::string nomString(image->getNom());
        // cout << nomString << endl;

        ajouteTupleTableImages(image->getId(),image->getType(),dimensionString,nomString);
      it.operator++();
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageNB_triggered()
{
    int indice = getIndiceImageSelectionnee();
    cout << "indice" << indice << endl;
    if (indice == -1)
    {
        dialogueErreur("Enregistrement echoue", "Aucune image trouve");
    }
    else
    {
        PhotoShop &photoShop = PhotoShop::getInstance();

        Image *image = photoShop.getImageParIndice(indice);

        if (image != nullptr)
        {
            const char *nomString = image->getType().c_str();
            if (strcmp("NG", nomString) == 0)
            {
                string fichier = dialogueDemandeFichierEnregistrer("Entrez le nom de l'image");

                string TypeDeFichierAEnregistrer = dialogueDemandeTexte("Type a enregistrer", "Quel type de fichier voulez-vous enregistrer (JPG/PNG/BMP)");

                ImageNG *nouvelleImage = dynamic_cast<ImageNG *>(image); // sert a verifier si le type est de type ImageNG si oui alors nouvelleImage est different de NULL

                if (nouvelleImage != nullptr)
                {
                    nouvelleImage->exportToFile(fichier.c_str(), TypeDeFichierAEnregistrer.c_str());
                    cout << "Enregistrement réussi" << endl;
                }
                else
                {
                    dialogueErreur("Enregistrement echoue", "Conversion vers ImageNG a échoué");
                }
            }
            else
            {
                dialogueErreur("Enregistrement echoue", "Mauvais type d'image trouve");
            }
        }
        else
        {
            dialogueErreur("Enregistrement echoue", "Image non trouvée");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void MainWindowPhotoShop::on_actionEnregistrer_ImageRGB_triggered()
  {
     int indice = getIndiceImageSelectionnee();
    cout << "indice" << indice << endl;
    if (indice == -1)
    {
        dialogueErreur("Enregistrement echoue", "Aucune image trouve");
    }
    else
    {
        PhotoShop &photoShop = PhotoShop::getInstance();

        Image *image = photoShop.getImageParIndice(indice);

        if (image != nullptr)
        {
            const char *nomString = image->getType().c_str();
            if (strcmp("NG", nomString) == 0)
            {
                string fichier = dialogueDemandeFichierEnregistrer("Entrez le nom de l'image");

                string TypeDeFichierAEnregistrer = dialogueDemandeTexte("Type a enregistrer", "Quel type de fichier voulez-vous enregistrer (JPG/PNG/BMP)");

                ImageRGB *nouvelleImage = dynamic_cast<ImageRGB *>(image); // sert a verifier si le type est de type ImageRGB si oui alors nouvelleImage est different de NULL

                if (nouvelleImage != nullptr)
                {
                    nouvelleImage->exportToFile(fichier.c_str(), TypeDeFichierAEnregistrer.c_str());
                    cout << "Enregistrement réussi" << endl;
                }
                else
                {
                    dialogueErreur("Enregistrement echoue", "Conversion vers ImageNG a échoué");
                }
            }
            else
            {
                dialogueErreur("Enregistrement echoue", "Mauvais type d'image trouve");
            }
        }
        else
        {
            dialogueErreur("Enregistrement echoue", "Image non trouvée");
        }
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageB_triggered()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
    cout << "indice" << indice << endl;
    if (indice == -1)
    {
        dialogueErreur("Enregistrement echoue", "Aucune image trouve");
    }
    else
    {
        PhotoShop &photoShop = PhotoShop::getInstance();

        Image *image = photoShop.getImageParIndice(indice);

        if (image != nullptr)
        {
            const char *nomString = image->getType().c_str();
            if (strcmp("B", nomString) == 0)
            {
                string fichier = dialogueDemandeFichierEnregistrer("Entrez le nom de l'image");

                string TypeDeFichierAEnregistrer = dialogueDemandeTexte("Type a enregistrer", "Quel type de fichier voulez-vous enregistrer (JPG/PNG/BMP)");

                ImageB *nouvelleImage = dynamic_cast<ImageB *>(image); // sert a verifier si le type est de type ImageRGB si oui alors nouvelleImage est different de NULL

                if (nouvelleImage != nullptr)
                {
                    nouvelleImage->exportToFile(fichier.c_str(), TypeDeFichierAEnregistrer.c_str());
                    cout << "Enregistrement réussi" << endl;
                }
                else
                {
                    dialogueErreur("Enregistrement echoue", "Conversion vers ImageNG a échoué");
                }
            }
            else
            {
                dialogueErreur("Enregistrement echoue", "Mauvais type d'image trouve");
            }
        }
        else
        {
            dialogueErreur("Enregistrement echoue", "Image non trouvée");
        }
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_selectionn_e_triggered()
{
  // Etape 11 (TO DO)

  int indice = getIndiceImageSelectionnee();
  cout << "indice" << indice << endl;
  if(indice==-1)
    dialogueErreur("Image non selectionner","Aucun image a ete selectionner");
  else
  {
    ++indice; 
    PhotoShop &photoShop = PhotoShop::getInstance();
    photoShop.supprimeImageParIndice(indice);
    videTableImages();

    Iterateur<Image*> it(photoShop.getImages());
    it.reset();
    while (!it.end()) {
        Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur

        // convertir dimension en string 
        int width = image->getDimension().getLargeur();
        int height = image->getDimension().getHauteur();

        std::string widthString = std::to_string(width);
        std::string heightString = std::to_string(height);

        // Concaténez les chaînes pour obtenir la dimension complète
        std::string dimensionString = widthString + "x" + heightString;

        // convertir char * en string         
        std::string nomString(image->getNom());

        ajouteTupleTableImages(image->getId(), image->getType(), dimensionString, nomString);
        it.operator++();
    }
  }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_par_id_triggered()
{
    int id = dialogueDemandeInt("Suppression par id", "Donnez l'id de l'image a supprimer");

    // Etape 11 (TO DO)
    PhotoShop& photoShop = PhotoShop::getInstance();
    photoShop.supprimeImageParId(id);

    videTableImages();

    Iterateur<Image*> it(photoShop.getImages());
    it.reset();
    while (!it.end()) {
        Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur

        // convertir dimension en string 
        int width = image->getDimension().getLargeur();
        int height = image->getDimension().getHauteur();

        std::string widthString = std::to_string(width);
        std::string heightString = std::to_string(height);

        // Concaténez les chaînes pour obtenir la dimension complète
        std::string dimensionString = widthString + "x" + heightString;

        // convertir char * en string         
        std::string nomString(image->getNom());

        ajouteTupleTableImages(image->getId(), image->getType(), dimensionString, nomString);
        it.operator++();
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_TRUE_pour_ImageB_triggered()
{
    // Etape 12 (TO DO)
    PhotoShop& photoShop = PhotoShop::getInstance();
    int indice = getIndiceImageSelectionnee();
    Image* image = photoShop.getImageParIndice(indice);

    int pRouge, pVert, pBleu;  // Allouer des variables pour stocker les valeurs

    dialogueDemandeCouleur("Veillez choisir une couleur", &pRouge, &pVert, &pBleu);

    if (ImageB* nouvelleImage = dynamic_cast<ImageB*>(image))
    {
        nouvelleImage->couleurTrue = Couleur(pRouge, pVert, pBleu);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_FALSE_pour_imageB_triggered()
{
  
    PhotoShop& photoShop = PhotoShop::getInstance();
    int indice = getIndiceImageSelectionnee();
    Image* image = photoShop.getImageParIndice(indice);

    int pRouge, pVert, pBleu;  // Allouer des variables pour stocker les valeurs

    dialogueDemandeCouleur("Veillez choisir une couleur", &pRouge, &pVert, &pBleu);

    if (ImageB* nouvelleImage = dynamic_cast<ImageB*>(image))
    {
        nouvelleImage->couleurFalse = Couleur(pRouge, pVert, pBleu);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImporterCSV_triggered()
{
  // Etape 13 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionReset_triggered()
{
  // Etape 14 (TO DO)

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions selection sur la table des images ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_tableWidgetImages_itemSelectionChanged()
{
  // Etape 11 (TO DO)

  int indice = getIndiceImageSelectionnee();
  cout << "indice" << indice << endl;
  if(indice==-1)
  {
    // dialogueErreur("Image non selectionner","Aucun image a ete selectionner");
    setImageB("selection", NULL);
    setImageRGB("selection", NULL); // on vide la fenetre a droite lorsqu'on s'est deselectionner
    setImageNG("selection", NULL);
  }

  else
  {
    PhotoShop& photoShop = PhotoShop::getInstance();

    Image *image = photoShop.getImageParIndice(indice);
    setNomImage(image->getNom());
    setParametresImageNG(); // permet de vider les champs
    ImageNG *nouvelleImage = dynamic_cast<ImageNG *>(image);
    if (nouvelleImage != nullptr)
    {
      setParametresImageNG(nouvelleImage->getMaximum(), nouvelleImage->getMinimum(), nouvelleImage->getLuminance(), nouvelleImage->getContraste());
      setImageNG("selection",nouvelleImage);
    }
    else
    {
      ImageRGB *nouvelleImage = dynamic_cast<ImageRGB *>(image); 
      if (nouvelleImage != nullptr)
      {
        setImageRGB("selection",nouvelleImage);
      }
      else
      {
        ImageB *nouvelleImage = dynamic_cast<ImageB *>(image); 
        if (nouvelleImage != nullptr)
          setImageB("selection",nouvelleImage);
      }
    }
  }

 

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonModifierNom_clicked()
{
  // Etape 11 (TO DO)

  string NouveauNom = getNomImage();

  int indice = getIndiceImageSelectionnee();
  cout << "indice" << indice << endl;
  if (indice == -1)
  {
      dialogueErreur("Enregistrement echoue", "Aucune image trouve");
  }
  else
  {
      PhotoShop &photoShop = PhotoShop::getInstance();

      Image *image = photoShop.getImageParIndice(indice);

      image->setNom(NouveauNom.c_str()); // il a ete mise a jour dans la programmation mais pas visuellement 
  }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande1_clicked()
{
  int indice = getIndiceImageSelectionnee();
  cout << "indice" << indice << endl;
  if (indice == -1)
  {
      dialogueErreur("Enregistrement echoue", "Aucune image trouve");
  }
  else
  {
      PhotoShop &photoShop = PhotoShop::getInstance();

      Image *image = photoShop.getImageParIndice(indice);

      photoShop.operande1= image;

      ImageNG *nouvelleImage = dynamic_cast<ImageNG *>(image);
      if (nouvelleImage != nullptr)
      {
        setParametresImageNG(nouvelleImage->getMaximum(), nouvelleImage->getMinimum(), nouvelleImage->getLuminance(), nouvelleImage->getContraste());
        setImageNG("operande1",nouvelleImage);
      }
      else
      {
        ImageRGB *nouvelleImage = dynamic_cast<ImageRGB *>(image); 
        if (nouvelleImage != nullptr)
        {
          setImageRGB("operande1",nouvelleImage);
        }
        else
        {
          ImageB *nouvelleImage = dynamic_cast<ImageB *>(image); 
          if (nouvelleImage != nullptr)
            setImageB("operande1",nouvelleImage);
        }
      }



  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimeOperande1_clicked()
{
  PhotoShop &photoShop = PhotoShop::getInstance();
  setImageNG("operande1", NULL);
  photoShop.operande1= nullptr;    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande2_clicked()
{
    
  int indice = getIndiceImageSelectionnee();
  cout << "indice" << indice << endl;
  if (indice == -1)
  {
      dialogueErreur("Enregistrement echoue", "Aucune image trouve");
  }
  else
  {
      PhotoShop &photoShop = PhotoShop::getInstance();

      Image *image = photoShop.getImageParIndice(indice);

      photoShop.operande2= image;

      ImageNG *nouvelleImage = dynamic_cast<ImageNG *>(image);
      if (nouvelleImage != nullptr)
      {
        setParametresImageNG(nouvelleImage->getMaximum(), nouvelleImage->getMinimum(), nouvelleImage->getLuminance(), nouvelleImage->getContraste());
        setImageNG("operande2",nouvelleImage);
      }
      else
      {
        ImageRGB *nouvelleImage = dynamic_cast<ImageRGB *>(image); 
        if (nouvelleImage != nullptr)
        {
          setImageRGB("operande2",nouvelleImage);
        }
        else
        {
          ImageB *nouvelleImage = dynamic_cast<ImageB *>(image); 
          if (nouvelleImage != nullptr)
            setImageB("operande2",nouvelleImage);
        }
      }
    }



}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerOperande2_clicked()
{
  PhotoShop &photoShop = PhotoShop::getInstance();
  setImageNG("operande2", NULL);
  photoShop.operande2= nullptr;    

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonResultat_clicked()
{
   PhotoShop &photoShop = PhotoShop::getInstance();
  int val =0;
  if (ImageB *imageB = dynamic_cast<ImageB*>(photoShop.resultat))
  {
    val = 1;
  }
  else if (ImageRGB *imageRGB = dynamic_cast<ImageRGB*>(photoShop.resultat))
  {
              val = 2;
  }
  else if (ImageNG *imageNG = dynamic_cast<ImageNG*>(photoShop.resultat))
  {
    val = 3;
  }
  // Ajouter l'image à la PhotoShop
    photoShop.ajouteImage(photoShop.resultat);


  videTableImages();

  Iterateur<Image*> it(photoShop.getImages());

  it.reset();
  while(!it.end()) {
      Image* image = it.operator&(); // Obtention de l'image à partir de l'itérateur      
      // convertir dimension en string 
      int width = image->getDimension().getLargeur();
      int height = image->getDimension().getHauteur();
      std::string widthString = std::to_string(width);
      std::string heightString = std::to_string(height);
      std::string dimensionString = widthString + "x" + heightString;
      std::string nomString(image->getNom());
      ajouteTupleTableImages(image->getId(),image->getType(),dimensionString,nomString);
    it.operator++();
  }
  if(val==1)
    setImageB("resultat", nullptr);
  else if(val == 2)
        setImageRGB("resultat", nullptr);
  else if(val == 3)
        setImageNG("resultat", nullptr);

    photoShop.resultat = nullptr;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerResultat_clicked()
{
    // Etape 12 (TO DO)
  PhotoShop &photoShop = PhotoShop::getInstance();
  
  delete photoShop.resultat;  

  setImageNG("resultat", nullptr); // dans tous les cas on ne met pas une image dedans donc n'importe quel methode peut etre appeler RGB/NG/B

  photoShop.resultat= nullptr;   

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonTraitement_clicked()
{
    // Etape 12 (TO DO)
    PhotoShop &photoShop = PhotoShop::getInstance();

    string traitementSelectionne = getTraitementSelectionne();
    if (photoShop.operande1 != nullptr)
    {
        // initialise
        setResultatBoolean(-1);
        setImageNG("resultat", NULL);
        delete photoShop.resultat;  
        photoShop.resultat = nullptr;
        int val = -1;
        ImageNG *resultatNG = new ImageNG();
        // Traitements nécessitant deux images
        ImageNG *image1 = dynamic_cast<ImageNG *>(photoShop.operande1);
        ImageNG *imageCopie = new ImageNG(*image1); // on fait une copie afin de ne pas modifier l'original

        if (traitementSelectionne == "Différence" || traitementSelectionne == "Comparaison (==)" || traitementSelectionne == "Comparaison (<)" || traitementSelectionne == "Comparaison (>)")
        {
            if (photoShop.operande2 != nullptr)
            {
                // Vérifier si operande1 et operande2 sont du type ImageNG
                ImageNG *image2 = dynamic_cast<ImageNG *>(photoShop.operande2);


                if (image1 != nullptr && image2 != nullptr)
                {
                    if (traitementSelectionne == "Différence")
                    {
                        *resultatNG = *image1 - *image2;
                        PhotoShop::resultat = resultatNG; // imageNG -> image , pas besoin de casting car ImageNG est la sous-classe de Image donc la casting est implicite
                        setImageNG("resultat", resultatNG);
                    }
                    else if (traitementSelectionne == "Comparaison (==)")
                    {
                        if (*image1 == *image2)
                            val = 1;
                        else
                            val = 0;
                        setResultatBoolean(val);
                    }
                    else if (traitementSelectionne == "Comparaison (<)")
                    {

                        if (*image1 < *image2)
                            val = 1;
                        else
                            val = 0;
                        cout << "val" << val << endl;
                        setResultatBoolean(val);
                    }
                    else if (traitementSelectionne == "Comparaison (>)")
                    {

                        if (*image1 > *image2)
                            val = 1;
                        else
                            val = 0;
                        cout << "val" << val << endl;

                        setResultatBoolean(val);
                    }
                    else
                    {
                        // Afficher un message d'erreur pour les traitements non gérés
                        dialogueErreur("Traitement échoué", "Traitement non pris en charge");
                    }
                }
                else
                {
                    // Afficher un message d'erreur, car une ou les deux opérandes ne sont pas du bon type
                    dialogueErreur("Traitement échoué", "Les opérandes doivent être de type ImageNG");
                }
            }
            else
            {
                // Afficher un message d'erreur, car operande2 est NULL
                dialogueErreur("Traitement échoué", "Aucune opérande 2 sélectionnée");
            }
        }
        else
        {
            if (traitementSelectionne == "Filtre moyenneur")
            {
              int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
              *resultatNG = Traitements::FiltreMoyenneur(*imageCopie, valeurAutiliser);
              PhotoShop::resultat = resultatNG;
              setImageNG("resultat", resultatNG);
            }
            else
            {
              if(traitementSelectionne == "Filtre médian")
              {
                int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                *resultatNG = Traitements::FiltreMedian(*imageCopie, valeurAutiliser);
                PhotoShop::resultat = resultatNG;
                setImageNG("resultat", resultatNG);

              }
              else
              {
                if(traitementSelectionne == "Erosion")
                {
                  int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                  *resultatNG = Traitements::Erosion(*imageCopie, valeurAutiliser);
                  PhotoShop::resultat = resultatNG;
                  setImageNG("resultat", resultatNG);
                }
                else
                {
                  if(traitementSelectionne == "Dilatation")
                  {
                    int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                    *resultatNG = Traitements::Dilatation(*imageCopie, valeurAutiliser);
                    PhotoShop::resultat = resultatNG;
                    setImageNG("resultat", resultatNG);
                  }
                  else
                  {
                    if(traitementSelectionne == "Négatif")
                    {
                      *resultatNG = Traitements::Negatif(*imageCopie);
                      PhotoShop::resultat = resultatNG;
                      setImageNG("resultat", resultatNG);
                    }
                    else
                    {
                      if(traitementSelectionne == "Seuillage")
                      {
                        int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                        ImageB *resultatB = new ImageB();
                        *resultatB = Traitements::Seuillage(*imageCopie, valeurAutiliser);
                        PhotoShop::resultat = resultatNG;
                        setImageB("resultat", resultatB);
                      }
                      else
                      {
                        if(traitementSelectionne == "Eclaircir (++)")
                        {
                          *resultatNG = imageCopie->operator++();
                          PhotoShop::resultat = resultatNG;
                          setImageNG("resultat", resultatNG);
                        }
                        else
                        {
                          if(traitementSelectionne == "Assombrir (--)")
                          {
                            *resultatNG = imageCopie->operator--();
                            PhotoShop::resultat = resultatNG;
                            setImageNG("resultat", resultatNG);
                          }
                          else
                          {
                            if(traitementSelectionne == "Eclaircir (+ val)")
                            {
                              int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                              *resultatNG = imageCopie->operator+(valeurAutiliser);
                              PhotoShop::resultat = resultatNG;
                              setImageNG("resultat", resultatNG);
                            }
                            else
                            {
                              if(traitementSelectionne == "Assombrir (- val)")
                              {
                                int valeurAutiliser =  dialogueDemandeInt("Insertion Valeur", "Inserez votre valeur");
                                *resultatNG = imageCopie->operator-(valeurAutiliser);
                                PhotoShop::resultat = resultatNG;
                                setImageNG("resultat", resultatNG);
                              }
                            }
                          }
                        }
                      }
                    }

                  }
                }
              }

            }
        }
    }
    else
    {
        // Afficher un message d'erreur, car operande1 est NULL
        dialogueErreur("Traitement échoué", "Aucune opérande 1 sélectionnée");
    }
}




    
