/****************************************************************************************
* Generation d'images .bmp 24 bits
*
* Test des fonctions systemes
*
* Programmation procedurale 2019 - E.Bosly - Version Demo
****************************************************************************************/
#include "Prepa_Img_2D.h"

/****************************************************************************************
* Test des differentes fonctions de manipulation des images
****************************************************************************************/
int main(void) {

    printf("\nTest image bitmap : matrice 2D\n\n");

 //   Tst_System_01();                // copy + copy_bw + monochromes + damier
 //   Tst_System_02();                // monochromes handling size
 //   Tst_System_03();                // monochromes + damiers handling size
//    Tst_System_04();                // copy ?
    Tst_System_SAM();

    return 0;
}

/****************************************************************************************
* Test Sam
****************************************************************************************/
void Tst_System_SAM(void) {

    image *img = NULL;

    printf("\n--- Test Sam -----------------------------------------------------\n\n");

    img = Lire_Image("tiger", "");
    Afficher_Header(img);

    Damier_size(img);
    Ecrire_Image(img, "_5");

    Free_Image(img);
}

/****************************************************************************************
* Test 1 : Lire, modifier et ecrire une image moyenne
*
* But : Valider les lectures / ecritures sur une image venant d'un logiciel externe
*       Tester un filtre elementaire
****************************************************************************************/
void Tst_System_01(void) {

    image *img = NULL;

    printf("\n--- Test 1 -----------------------------------------------------\n\n");

    img = Lire_Image("USS_Ent", "");        // load image into struct image
    Afficher_Header(img);                                    // display image header
    Ecrire_Image(img, "_1");                         // write image into disc (copy in this case)

    Filtrer_Noir_Blanc(img);
    Ecrire_Image(img, "_2");

    Initialiser_Image(img, Get_Col(JAUNE));
    Ecrire_Image(img, "_3");

    Initialiser_Image(img, Get_Col(ROUGE_4));
    Ecrire_Image(img, "_4");

    Damier(img);
    Ecrire_Image(img, "_5");

    Free_Image(img);
}

/****************************************************************************************
* Test 2 : Creation d'images vierges
*
* But : tester les routines de bases de creation/ecriture d'images
****************************************************************************************/
void Tst_System_02(void) {

    image *img = NULL;

    printf("\n--- Test 2 -----------------------------------------------------\n\n");

    img = Creer_Image("Test", 800, 500, CYAN);
    Afficher_Header(img);
    Ecrire_Image(img, "_010");
    Free_Image(img);

    img = Creer_Image("Test", 5000, 5000, BLEU);
    Afficher_Header(img);
    Ecrire_Image(img, "_011");
    Free_Image(img);

    img = Creer_Image("Test", 8000, 8000, VERT);
    Afficher_Header(img);
    Ecrire_Image(img, "_012");
    Free_Image(img);
}

/****************************************************************************************
* Test 3 : Creation de 4 images presque identiques, sauf en largeur
*
* But : valider la creation / ecriture d'une image de test de largeur quelconque
*       dimensions de l'image de test :
*           hauteur   : 300 - constante
*           largeur   : 900 -  901 -  902 -  903
*           largeur%4 :  0      1      2      3
****************************************************************************************/
void Tst_System_03(void) {

    image *img = NULL;

    printf("\n--- Test 3 -----------------------------------------------------\n\n");

    img = Creer_Image("Test", 900, 300, ROUGE_6);
    Ecrire_Image(img, "_010");
    Damier(img);
    Ecrire_Image(img, "_011");
    Free_Image(img);

    img = Creer_Image("Test", 901, 300, VERT_6);
    Ecrire_Image(img, "_012");
    Damier(img);
    Ecrire_Image(img, "_013");
    Free_Image(img);

    img = Creer_Image("Test", 902, 300, JAUNE_6);
    Ecrire_Image(img, "_014");
    Damier(img);
    Ecrire_Image(img, "_015");
    Free_Image(img);

    img = Creer_Image("Test", 903, 300, BLEU_6);
    Ecrire_Image(img, "_016");
    Damier(img);
    Ecrire_Image(img, "_017");
    Free_Image(img);
}

/****************************************************************************************
* Test 4 : Copie de 5 images presque identiques, sauf en largeur
*
* But : valider la lecture / ecriture d'une image de test de largeur quelconque
*       dimensions de l'image de test :
*           hauteur   : 828 - constante
*           largeur   : 1196 - 1197 - 1198 - 1199 - 1200
*           largeur%4 :  0      1      2      3      0
****************************************************************************************/
void Tst_System_04(void) {

    image *ori=NULL;
    int i;
    char txt[20];

    printf("\n--- Test 4 -----------------------------------------------------\n\n");

    for (i=0; i<5; i++) {
        sprintf(txt, "_Ele_%d", i);
        ori = Lire_Image("Test",txt);
        sprintf(txt, "_Ele_%d_C", i);
        Ecrire_Image(ori, txt);
    }

    Free_Image(ori);
    return;
}

/****************************************************************************************
* Filtrer l'image en noir et blanc
*   img     : structure image
****************************************************************************************/
void Filtrer_Noir_Blanc(image * img) {

    int x, y, cm;
    pixel *pix;

    printf("Filtrage noir et blanc en cours......");

    for(x=0; x<img->header.largeur; x++) {

        for (y=0; y<img->header.hauteur; y++) {

            pix = Get_Pixel(img, x, y);

            cm = ( pix->B + pix->G + pix->R ) / 3;

            pix->B = (uchar)cm;		// blue
            pix->G = (uchar)cm;		// green
            pix->R = (uchar)cm;		// red

            Set_Pixel(img, x, y, pix);
        }
    }

    printf(" termine.\n\n");
}

/****************************************************************************************
* Genere une image en damier noir et blanc
*   img     : structure image
****************************************************************************************/
void Damier(image * img) {

    int x, y, col;

    for(y=0;y<img->header.hauteur;y++) {

        col = y % 2 ? NOIR : BLANC;

        for (x=0;x<img->header.largeur;x++) {

            Set_Pixel(img, x, y, Get_Col(col));
            col = 1 - col;
        }
    }
}


/****************************************************************************************
 * Genere une image en damier noir et blanc
 *      img     : structure image
 *      SIZE    : taille des pavés en pixels (hauteur et largeur)
****************************************************************************************/
void Damier_size(image * img, int size) {

    int x, y, col;

    for(y=0; y<img->header.hauteur; y++) {

        col = y % 10 ? NOIR : BLANC;

        for (x=0; x<img->header.largeur; x++) {

            Set_Pixel(img, x, y, Get_Col(col));
            if (x % 10 == 0) {
                col = 1 - col;      // switch
            }
        }
    }
}
