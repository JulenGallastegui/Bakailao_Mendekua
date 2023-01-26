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
int powerUp2_1 = 0;
int powerUp2_2 = 0;
int powerUp3_1 = 0;
int powerUp3_2 = 0;


extern POSIZIOA playerPos;

int PowerUpJaso()
{
	switch (akuarioa)
	{
	case 1:
		switch (gela)
		{
			case 3://Pasalekua 4 handia

				if (botilaDu == 0 && playerPos.x + 117 >= 570 && playerPos.x + 117 <= 678 && playerPos.y + 234 >= 306 && playerPos.y + 234 <= 336)
				{
					irudiaKendu(5);
					botilaDu = 1;
					return 1;
				}
				break;
			case 6://Pasalekua 5 txikia
				if (powerUp1_1 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 277 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					powerUp1_1 = 1;
					bizitzaExtra += 20;
					return 1;
				}
				break;
			default:
				break;
		}
		break;
	case 2:
		switch (gela)
		{
			case 3://Pasalekua 2 handia Objeto

				if (ezkutuaDu == 0 && playerPos.x + 117 >= 570 && playerPos.x + 117 <= 678 && playerPos.y + 234 >= 306 && playerPos.y + 234 <= 336)
				{
					irudiaKendu(5);
					ezkutuaDu = 1;
					return 1;
				}
				break;
			case 4://Pasalekua 4 txikia
				if (powerUp2_1 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 277 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					powerUp2_1 = 1;
					indarExtra += 10;
					return 1;
				}
				break;
			case 6://Pasalekua 3 txikia
				if (powerUp2_2 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 277 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					powerUp2_2 = 1;
					bizitzaExtra+= 20;
					return 1;
				}
				break;
			default:
				break;
		}
		break;
	case 3:
		switch (gela)
		{
			case 13://giltza
				if (barraDu == 0 && playerPos.x + 117 >= 570 && playerPos.x + 117 <= 678 && playerPos.y + 234 >= 306 && playerPos.y + 234 <= 336)
				{
					irudiaKendu(5);
					barraDu = 1;
					return 1;
				}
				break;
			case 8://kontraeraso
				if (powerUp3_1 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 277 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					powerUp3_1 = 1;
					kontraerasoTotala = 1;
					return 1;
				}
				break;
			case 10://+10 de daño
				if (powerUp3_2 == 0 && playerPos.x + 117 >= 578 && playerPos.x + 117 <= 674 && playerPos.y + 234 >= 277 && playerPos.y + 234 <= 307)
				{
					irudiaKendu(5);
					powerUp3_2 = 1;
					indarExtra += 10;
					return 1;
				}
				break;
			default:
				break;
		}
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
			switch (gela)
			{
			case 3:
				if (ezkutuaDu == 0)
				{
					
					irudiaKargatu(".\\img\\PowerUp\\Ezkutu.png", 5);
					irudiaMugitu(5, 515, -40);
				}
				break;
			case 4:
				if (powerUp2_1 == 0)
				{
					irudiaKargatu(".\\img\\PowerUp\\IndarExtra.png", 5);
					irudiaMugitu(5, 285, -255);
				}
				break;
			case 6:
				if (powerUp2_2 == 0)
				{
					irudiaKargatu(".\\img\\PowerUp\\Bizitza.png", 5);
					irudiaMugitu(5, 285, -255);
				}
				break;
			}
			break;
		case 3:
			switch (gela)
			{
				case 13:
					if (barraDu == 0)
					{
						irudiaKargatu(".\\img\\PowerUp\\Giltza.png", 5);
						irudiaMugitu(5, 515, -40);
					}
					break;
				case 8:
					if (powerUp3_1 == 0)
					{
						irudiaKargatu(".\\img\\PowerUp\\Kontraerasoa.png", 5);
						irudiaMugitu(5, 285, -255);
					}
					break;
				case 10:
					if (powerUp3_2 == 0)
					{
						irudiaKargatu(".\\img\\PowerUp\\IndarExtra.png", 5);
						irudiaMugitu(5, 285, -255);
					}
					break;
				default:
					printf("ASD");
					break;
				}
			break;
		default:
			break;
	}
}