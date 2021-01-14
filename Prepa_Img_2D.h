/****************************************************************************************
* .bmp 24 bits Image Generation
*
* Test
*
* Programmation procedurale 2021 - Samuel CIULLA - Version 0
****************************************************************************************/
#ifndef IMAGE_PROCESSING_PREPA_IMG_2D_H
#define IMAGE_PROCESSING_PREPA_IMG_2D_H

#include "Img_Bmp_2D.h"

void Filtrer_Noir_Blanc(image * img);
void Damier(image * img);
void simple_paving(image * img, int factor);
void resize_img(image * img, int factor);
void mosaic(image * img, char * rs_img, int factor);

void Tst_System_01(void);
void Tst_System_02(void);
void Tst_System_03(void);
void Tst_System_04(void);
void test_func(void);


#endif
