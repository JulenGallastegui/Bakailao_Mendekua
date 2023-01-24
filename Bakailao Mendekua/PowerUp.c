#include "NibelKolisioak.h"
#include "graphics.h"
#include "Mugimendua.h"
#include "ebentoak.h"
#include "imagen.h"
#include "OurTypes.h"
#include "pantailaAldatu.h"
#include "PowerUp.h"

#include <stdio.h>

GURE_GAUZAK gureGauzak;

extern int bizitzaExtra;
extern int indarExtra;
extern int sendaketaExtra;
extern int kontraerasoTotala;
extern int botilaDu;
extern int barraDu;
extern int ezkutuaDu;

extern int gela;
extern int akuarioa;

int powerUp1_1 = 0;


extern POSIZIOA playerPos;

int PowerUpJaso()
{
	switch (akuarioa)
	{
	case 1:
		switch (gela)
		{
			case 3://Pasalekua 4

				if (botilaDu == 0 && playerPos.x + 117 >= 570 && playerPos.x + 117 <= 678 && playerPos.y + 234 >= 200 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					botilaDu = 1;
					return 1;
				}
				break;
			case 6://Pasalekua 5
				if (powerUp1_1 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 278 && playerPos.y + 234 <= 300)
				{
					irudiaKendu(5);
					bizitzaExtra += 20;
					return 1;
				}
				break;
			default:
				break;
		}
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

	return 0;
}

void PowerUpHasieratu()
{
	switch (akuarioa)
	{
		case 1:
			switch (gela)
			{
				case 3:
					if (botilaDu == 0)
					{
						irudiaKargatu(".\\img\\PowerUp\\Ura.png", 5);
						irudiaMugitu(5, 515, -40);
					}
					break;
				case 6:
					if (powerUp1_1 == 0)
					{
						irudiaKargatu(".\\img\\PowerUp\\Bizitza.png", 5);
						irudiaMugitu(5, 285, -255);
					}
					break;
			}
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}
}