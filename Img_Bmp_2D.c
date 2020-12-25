/****************************************************************************************
* Generation d'images .bmp 24 bits
*
* Implementation des fonctions systemes via tableau a 2 dimensions :
*   lecture/ecriture sur disque,
*   allocation dynamique, affichage
*
* Programmation procedurale 2019 - E.Bosly - Version Demo
****************************************************************************************/
#include "Img_Bmp_2D.h"

/****************************************************************************************
* Definition du tableau palette de couleurs
****************************************************************************************/
pixel color[60] = {
        {   0,   0,   0 },  // 000 Noir
        { 255, 255, 255 },  // 001 Blanc
        { 255,   0,   0 },  // 002 Bleu
        {   0, 255,   0 },  // 003 Vert
        {   0,   0, 255 },  // 004 Rouge
        {   0, 255, 255 },  // 005 Jaune
        { 255,   0, 255 },  // 006 Magenta
        { 255, 255,   0 },  // 007 Cyan
        {  32,  32,  32 },  // 008 Gris_x
        {  64,  64,  64 },  // 009
        {  96,  96,  96 },  // 010
        { 128, 128, 128 },  // 011
        { 160, 160, 160 },  // 012
        { 192, 192, 192 },  // 013
        { 224, 224, 224 },  // 014
        { 255,  32,  32 },  // 015 Bleu_x
        { 255,  64,  64 },  // 016
        { 255,  96,  96 },  // 017
        { 255, 128, 128 },  // 018
        { 255, 160, 160 },  // 019
        { 255, 192, 192 },  // 020
        { 255, 224, 224 },  // 021
        {  32, 255,  32 },  // 022 Vert_x
        {  64, 255,  64 },  // 023
        {  96, 255,  96 },  // 024
        { 128, 255, 128 },  // 025
        { 160, 255, 160 },  // 026
        { 192, 255, 192 },  // 027
        { 224, 255, 224 },  // 028
        {  32,  32, 255 },  // 029 Rouge_x
        {  64,  64, 255 },  // 030
        {  96,  96, 255 },  // 031
        { 128, 128, 255 },  // 032
        { 160, 160, 255 },  // 033
        { 192, 192, 255 },  // 034
        { 224, 224, 255 },  // 035
        {  32, 255, 255 },  // 036 Jaune_x
        {  64, 255, 255 },  // 037
        {  96, 255, 255 },  // 038
        { 128, 255, 255 },  // 039
        { 160, 255, 255 },  // 040
        { 192, 255, 255 },  // 041
        { 224, 255, 255 },  // 042
        { 255,  32, 255 },  // 043 Magenta_x
        { 255,  64, 255 },  // 044
        { 255,  96, 255 },  // 045
        { 255, 128, 255 },  // 046
        { 255, 160, 255 },  // 047
        { 255, 192, 255 },  // 048
        { 255, 224, 255 },  // 049
        { 255, 255,  32 },  // 050 Cyan_x
        { 255, 255,  64 },  // 051
        { 255, 255,  96 },  // 052
        { 255, 255, 128 },  // 053
        { 255, 255, 160 },  // 054
        { 255, 255, 192 },  // 055
        { 255, 255, 224 },  // 056
        {   0,   0,   0 },  // 057
        {   0,   0,   0 },  // 058
        {   0,   0,   0 }   // 059
};

/****************************************************************************************
* Donner une couleur de base sur 8 niveaux possibles
*   col     : couleur definie dans enum couleur
****************************************************************************************/
pixel * Get_Col(int col) {

    return &color[col];
}

/****************************************************************************************
* Afficher les donnees du fichier BMP 24bits original
*   img     : structure image
****************************************************************************************/
void Afficher_Header(image *img) {

    printf("\n--------------------------------------------------------\n");
    printf("%-12s: %s  \n", "Image", img->nom_base);
    printf("%-12s: %d  \n","Largeur", img->header.largeur);
    printf("%-12s: %d  \n","Hauteur", img->header.hauteur);
    //printf("%-12s: %ld Kbytes \n","Taille", img->header.taille/1024);
    printf("%-12s: %u Kbytes \n","Taille", img->header.taille/1024);
    printf("\n");
}

/****************************************************************************************
* Composition du nom de fichier complet
* Exemple : si le nom de base est Test et l'extension _V1 : .\Test\Test_V1.bmp
*   nom     : nom compose
*   nom_bas : nom de base de l'image
*   nom_tag : suffixe du nom d'image
****************************************************************************************/
void Nom_Image(char * nom, char * nom_base, char * nom_tag) {

    //strncpy(nom, PHOTO_DIR,     FIC_NM);        // Repertoire de base, harcode via define (not needed on mac)
    strncat(nom, nom_base,      FIC_NM);        // Repertoire image = Nom de base
    //strncat(nom, "\\",          FIC_NM);        // windows
    strncat(nom, "/",          FIC_NM);         // mac
    strncat(nom, nom_base,      FIC_NM);        // Nom de base de l'image
    strncat(nom, nom_tag,       FIC_NM);        // Extension accrochee au nom de base
    strncat(nom, ".bmp",        FIC_NM);        // Type de fichier
    printf("Fichier : %s\n\n", nom);
}

/****************************************************************************************
* Lire un fichier BMP 24bits original en memoire
*   nom_bas : nom de base de l'image
*   nom_tag : suffixe du nom d'image
*   retourne le pointeur vers l'image allouee
****************************************************************************************/
image * Lire_Image(char * nom_bas, char * nom_tag) {

    int bufsize, pt_line, i;
    char nom_fic[FIC_NM] = {0};    // Nom complet du fichier image

    FILE *fp = NULL;                    // Pointeur vers le fichier image .bmp
    image *img = NULL;                  // Pointeur vers la structure image

    /* Allocation de la structure image */
    img = (image *)malloc(sizeof(image));
    if (img==NULL) {
        printf("Lire_Image 1 : Impossible d'initialiser avec malloc\n" );
        exit(EXIT_FAILURE);
    }

    /* Ouverture fichier binaire en lecture */
    Nom_Image(nom_fic, nom_bas, nom_tag);                       // compose and assign a file name
    if ((fp = fopen(nom_fic, "rb")) == NULL) {
        printf("\nError opening source file %s\n", nom_fic);
        img=NULL;
        return img;
    }

    /* Premiere lecture de l'entete (54 octets) pour obtenir les caracteristiques image */
    memset(&img->header, 0, sizeof(img->header));
    fseek(fp, 2, SEEK_SET);                 // jumping after the 'BM'
    fread(&img->header, 1, sizeof(img->header), fp);

    /* Initialisation des autres caracteristiques de l'image */
    img->nb_pix = img->header.hauteur * img->header.largeur;
    strncpy(img->nom_base, nom_bas, FIC_NM);

    /* Allocation de l'image */
    img->pic = Malloc_Pic(img->header.hauteur, img->header.largeur);

    /* Lecture de l'image dans le tableau de pixel */
    bufsize = (3 * img->header.largeur + img->header.largeur%4) * img->header.hauteur;

    for (i=0; i<img->header.hauteur; i++) {
        pt_line = img->header.offset + i * (3 * img->header.largeur + img->header.largeur%4);
        fseek(fp, pt_line, SEEK_SET);
        fread(img->pic[i], 1, 3*img->header.largeur, fp);
    }

    /* Resize header to 54 char */
    img->header.offset = HEADER_SIZE;
    img->header.lg_head = HEADER_SIZE - 14;
    img->header.taille = img->header.offset + bufsize;

    /* Desallocation du buffer et fermeture du fichier : l'image est dans la structure img */
    fclose(fp);

    return img;
}

/****************************************************************************************
* Get pixel value
*   img     : structure image
*   x       : coordonnee x
*   y       : coordonnee y
*   retourne un pointeur vers le pixel x,y
****************************************************************************************/
pixel * Get_Pixel(image * img, int x, int y) {

    return &(img->pic[y][x]);
}

/****************************************************************************************
* Set pixel value
*   img     : structure image
*   x       : coordonnee x
*   y       : coordonnee y
*   col     : couleur a mettre dans le pixel x,y
****************************************************************************************/
void Set_Pixel(image * img, int x, int y, pixel * col) {

    img->pic[y][x] = *col;
}

/****************************************************************************************
* Creer une image vierge uniformement coloree en memoire
*   nom_bas : nom de base de l'image
*   hauteur : hauteur de l'image en pixels
*   largeur : largeur de l'image en pixels
*   col     : couleur definie dans enum couleur
*   retourne le pointeur vers l'image allouee
****************************************************************************************/
image * Creer_Image(char * nom_bas, uint largeur, uint hauteur, int col) {

    image *img = NULL;

    img = (image *)malloc(sizeof(image));
    if (img==NULL) {
        printf ("Creer_Image 1 : Impossible d'initialiser avec malloc\n" );
        exit(EXIT_FAILURE);
    }

    memset(&img->header, 0, sizeof(img->header));

    strncpy(img->nom_base, nom_bas, FIC_NM);

    img->header.largeur = largeur;
    img->header.hauteur = hauteur;
    img->nb_pix = largeur * hauteur;

    img->header.bitpix = BIT_PIXEL;
    img->header.offset = HEADER_SIZE;
    img->header.lg_head = HEADER_SIZE - 14;
    img->header.taille = img->header.offset + ((3 * img->header.largeur + img->header.largeur%4) * img->header.hauteur);

    img->header.applic_id[0] = 'S';
    img->header.applic_id[1] = 'C';
    img->header.applic_id[2] = 'I';
    img->header.applic_id[3] = 'U';

    img->header.planes = 1;

    img->pic = Malloc_Pic(img->header.hauteur, img->header.largeur);
    Initialiser_Image(img, Get_Col(col) );

    return img;
}


/****************************************************************************************
* Ecrire l'image en memoire sur disque (en passant par un buffer)
*   img     : structure image
*   nom_tag : suffixe du nom d'image
****************************************************************************************/
void Ecrire_Image(image * img, char * nom_tag) {

    int i, pt_line;
    char nom_fic[FIC_NM] = {0};
    char typ[4]="BM", fil[4]= {0};

    FILE *fp = NULL;

    Nom_Image(nom_fic, img->nom_base, nom_tag);
    if ((fp = fopen(nom_fic, "wb")) ==NULL) {
        printf("\nError opening source file\n");
        exit(EXIT_FAILURE);
    }

    fwrite(typ, 1, 2, fp);
    fwrite(&img->header, 1, sizeof(img->header), fp);

    for (i=0; i<img->header.hauteur; i++) {
        pt_line = img->header.offset + i * (3 * img->header.largeur + img->header.largeur%4);
        fseek(fp, pt_line, SEEK_SET);
        fwrite(img->pic[i], 1, 3*img->header.largeur, fp);
        fwrite(fil, 1, img->header.largeur%4, fp);
    }

    fclose(fp);
}

/****************************************************************************************
* Allocation dynamique d'une image sous forme d'un tableau de pixels a 2 dimensions
*   hauteur : hauteur de l'image en pixels
*   largeur : largeur de l'image en pixels
*   retourne un pointeur vers la matrice image allouee
****************************************************************************************/
pixel ** Malloc_Pic(uint hauteur, uint largeur) {

    int i;
    pixel **t;

    t = (pixel**)malloc(sizeof(*t) * hauteur);
    if (t==NULL) {
        printf ("Malloc_pic 1 : Impossible d'initialiser avec malloc\n" );
        exit(EXIT_FAILURE);
    }

    for (i=0; i<hauteur; i++) {
        t[i] = (pixel*)malloc(sizeof(**t) * largeur);

        if (t[i]==NULL) {
            printf ("Malloc_pic 2 : Impossible d'initialiser avec malloc\n" );
            exit(EXIT_FAILURE);
        }
    }
    return t;
}

/****************************************************************************************
* Desallocation d'une image
*   img     : structure image a desallouer
****************************************************************************************/
void Free_Image(image * img) {

    free(img->pic);
    free(img);
}

/****************************************************************************************
* Desallocation d'une matrice image
*   t       : matrice image a desallouer
*   hauteur : hauteur de l'image en pixels
*   largeur : largeur de l'image en pixels
****************************************************************************************/
void Free_Pic(pixel ** t, uint hauteur, uint largeur) {

    int i;

    for (i=0; i<hauteur; i++) free(t[i]);
    free(t);
}

/****************************************************************************************
* Initialiser l'image a une valeur constante
*   img : structure image
*   col : vecteur des composantes de la couleur
****************************************************************************************/
void Initialiser_Image(image * img, pixel * col) {

    int x, y;

    for (x=0; x<img->header.largeur; x++) {
        for (y=0; y<img->header.hauteur; y++) {
            Set_Pixel(img, x, y, col);
        }
    }
}
