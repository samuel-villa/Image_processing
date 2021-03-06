/****************************************************************************************
* .bmp 24 bits Image Generation
*
* Test and image modelization functions
*
* Programmation procedurale 2021 - Samuel CIULLA - Version 2
****************************************************************************************/
#ifndef IMAGE_PROCESSING_PREPA_IMG_2D_H
#define IMAGE_PROCESSING_PREPA_IMG_2D_H

#include <math.h>
#include "Img_Bmp_2D.h"


/// definitions
enum Card_Points {
    N, S, W, E
};


/// prototypes
void Filtrer_Noir_Blanc(image * img);
void Damier(image * img);
void simple_paving(image * img, int factor);                               // generate mosaic image of monocolored paves
void resize_img(image * img, int factor);                                  // resize image, used for mosaic()
void mosaic(image * img, char * rs_img, int factor);                       // generate mosaic image
image * polarize(image * in, char * in_name, double angle, uint radius, int cut_dir);   // convert image to polar coordinates
image * set_background(image * img, char * img_name, int radius);          // prepare background, used by polarize()


/// test functions
void Tst_System_01(void);
void Tst_System_02(void);
void Tst_System_03(void);
void Tst_System_04(void);
void test_func(void);

#endif
