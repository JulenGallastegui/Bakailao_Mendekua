#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "imagen.h"
#include "ebentoak.h"
#include "OurTypes.h"
#include "text.h"
#include "soinua.h"
#include "Combate.h"
#include <stdio.h>
#include <stdlib.h>
#include "GalduPantaila.h"
#include "pantailaAldatu.h"

POSIZIOA pos;

int ebentu;
extern int gela, akuarioa;



int GalduPantaila()
{ 
    irudiaKargatu(".\\img\\Borroka\\BorrokaGaldu.png", 1);
    int irten = 0;
    int berriroEgin = 1;
    while (!irten)
    {
       
      pantailaGarbitu();
      ebentu = ebentuaJasoGertatuBada();
      pos = saguarenPosizioa();

      if (ebentu == SAGU_BOTOIA_EZKERRA)
      {
            if (pos.x > 84 && pos.x < 354 && pos.y > 251 && pos.y < 345)
            {
          
                gela = 0;
                irten = 1;
          
            }
            else if (pos.x > 354 && pos.x < 597 && pos.y > 251 && pos.y < 345)
            {
                if (akuarioa == 1)
                {
                    if (gela == 3 || gela == 6)
                        gela--;
                    else
                        gela -= 2;
                }
                else if (akuarioa == 2)
                {
                    if (gela == 4)
                        gela--;
                    gela--;
                }
                else if (akuarioa == 3)
                {
                    if (gela == 13)
                        gela = 2;
                    else
                        gela--;
                }
      
                irten = 1;
            }
            else if (pos.x > 223 && pos.x < 496 && pos.y > 356 && pos.y < 564)
            {
                irten = -1;
            }
      }
      irudiakMarraztu();
      pantailaBerriztu();
    }
    return irten;
}