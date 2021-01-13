/****************************************************************************************
* Generation d'images .bmp 24 bits
*
* Header : Test
*
* Programmation procedurale 2019 - E.Bosly - Version Demo
****************************************************************************************/
#ifndef IMAGE_PROCESSING_PREPA_IMG_2D_H
#define IMAGE_PROCESSING_PREPA_IMG_2D_H

#include "Img_Bmp_2D.h"

void Filtrer_Noir_Blanc(image * img);
void Damier(image * img);
void damier_size(image * img, int size);        // create chess board; cases of given size
image * resize_init(image * img, int factor);
void simple_paving(image * in, int factor);

void Tst_System_01(void);
void Tst_System_02(void);
void Tst_System_03(void);
void Tst_System_04(void);
void test_paving(void);


#endif
