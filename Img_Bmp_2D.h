/****************************************************************************************
* Generation d'images .bmp 24 bits
*
* Header
*
* Programmation procedurale 2019 - E.Bosly - Version Demo
****************************************************************************************/
#ifndef IMAGE_PROCESSING_IMG_BMP_2D_H
#define IMAGE_PROCESSING_IMG_BMP_2D_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************************
* Constantes symboliques
****************************************************************************************/
#define HEADER_SIZE 54
#define BIT_PIXEL 24
#define FIC_NM 80
#define PHOTO_DIR ".\\"

enum couleur {

    NOIR,
    BLANC,
    BLEU,
    VERT,
    ROUGE,
    JAUNE,
    MAGENTA,
    CYAN,
    GRIS_1,
    GRIS_2,
    GRIS_3,
    GRIS_4,
    GRIS_5,
    GRIS_6,
    GRIS_7,
    BLEU_1,
    BLEU_2,
    BLEU_3,
    BLEU_4,
    BLEU_5,
    BLEU_6,
    BLEU_7,
    VERT_1,
    VERT_2,
    VERT_3,
    VERT_4,
    VERT_5,
    VERT_6,
    VERT_7,
    ROUGE_1,
    ROUGE_2,
    ROUGE_3,
    ROUGE_4,
    ROUGE_5,
    ROUGE_6,
    ROUGE_7,
    JAUNE_1,
    JAUNE_2,
    JAUNE_3,
    JAUNE_4,
    JAUNE_5,
    JAUNE_6,
    JAUNE_7,
    MAGENTA_1,
    MAGENTA_2,
    MAGENTA_3,
    MAGENTA_4,
    MAGENTA_5,
    MAGENTA_6,
    MAGENTA_7,
    CYAN_1,
    CYAN_2,
    CYAN_3,
    CYAN_4,
    CYAN_5,
    CYAN_6,
    CYAN_7
};

/****************************************************************************************
* Definition de la structure de donnees image
****************************************************************************************/
typedef unsigned int uint;
typedef unsigned short int usint;
typedef unsigned char uchar;

typedef struct Pixel {

    uchar B;
    uchar G;
    uchar R;
} pixel;


typedef struct Header_Bitmap {      // 52 char, SANS BM au debut sinon pas multiple de 4

    uint taille;        // taille du fichier
    char applic_id[4];  // identification de l'application creant le fichier
    uint offset;        // offset dans le fichier BMP du 1er pixel = longueur totale header
    uint lg_head;       // longueur totale header - 14
    uint largeur;       // largeur de l'image
    uint hauteur;       // hauteur de l'image
    usint planes;       // nb of planes - 1
    usint bitpix;       // nb bits par pixels - 24
    char fill[22];
} head_bmp;

typedef struct Image {

    head_bmp header;        // contenu du header
    pixel **pic;            // matrice image
    char nom_base[FIC_NM];  // nom de base de l'image sans extension
    uint nb_pix;            // nombre de pixels sur l'image
} image;

/****************************************************************************************
* Prototypes Systeme : Gestion des image sur disque et allocation dynamique memoire
****************************************************************************************/
image * Lire_Image(char * nom_bas, char * nom_tag);
image * Creer_Image(char * nom_bas, uint largeur, uint hauteur, int col);
void Ecrire_Image(image * img, char * nom_tag);
void Nom_Image(char * nom, char * nom_base, char * nom_tag);

pixel ** Malloc_Pic(uint hauteur, uint largeur);
void Free_Pic(pixel ** t, uint hauteur, uint largeur);

void Free_Image(image * img);
void Afficher_Header(image * img);

pixel * Get_Col(int col);

void Initialiser_Image(image * img, pixel * col);

pixel * Get_Pixel(image * img, int x, int y);
void Set_Pixel(image * img, int x, int y, pixel * col);


#endif