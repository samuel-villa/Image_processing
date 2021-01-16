/****************************************************************************************
* .bmp 24 bits Image Generation
*
* Test
*
* Programmation procedurale 2021 - Samuel CIULLA - Version 0
****************************************************************************************/
#ifndef IMAGE_PROCESSING_PREPA_IMG_2D_H
#define IMAGE_PROCESSING_PREPA_IMG_2D_H

#include <math.h>
#include "Img_Bmp_2D.h"

enum Card_Points {
    N, S, W, E
};

void Filtrer_Noir_Blanc(image * img);
void Damier(image * img);
void simple_paving(image * img, int factor);
void resize_img(image * img, int factor);
void mosaic(image * img, char * rs_img, int factor);
void polarize(image * in, image * out, double angle, uint radius, int start);

void Tst_System_01(void);
void Tst_System_02(void);
void Tst_System_03(void);
void Tst_System_04(void);
void test_func(void);


#endif
