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
void Damier_size(image * img, int size);        // create chess board; cases of given size

void Tst_System_01(void);
void Tst_System_02(void);
void Tst_System_03(void);
void Tst_System_04(void);
void Tst_System_SAM(void);


#endif
