#include "NibelKolisioak.h"
#include "graphics.h"
#include "Mugimendua.h"
#include "ebentoak.h"
#include "imagen.h"
#include "OurTypes.h"
#include <stdio.h>
#include "pantailaAldatu.h"

GURE_GAUZAK gureGauzak;
POSIZIOA pos;
int piztu = 0;
int geziak[SCREEN_WIDTH][SCREEN_HEIGHT];
extern int gela;
extern int akuarioa;
extern POSIZIOA playerPos;

int AldatuGela(int ebentu)
{
	switch (ebentu)
	{

	case TECLA_e:
		PantailaAldatu();
		break;
	default:
		break;
	}
}

int PantailaAldatu()
{
	switch (akuarioa)
	{
	case -1:
		if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
		{
			akuarioa = 0;
			gela = 1;
		}
		else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			return -1;
		break;
	case 0:
		switch (gela)
		{
		case -1:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 0;
			}

			break;
		case 0:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = -1;
			}
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 2;
			}
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
			{
				gela = 1;
			}

			break;
		case 1:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 0;
			}

			break;
		case 2:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 0;
			}
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 3;
			}

			break;
		case 3:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 2;
			}
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 4;
			}

			break;
		default:
			break;
		}

		break;
	case 1:

		switch (gela)
		{
		case -1:
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 0;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 8;
			}


			break;
		case 0: //akuarioaren sarrera
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = -1;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 1;
			}
			break;
		case 1://sarrera
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 0;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 2;
			}
			break;
		case 2://Pasalekua 1
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 3;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 1;
			}

			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
			{
				gela = 4;
			}
			break;
		case 3://Pasalekua 4
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 2;
			}
			break;
		case 4://Pasalekua 2
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 2;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 5;
			}
			break;
		case 5://Pasalekua 3
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 4;
			}
			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
			{
				gela = 7;
			}

			else if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
			{
				gela = 6;
			}
			break;
		case 6://Pasalekua 5
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 5;
			}

			break;
		case 7://buruzagi
			if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
			{
				gela = 5;
			}

			break;
		default:
			break;
		}

		break;
	case 2:
		switch (gela)
		{
			case -1:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 0;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 8;
				}
				break;
			case 0: //akuarioaren sarrera
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = -1;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 1;
				}
				break;
			case 1://sarrera
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 0;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 2;
				}
				break;
			case 2://Pasalekua 1
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 3;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 1;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 4;
				}
				break;
			case 3://Pasalekua 2
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 2;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 5;
				}
				break;
			case 4://Pasalekua 4
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 2;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 5;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 6;
				}
				break;
			case 5://Pasalekua 5
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 3;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 7;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 4;
				}
				break;
			case 6://Pasalekua 3
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 4;
				}
				break;
			case 7://Pasalekua 6
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 5;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 9;
				}
				break;
			case 9://Pasalekua 7
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 7;
				}
				else if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 10;
				}
				break;
			case 10://buruzagia
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 9;
				}
				break;
			default:
				break;
		}
		break;
	case 3:
		switch (gela)
		{
			case -1:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 0;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 14;
				}
				break;
			case 0:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = -1;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 1;
				}
				break;
			case 1:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 0;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 2;
				}
				break;
			case 2:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 1;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 13;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 3;
				}
				break;
			case 3:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 2;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 4;
				}
				break;
			case 4:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 3;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 5;
				}
				break;
			case 5:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 4;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 6;
				}
				break;
			case 6:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 7;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 5;
				}
				break;
			case 7:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 6;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 8;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 9;
				}
				break;
			case 8:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 7;
				}
				break;
			case 9:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 11;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 7;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 3)
				{
					gela = 10;
				}
				break;
			case 10:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 9;
				}
				break;
			case 11:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 9;
				}
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 2)
				{
					gela = 12;
				}
				break;
			case 12:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 11;
				}

				break;
			case 13:
				if (geziak[playerPos.x + 117][playerPos.y + 234] == 1)
				{
					gela = 2;
				}
				break;
			default:
				break;
		}
		break;
	default:
		break;
	}
}
int GeziakHasieratu(char* mapaIzena)
{
	if (mapaIzena == "menu")
		GeziakJaso(-1, 0, geziak);
	else if (mapaIzena == "anden1")
		GeziakJaso(1, -1, geziak);
	else if (mapaIzena == "akuarioarenSarrera1")
		GeziakJaso(1, 0, geziak);
	else if (mapaIzena == "sarrera1")
		GeziakJaso(1, 1, geziak);
	else if (mapaIzena == "pasaleku1_1")
		GeziakJaso(1, 2, geziak);
	else if (mapaIzena == "pasaleku1_2")
		GeziakJaso(1, 4, geziak);
	else if (mapaIzena == "pasaleku1_3")
		GeziakJaso(1, 5, geziak);
	else if (mapaIzena == "pasaleku1_4")
		GeziakJaso(1, 3, geziak);
	else if (mapaIzena == "pasaleku1_5")
		GeziakJaso(1, 6, geziak);
	else if (mapaIzena == "buruzagia1")
		GeziakJaso(1, 7, geziak);
	else if (mapaIzena == "anden2")
		GeziakJaso(1, -1, geziak);
	else if (mapaIzena == "akuarioarenSarrera2")
		GeziakJaso(1, 0, geziak);
	else if (mapaIzena == "sarrera2")
		GeziakJaso(2, 1, geziak);
	else if (mapaIzena == "pasaleku2_1")
		GeziakJaso(2, 2, geziak);
	else if (mapaIzena == "pasaleku2_2")
		GeziakJaso(2, 3, geziak);
	else if (mapaIzena == "pasaleku2_3")
		GeziakJaso(2, 6, geziak);
	else if (mapaIzena == "pasaleku2_4")
		GeziakJaso(2, 4, geziak);
	else if (mapaIzena == "pasaleku2_5")
		GeziakJaso(2, 5, geziak);
	else if (mapaIzena == "pasaleku2_6")
		GeziakJaso(2, 7, geziak);
	else if (mapaIzena == "pasaleku2_7")
		GeziakJaso(2, 9, geziak);
	else if (mapaIzena == "buruzagia2")
		GeziakJaso(2, 10, geziak);
	else if (mapaIzena == "Hondartza")
		GeziakJaso(0, -1, geziak);
	else if (mapaIzena == "Etxea")
		GeziakJaso(0, 0, geziak);
	else if (mapaIzena == "CuartoPrincipal")
		GeziakJaso(0, 1, geziak);
	else if (mapaIzena == "Geltokirabidea")
		GeziakJaso(0, 2, geziak);
	else if (mapaIzena == "anden0")
		GeziakJaso(0, 3, geziak);
	else if (mapaIzena == "anden3")
		GeziakJaso(3, -1, geziak);
	else if (mapaIzena == "Akuarioaren sarrera3")
		GeziakJaso(3, 0, geziak);
	else if (mapaIzena == "sarrera3")
		GeziakJaso(3, 1, geziak);
	else if (mapaIzena == "pasaleku3_1")
		GeziakJaso(3, 2, geziak);
	else if (mapaIzena == "pasaleku3_3")
		GeziakJaso(3, 3, geziak);
	else if (mapaIzena == "pasaleku3_4")
		GeziakJaso(3, 4, geziak);
	else if (mapaIzena == "pasaleku3_5")
		GeziakJaso(3, 5, geziak);
	else if (mapaIzena == "pasaleku3_6")
		GeziakJaso(3, 6, geziak);
	else if (mapaIzena == "pasaleku3_7")
		GeziakJaso(3, 7, geziak);
	else if (mapaIzena == "pasaleku3_8")
		GeziakJaso(3, 8, geziak);
	else if (mapaIzena == "pasaleku3_9")
		GeziakJaso(3, 9, geziak);
	else if (mapaIzena == "pasaleku3_10")
		GeziakJaso(3, 10, geziak);
	else if (mapaIzena == "pasaleku3_11")
		GeziakJaso(3, 11, geziak);
	else if (mapaIzena == "buruzagia3")
		GeziakJaso(3, 12, geziak);
	else if (mapaIzena == "pasaleku3_2")
		GeziakJaso(3, 13, geziak);
	else
		return 0;

	return 1;
}
int MaparenAukerak(void)
{
	irudiaKargatu(".\\img\\Mapa.png", 0);
	int irten = 0;
	int ebentu = 0;
	while (!irten)
	{
		ebentu = ebentuaJasoGertatuBada();
		pantailaGarbitu();
		if (ebentu == GERTAERA_IRTEN)
			return -1;
		else if (ebentu == SAGU_BOTOIA_EZKERRA)
		{
			pos = saguarenPosizioa();
			
			if (pos.x > 93 && pos.x < 214 && pos.y > 584 && pos.y < 700) //Etxea
			{
				//irudiaKendu(0);
				//gureGauzak.idIrudiak[0] = irudiaKargatu(".\\img\\0.png", 0);
				akuarioa = 0;
				gela = 3;
				irten = 1;
			}
			if (pos.x > 99 && pos.x < 222 && pos.y > 368 && pos.y < 493) //akuario 1
			{

				akuarioa = 1;
				gela = -1;
				irten = 1;
			}
			else if (pos.x > 134 && pos.x < 251 && pos.y > 93 && pos.y < 205) //akuario 2
			{

				akuarioa = 2;
				gela = -1;
				irten = 1;
			}
			else if (pos.x > 414 && pos.x < 681 && pos.y > 176 && pos.y < 295) //akuario 3
			{

				akuarioa = 3;
				gela = -1;
				irten = 1;
			}

		}

		irudiakMarraztu();
		pantailaBerriztu();
	}
	return 1;
}