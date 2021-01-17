/****************************************************************************************
* .bmp 24 bits Image Generation
*
* Testing system functions
*
* Programmation procedurale 2021 - Samuel CIULLA - Version 2
****************************************************************************************/
#include "Prepa_Img_2D.h"

/****************************************************************************************
* Test des differentes fonctions de manipulation des images
****************************************************************************************/
int main(void) {

    printf("\nSamuel CIULLA");
    printf("\nTest image bitmap: matrice 2D\n\n");

    test_func();

    return 0;
}

/****************************************************************************************
* Test Sam
****************************************************************************************/
void test_func(void) {

    printf("\n--- Test Sam -----------------------------------------------------\n\n");

    image *img = NULL, *out = NULL;

    /// polar conversion test
    img = Lire_Image("landscape", "");
    out = polarize(img, "landscape", 360, 0, N);
    Ecrire_Image(out, "_pol1");

//    img = Lire_Image("landscape", "");
//    out = polarize(img, "landscape", 360, 950, N);
//    Ecrire_Image(out, "_pol2");
//
//    img = Lire_Image("landscape", "");
//    out = polarize(img, "landscape", 270, 100, S);
//    Ecrire_Image(out, "_pol3");
//
//    img = Lire_Image("hendrix", "");
//    out = polarize(img, "hendrix", 90, 150, E);
//    Ecrire_Image(out, "_pol4");
//
//    img = Lire_Image("beethoven", "");
//    out = polarize(img, "beethoven", -45, 200, S);
//    Ecrire_Image(out, "_pol5");
//
//    img = Lire_Image("Test", "");
//    out = polarize(img, "Test", 120, 250, E);
//    Ecrire_Image(out, "_pol5");                     // OK

    //Afficher_Header(img);
    //Afficher_Header(out);

    /// mosaic test
//    img = Lire_Image("hendrix", "");
//    mosaic(img, "hendrix", 5);                            // big hendrix - little hendrix
//    Ecrire_Image(img, "_mos1");
//    img = Lire_Image("hendrix", "");
//    mosaic(img, "beethoven", 10);                         // big hendrix - little beethoven
//    Ecrire_Image(img, "_mos2");
//    img = Lire_Image("hendrix", "");
//    mosaic(img, "hendrix", 20);                           // big hendrix - little hendrix
//    Ecrire_Image(img, "_mos3");
//    img = Lire_Image("beethoven", "");
//    mosaic(img, "beethoven", 10);                         // big beethoven - little beethoven
//    Ecrire_Image(img, "_mos4");
//    img = Lire_Image("beethoven", "");
//    mosaic(img, "hendrix", 10);                           // big beethoven - little hendrix
//    Ecrire_Image(img, "_mos5");
//    img = Lire_Image("beethoven", "");
//    mosaic(img, "beethoven", 50);                         // big beethoven - little beethoven
//    Ecrire_Image(img, "_mos6");                           // OK

    /// resize test
//    resize_img(img, 100);
//    Ecrire_Image(img, "_rsz1");
//    img = Lire_Image("hendrix", "");
//    resize_img(img, 50);
//    Ecrire_Image(img, "_rsz2");
//    img = Lire_Image("hendrix", "");
//    resize_img(img, 20);
//    Ecrire_Image(img, "_rsz3");
//    img = Lire_Image("hendrix", "");
//    resize_img(img, 10);
//    Ecrire_Image(img, "_rsz4");
//    img = Lire_Image("hendrix", "");
//    resize_img(img, 5);
//    Ecrire_Image(img, "_rsz5");                           // OK

    /// constant paving test
//    simple_paving(img, 5);
//    Ecrire_Image(img, "_pav1");
//    img = Lire_Image("hendrix", "");
//    simple_paving(img, 10);
//    Ecrire_Image(img, "_pav2");
//    img = Lire_Image("hendrix", "");
//    simple_paving(img, 20);
//    Ecrire_Image(img, "_pav3");
//    img = Lire_Image("hendrix", "");
//    simple_paving(img, 50);
//    Ecrire_Image(img, "_pav4");                           // OK

    Free_Image(img);
    Free_Image(out);

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
 * Image paving
 * This function has been implemented in integer type, meaning the 'factor' parameter
 * MUST match with the image size, ex:
 * if size = 500, factor = 10: 500/10=50        => OK
 * if size = 500, factor = 15: 500/15=33,333... => NOT OK
 *      img   : image struct
 *      factor: size of pave pieces
****************************************************************************************/
void simple_paving(image * img, int factor) {

    int x, y, xi, yi, sumR=0, sumG=0, sumB=0, avgR, avgG, avgB, stepl = factor, stepc = factor;
    int div = factor*factor;
    pixel *pix;

    for (y=0; y<img->header.hauteur; y+=factor) {
        for(x=0; x<img->header.largeur; x+=factor) {

            for (yi=y; yi < stepl; yi++) {                  // get average color on input image bloc by bloc
                for (xi=x; xi < stepc; xi++) {
                    pix = Get_Pixel(img, xi, yi);
                    sumB += pix->B;
                    sumR += pix->R;
                    sumG += pix->G;
                }
            }
            avgB = sumB/div;
            avgR = sumR/div;
            avgG = sumG/div;

            for (yi=y; yi < stepl; yi++) {                  // set average color of each bloc on output image
                for (xi=x; xi < stepc; xi++) {
                    pix = Get_Pixel(img, xi, yi);
                    pix->B = avgB;
                    pix->G = avgG;
                    pix->R = avgR;
                    Set_Pixel(img, xi, yi, pix);
                }
            }
            sumG = 0; sumR = 0; sumB = 0;
            stepc += factor;
        }
        stepl += factor;
        stepc = factor;
    }
}



/****************************************************************************************
 * Image resizing (smaller), needed to create the mosaic pieces.
 * This function has been implemented in integer type, meaning the 'factor' parameter
 * MUST match with the image size, ex:
 * if size = 500, factor = 10: 500/10=50        => OK
 * if size = 500, factor = 15: 500/15=33,333... => NOT OK
 *      img   : image struct
 *      factor: resize scale factor
****************************************************************************************/
void resize_img(image * img, int factor) {

    int x, y, xi, yi, sumR=0, sumG=0, sumB=0, avgR, avgG, avgB, stepl=factor, stepc=factor, bufsize;
    int div = factor*factor;
    pixel *pix;

    for (y=0; y<img->header.hauteur; y+=factor) {
        for(x=0; x<img->header.largeur; x+=factor) {

            for (yi=y; yi < stepl; yi++) {                      // get average color of a bloc of size factor*factor
                for (xi=x; xi < stepc; xi++) {
                    pix = Get_Pixel(img, xi, yi);
                    sumB += pix->B;
                    sumR += pix->R;
                    sumG += pix->G;
                }
            }
            avgB = sumB/div;
            avgR = sumR/div;
            avgG = sumG/div;

            for (yi=y/factor; yi < stepl/factor; yi++) {        // creating smaller image of average color
                for (xi=x/factor; xi < stepc/factor; xi++) {    // of corresponding bloc
                    pix = Get_Pixel(img, xi, yi);
                    pix->B = avgB;
                    pix->G = avgG;
                    pix->R = avgR;
                    Set_Pixel(img, xi, yi, pix);
                }
            }
            sumG = 0; sumR = 0; sumB = 0;
            stepc += factor;
        }
        stepl += factor;
        stepc = factor;
    }
    img->header.hauteur = img->header.hauteur/factor;           // update smaller image header
    img->header.largeur = img->header.largeur/factor;
    bufsize = (3 * img->header.largeur + img->header.largeur%4) * img->header.hauteur;
    img->header.taille = img->header.offset + bufsize;
}




/****************************************************************************************
 * Mosaic of resized images composing a bigger image
 * This function has been implemented in integer type, meaning the 'factor' parameter
 * MUST match with the image size, ex:
 * if size = 500, factor = 10: 500/10=50        => OK
 * if size = 500, factor = 15: 500/15=33,333... => NOT OK
 *      img   : image struct
 *      rs_img: image of each mosaic piece (MUST match with main image)
 *      factor: size of mosaic piece
****************************************************************************************/
void mosaic(image * img, char * rs_img, int factor) {

    int x, y, xi, yi, sumR=0, sumG=0, sumB=0, avgR, avgG, avgB, stepl=factor, stepc=factor, yr, xr, div=factor*factor;
    int fact_rsz = img->header.largeur/factor;
    pixel *pix;
    image *rsz = NULL;

    rsz = Lire_Image(rs_img, "");
    resize_img(rsz, fact_rsz);

    for (y=0; y<img->header.hauteur; y+=factor) {
        for(x=0; x<img->header.largeur; x+=factor) {

            for (yi=y; yi < stepl; yi++) {                      // get average color of a bloc of size factor*factor
                for (xi=x; xi < stepc; xi++) {
                    pix = Get_Pixel(img, xi, yi);
                    sumB += pix->B;
                    sumR += pix->R;
                    sumG += pix->G;
                }
            }
            avgB = sumB/div;
            avgR = sumR/div;
            avgG = sumG/div;

            for (yi=y, yr=yi%rsz->header.hauteur; yi < stepl; yi++, yr++) {
                for (xi=x, xr=xi%rsz->header.largeur; xi < stepc; xi++, xr++) {
                    pix = Get_Pixel(rsz, xr, yr);               // insert resized image in loop
                    Set_Pixel(img, xi, yi, pix);
                    pix = Get_Pixel(img, xi, yi);               // get color of every pixel of the resized image
                    pix->B = (pix->B + avgB) / 2;               // calculate average color between resized image pixels
                    pix->G = (pix->G + avgG) / 2;               // and the average of the blocs we've calculated earlier
                    pix->R = (pix->R + avgR) / 2;
                    Set_Pixel(img, xi, yi, pix);
                }
            }
            sumG = 0; sumR = 0; sumB = 0;
            stepc += factor;
        }
        stepl += factor;
        stepc = factor;
    }
    Free_Image(rsz);
}




/****************************************************************************************
 * Convert cartesian coordinates of an image to polar coordinates
 *      in     : image source, Input
 *      in_name: image source file name
 *      angle  : image angle, ex: 360=donut, 180=half donut, 90=1/4 donut, 0=empty image, -180=reversed half donut
 *      radius : radius of the central circle
 *      cut_dir: where the 'cut' will be directed, can be N, S, W or E.
****************************************************************************************/
image * polarize(image * in, char * in_name, double angle, uint radius, int cut_dir) {

    if (radius < 0) radius = 0;                                                 // set min and max radius level:
    if (radius > in->header.hauteur*2.5) radius = in->header.hauteur*2.5;       // avoid errors and bad image resolution

    image *out = set_background(in, in_name, radius);
    double x, y, d, t, xdist, ydist, xc=out->header.largeur/2, yc=out->header.hauteur/2, alpha=angle/360;
    pixel *pix = NULL;

    for (y=0; y<out->header.largeur; y++) {
        for (x=0; x<out->header.hauteur; x++) {
            ydist = sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc)) - radius;           // distance
            d = ydist + radius;
            if (d < in->header.hauteur + radius && d > radius) {

                if      (cut_dir == S) t = atan2(xc - x, yc - y) / (alpha * M_PI);      // angle and image orientation
                else if (cut_dir == N) t = atan2(x - xc, y - yc) / (alpha * M_PI);
                else if (cut_dir == E) t = atan2(y - yc, x - xc) / (alpha * M_PI);
                else if (cut_dir == W) t = atan2(yc - y, xc - x) / (alpha * M_PI);

                xdist = (t + 1) * ((in->header.largeur - 1) / 2);
                if (xdist >= 0 && ydist >= 0 && xdist < in->header.largeur && ydist < in->header.hauteur) {
                    pix = Get_Pixel(in, xdist, ydist);
                    Set_Pixel(out, x, y, pix);
                }
            }
        }
    }
    return out;
}




/****************************************************************************************
 * Prepare background for the image converted to polar coordinates,
 * allocate the correct size and set the average color of the source image as background.
 *      img     : image struct
 *      img_name: image source file name
 *      radius  : radius of the central circle
****************************************************************************************/
image * set_background(image * img, char * img_name, int radius) {

    int x, y, sumR=0, sumG=0, sumB=0;
    image * out = NULL;
    pixel *pix = NULL;

    for (y=0; y<img->header.hauteur; y++) {                     // get color of each pixel
        for(x=0; x<img->header.largeur; x++) {
            pix = Get_Pixel(img, x, y);
            sumB += pix->B;
            sumR += pix->R;
            sumG += pix->G;
        }
    }
    pix->R = sumR/(img->header.hauteur*img->header.largeur);    // get average color
    pix->G = sumG/(img->header.hauteur*img->header.largeur);
    pix->B = sumB/(img->header.hauteur*img->header.largeur);
                                                                // create background and allocate memory
    out = Creer_Image(img_name, ((img->header.hauteur+radius) *2), ((img->header.hauteur+radius) *2), BLANC);

    for (y=0; y<out->header.hauteur; y++) {                     // set average color (WHITE will be overwritten)
        for(x=0; x<out->header.largeur; x++) {
            Set_Pixel(out, x, y, pix);
        }
    }
    return out;
}