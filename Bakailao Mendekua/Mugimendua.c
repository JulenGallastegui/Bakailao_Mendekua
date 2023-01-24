#include "Mugimendua.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "OurTypes.h"
#include "NibelKolisioak.h"


int Mugimendua(int zenbat);
int TxokatzenAlDa(int zenbat);
int PausoSoinua();

extern int mugimenduaItxita;
extern int haserreNibela;

int azkenMugimendua = 0; //0: \/ 1: < 2: > 3: ^
int mugitu = 0;
int txokatzenDa;
POSIZIOA playerPos = {-117, -234}; //234 = irudiaren tamaina. 117 = 234/2 140 = eskumako oinaren X 93 = ezkerreko oinaren X

int channelPausuak = -2;
int azkenengoPausua = 1;
int pausu1 = -1, pausu2 = -1;

int kolisioa[SCREEN_WIDTH][SCREEN_HEIGHT];

extern GURE_GAUZAK gureGauzak;


int MugituPertsonaia(int ebentu, int zenbat)
{
	switch (ebentu)
	{
		case TECLA_s:
		case TECLA_DOWN:
			mugitu = 0;
			break;
		case TECLA_a:
		case TECLA_LEFT:
			mugitu = 1;
			break;
		case TECLA_d:
		case TECLA_RIGHT:
			mugitu = 2;
			break;
		case TECLA_w:
		case TECLA_UP:
			mugitu = 3;
			break;
		default:
			return 0;
	}



	if (azkenMugimendua == mugitu) //Pertsonaia mugitu
	{
		azkenMugimendua = mugitu;
		switch (Mugimendua(zenbat))
		{
			case 0:
				return 0;
			case 1:
				PausoSoinua();
				return 1;
			case 2:
				return 2;
			default:
				return -1;
		}
	}
	else //Pertsonaia rotatu
	{
		irudiaKendu(ARRAIN_GIZON_ID);
		switch (mugitu)
		{
			case 0:
				if (haserreNibela == 0)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 1)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Haserre\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 2)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Oso haserre\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);
				break;
			case 1:
				if (haserreNibela == 0)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon ezkerrera.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 1)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Haserre\\Arrain Gizon ezkerrera.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 2)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Oso haserre\\Arrain Gizon ezkerrera.png", ARRAIN_GIZON_ID);
				break;
			case 2:
				if (haserreNibela == 0)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon eskumara.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 1)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Haserre\\Arrain Gizon eskumara.png", ARRAIN_GIZON_ID);
				else if (haserreNibela == 2)
					irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Oso haserre\\Arrain Gizon eskumara.png", ARRAIN_GIZON_ID);
				break;
			case 3:
				irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Arrain Gizon goruntz.png", ARRAIN_GIZON_ID);
				PausoSoinua();
				break;
		}
		if(azkenMugimendua == 3)
			PausoSoinua();

		irudiaMugitu(ARRAIN_GIZON_ID, playerPos.x, playerPos.y);
		azkenMugimendua = mugitu;
		return 1;
	}
	
}

int Mugimendua(int zenbat)
{
	int gelditzenDirenMugimenduak = zenbat;
	int txokatzenDa = 2;
	while (gelditzenDirenMugimenduak != 0 && txokatzenDa != 1)
	{
		txokatzenDa = TxokatzenAlDa(1);
		if (txokatzenDa == 1)
			break;
		switch (mugitu)
		{
			case 0:
				playerPos.y += 1;
				break;
			case 1:
				playerPos.x -= 1;
				break;
			case 2:
				playerPos.x += 1;
				break;
			case 3:
				playerPos.y -= 1;
				break;
		}
		gelditzenDirenMugimenduak--;
	}

	irudiaMugitu(ARRAIN_GIZON_ID, playerPos.x, playerPos.y);

	if (txokatzenDa == 1 && gelditzenDirenMugimenduak == zenbat)
		return 2;

	return 1;
}

int TxokatzenAlDa(int zenbat)
{
	switch (mugitu)
	{
		case 0:
			if (kolisioa[playerPos.x + 117][playerPos.y + zenbat + 234] == 1 || //Erdiko puntua
				kolisioa[playerPos.x + 93 ][playerPos.y + zenbat + 234] == 1 || //Ezkerreko oina
				kolisioa[playerPos.x + 140][playerPos.y + zenbat + 234] == 1 || //Eskumako oina
				playerPos.y + 1 + 234 >= 700)									//Pantailaren goikaldea
			{
				return 1;
			}
			break;
		case 1:
			if (kolisioa[playerPos.x - zenbat + 93][playerPos.y + 234] == 1 || //Ezkerreko oina
				playerPos.x - 1 + 93 < 10)									   //Pantailaren ezkerraldea
			{
				return 1;
			}
			break;
		case 2:
			if (kolisioa[playerPos.x + zenbat + 140][playerPos.y + 234] == 1 || //Eskumako oina
				playerPos.x + 1 + 140 >= 690)									//Pantailaren eskumaldea
			{
				return 1;
			}
			break;
		case 3:
			if (kolisioa[playerPos.x + 117][playerPos.y - zenbat + 234] == 1 || //Erdiko puntua
				kolisioa[playerPos.x + 93] [playerPos.y - zenbat + 234] == 1 || //Ezkerreko oina
				kolisioa[playerPos.x + 140][playerPos.y - zenbat + 234] == 1 || //Eskumako oina
				playerPos.y - 1 + 234 < 0)										//Pantailako behekaldea
			{
				return 1;
			}
			break;
	}
	return 0;
}

int KolisioakSortu(char* mapaIzena)
{
	if (mapaIzena == "menu")
		return KolisioaJaso(-1, 0, kolisioa);
	else if (mapaIzena == "anden1")
		return KolisioaJaso(1, 0, kolisioa);
	else if (mapaIzena == "pasaleku1_1")
		return KolisioaJaso(1, 2, kolisioa);
	else if (mapaIzena == "sarrera1")
		return KolisioaJaso(1, 1, kolisioa);
	else if (mapaIzena == "pasaleku1_2")
		return KolisioaJaso(1, 4, kolisioa);
	else if (mapaIzena == "pasaleku1_3")
		return KolisioaJaso(1, 5, kolisioa);
	else if (mapaIzena == "pasaleku1_4")
		return KolisioaJaso(1, 3, kolisioa);
	else if (mapaIzena == "pasaleku1_5")
		return KolisioaJaso(1, 6, kolisioa);
	else if (mapaIzena == "buruzagia1")
		return KolisioaJaso(1, 7, kolisioa);
	else if (mapaIzena == "akuarioarenSarrera1")
		return KolisioaJaso(1, -1, kolisioa);
	
	return 0;
}

int PausuSoinuakKargatu(char* mapaIzena)
{
	if (mapaIzena == "menu" || mapaIzena == "sarrera1" || mapaIzena == "pasaleku1_1" || mapaIzena == "pasaleku1_2" || mapaIzena == "pasaleku1_3" || mapaIzena == "pasaleku1_4" || mapaIzena == "pasaleku1_5" || mapaIzena == "buruzagia1")
	{
		if (haserreNibela == 0)
		{
			pausu1 = 2;
			pausu2 = 3;
		}
		else if (haserreNibela == 1)
		{
			pausu1 = 6;
			pausu2 = 7;
		}
		else if (haserreNibela == 2)
		{
			pausu1 = 10;
			pausu2 = 11;
		}
		return 1;
	} 
	else if (mapaIzena == "anden1" || mapaIzena == "akuarioarenSarrera1")
	{
		if (haserreNibela == 0)
		{
			pausu1 = 0;
			pausu2 = 1;
		} 
		else if (haserreNibela == 1)
		{
			pausu1 = 4;
			pausu2 = 5;
		}
		else if (haserreNibela == 2)
		{
			pausu1 = 8;
			pausu2 = 9;
		}
		return 1;
	}

	return 0;
}

int MugimenduaHasieratu(int x, int y, char* mapaIzena)
{
	if (KolisioakSortu(mapaIzena) == 0 || PausuSoinuakKargatu(mapaIzena) == 0)
		return -1;

	if (x >= 700 || x < 0 || y >= 700 || y < 0)
		return 0;

	if (kolisioa[x][y] == 1)
		return -2;

	playerPos.x = -117 + x;
	playerPos.y = -234 + y;

	if (haserreNibela == 0)
		irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);
	else if (haserreNibela == 1)
		irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Haserre\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);
	else if (haserreNibela == 2)
		irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Oso haserre\\Arrain Gizon behera.png", ARRAIN_GIZON_ID);

	irudiaMugitu(ARRAIN_GIZON_ID, playerPos.x, playerPos.y);

	azkenMugimendua = 0;

	mugimenduaItxita = 0;

	return 1;
}

int PausoSoinua()
{
	if (channelPausuak == -2 || soinuaDago(channelPausuak) == 0)
	{

		azkenengoPausua = azkenengoPausua == pausu2 ? pausu1 : pausu2;

		channelPausuak = playSound(azkenengoPausua);
	}
	

	return 1;
}
