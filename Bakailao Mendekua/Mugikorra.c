#define _CRT_SECURE_NO_WARNINGS
#include "Mugikorra.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "imagen.h"
#include "graphics.h"
#include <stdio.h>

void NolaJolastuTestuaJarri(void);
int NolaJolastuTestuaJaso(int zein, char *testua);
int ArratoiaErabiliz(int scrollMax);
void BarraMugitu(int scrollMax);
int SaguPosAztertu(int scrollMax);

void BolumenKontrolenTestua(void);

extern SDL_Color textColor;

int posNolaJolastu = 0;
int posNolaJolastuMax = 64;
int arratoia = 0;

extern int ctrl;

int menua = 0;

POSIZIOA saguPos = { 0, 0 };

int MugikorraAtera(void)
{
	int ebentu = 0;
	int irten = 0;
	int scrollMax = posNolaJolastuMax - 14 < 0 ? 0 : posNolaJolastuMax - 14;
	int menuraBueltatu = 0;

	SDL_Color koloreZaharra = textColor;

	textColor.r = 0;
	textColor.g = 0;
	textColor.b = 0;

	if (menua == 0)
	{
		irudiaKargatu(".\\img\\Mugikorra\\Nola jolastu.png", MAX_IMG - 2);
		irudiaKargatu(".\\img\\Mugikorra\\Nola jolastu gurpila.png", MAX_IMG - 1);
	}
	else
	{
		irudiaKargatu(".\\img\\Mugikorra\\Mugikorra bolumen.png", MAX_IMG - 1);
	}

	while (irten == 0)
	{
		pantailaGarbitu();

		ebentu = ebentuaJasoGertatuBada();
		if(menua == 0) 
			bolumenaAldatu(ebentu);

		saguPos = saguarenPosizioa();

		switch (ebentu)
		{
			case TECLA_ESCAPE:
			case TECLA_n:
				irten = 1;
				break;
			case GERTAERA_IRTEN:
				return -1;
			case SAGU_SCROLL_GORA:
			case TECLA_w:
			case TECLA_a:
			case TECLA_UP:
			case TECLA_LEFT:
				if(menua == 0 && posNolaJolastu != 0 && arratoia == 0)
					posNolaJolastu--;
				break;
			case SAGU_SCROLL_BEHERA:
			case TECLA_s:
			case TECLA_d:
			case TECLA_DOWN:
			case TECLA_RIGHT:
				if(menua == 0 && posNolaJolastu != scrollMax && arratoia == 0)
					posNolaJolastu++;
				break;
			case SAGU_BOTOIA_EZKERRA_DOWN:
				switch (SaguPosAztertu(scrollMax))
				{
					case 1:
						irten = 1;
						break;
					case 2:
						irten = 1;
						menuraBueltatu = 1;
						break;
				}
				break;
			case SAGU_BOTOIA_EZKERRA:
				//Barra soltatu du
				if(menua == 0)
					arratoia = 0;

				break;
			case SAGU_MUGIMENDUA:
				//Barra sakatzen eta arratoia mugitzen dago
				if(menua == 0 && arratoia == 1)
					posNolaJolastu = ArratoiaErabiliz(scrollMax);

				break;
			default:
				break;
		}

		if (menua == 0)
		{
			BarraMugitu(scrollMax); //Barra egon behar den tokian jarri
			irudiakMarraztu();
			NolaJolastuTestuaJarri(); //Ikusten den testua jarri
		}
		else
		{
			irudiakMarraztu();
			BolumenKontrolenTestua();
		}
		pantailaBerriztu();
	}

	irudiaKendu(MAX_IMG - 1);
	irudiaKendu(MAX_IMG - 2);
	pantailaBerriztu();
	textColor = koloreZaharra;

	if (menuraBueltatu == 1)
		return -2;

	return 1;
}

int SaguPosAztertu(int scrollMax)
{
	//Barran sakatu du
	if (menua == 0 && saguPos.x > 580 && saguPos.x < 600 && saguPos.y <= (float)290 / scrollMax * posNolaJolastu + 310 && saguPos.y >= (float)290 / scrollMax * posNolaJolastu + 280)
		arratoia = 1;
	//Bueltatzeko gezian sakatu du
	else if (saguPos.x >= 334 && saguPos.x <= 365 && saguPos.y >= 624 && saguPos.x <= 660)
		return 1;
	//Etxean sakatu du (hasierako menura bueltatu)
	else if (saguPos.x >= 429 && saguPos.x <= 465 && saguPos.y >= 624 && saguPos.x <= 660)
	{
		return 2;
	}
	//Marretan sakatu du
	else if (saguPos.x >= 529 && saguPos.x <= 570 && saguPos.y >= 624 && saguPos.x <= 660)
	{
		menua = menua == 1 ? 0 : 1;
		if (menua == 1)
		{
			irudiaKendu(MAX_IMG - 1);
			irudiaKargatu(".\\img\\Mugikorra\\Mugikorra bolumen.png", MAX_IMG - 2);
		}
		else
		{
			irudiaKargatu(".\\img\\Mugikorra\\Nola jolastu gurpila.png", MAX_IMG - 1);
			irudiaKargatu(".\\img\\Mugikorra\\Nola jolastu.png", MAX_IMG - 2);
		}
	}
	//Bolumenaren ikurrak
	else if (menua == 1 && saguPos.x >= 506 && saguPos.x <= 527 && saguPos.y >= 330 && saguPos.y <= 342) //Musika jaitsi
	{
		if(MusikaBolumenaJaso() - 1 != -1)
			musikarenBolumena(MusikaBolumenaJaso() - 1);
	}
	else if (menua == 1 && saguPos.x >= 531 && saguPos.x <= 550 && saguPos.y >= 330 && saguPos.y <= 342) //Musika kendua
	{
		musikarenBolumena(0);
	}
	else if (menua == 1 && saguPos.x >= 554 && saguPos.x <= 575 && saguPos.y >= 330 && saguPos.y <= 342) //Musika igo
	{
		if (MusikaBolumenaJaso() + 1 != 9)
			musikarenBolumena(MusikaBolumenaJaso() + 1);
	}
	else if (menua == 1 && saguPos.x >= 506 && saguPos.x <= 527 && saguPos.y >= 400 && saguPos.y <= 412) //Efektuak jaitsi
	{
		if (SoinuenBolumenaJaso() - 1 != -1)
			soinuenBolumena(SoinuenBolumenaJaso() - 1);
	}
	else if (menua == 1 && saguPos.x >= 531 && saguPos.x <= 550 && saguPos.y >= 400 && saguPos.y <= 412) //Efektuak kendua
	{
		soinuenBolumena(0);
	}
	else if (menua == 1 && saguPos.x >= 554 && saguPos.x <= 575 && saguPos.y >= 400 && saguPos.y <= 412) //Efektuak igo
	{
		if (SoinuenBolumenaJaso() + 1 != 9)
			soinuenBolumena(SoinuenBolumenaJaso() + 1);
	}
	return 0;
}

void NolaJolastuTestuaJarri(void)
{
	char testua[255];
	for (int i = posNolaJolastu; i <= posNolaJolastu + 14; i++)
	{
		//TestuaJaso funtzioak "testua" string-an sartzen du testua, eta zenbat mugitu behar den testua x ardatzan bueltatzen du.
		textuaIdatzi(310 + NolaJolastuTestuaJaso(i, testua), 290 + i * 20 - posNolaJolastu * 20, testua);
	}
}

int ArratoiaErabiliz(int scrollMax)
{
	int pos = saguPos.y;

	if (pos < 280)
		pos = 280;
	else if (pos > 570) //Barra mugikorratik atera ez dezan
		pos = 570;

	return (pos - 280) * scrollMax / (570 - 280); //Iruko erregela aplikatu barraren posizioa lortzeko
}

void BarraMugitu(int scrollMax)
{
	if (arratoia == 0) //Gurpilakin mugitu da
	{
		irudiaMugitu(MAX_IMG - 1, 0, (float)290 / scrollMax * posNolaJolastu);
	}
	else //Barra erabiliz mugitu da
	{
		int pos = saguPos.y;

		if (pos > 585)
			pos = 585;
		else if (pos < 295) //Barra mugikorratik atera ez dezan
			pos = 295;

		irudiaMugitu(MAX_IMG - 1, 0, pos - 295);
	}
}

void BolumenKontrolenTestua(void)
{
	char musika[2], efektua[2];
	textuaIdatzi(330, 330, "Musikaren bolumena:");
	textuaIdatzi(340, 400, "Efektuen bolumena:");
	sprintf(musika, "%d", MusikaBolumenaJaso());
	sprintf(efektua, "%d", SoinuenBolumenaJaso());
	musika[1] = '\0';
	efektua[1] = '\0';
	textuaIdatzi(470, 330, musika);
	textuaIdatzi(480, 330, "/ 8");
	textuaIdatzi(470, 400, efektua);
	textuaIdatzi(480, 400, "/ 8");
}

int NolaJolastuTestuaJaso(int zein, char *testua)
{
	int xExtra = 0;
	switch (zein)
	{
		case 0://                 "--idazteko lekua gutxi gorabehera--");
			sprintf(testua, "%s", "NOLA MUGITU");
			xExtra = 75;
			break;
		case 1:
			sprintf(testua, "%s", "Geziak edo \"wasd\" teklak erabiliz.");
			break;
		case 2:
			sprintf(testua, "%s", " ");
			break;
		case 3:
			sprintf(testua, "%s", "NOLA ALDATU GELAZ");
			xExtra = 50;
			break;
		case 4:
			sprintf(testua, "%s", "Gelaz aldatzeko, gezi baten gainean");
			break;
		case 5:
			sprintf(testua, "%s", "kokatu behar zara, eta \"e\" tekla sakatu.");
			break;
		case 6:
			sprintf(testua, "%s", " ");
			break;
		case 7:
			sprintf(testua, "%s", "NOLA BORROKATU");
			xExtra = 65;
			break;
		case 8:
			sprintf(testua, "%s", "Borrokatzerakoan, 4 aukera daude:");
			break;
		case 9:
			sprintf(testua, "%s", "erasotzeko, sendatzeko, kontraerasotzeko");
			break;
		case 10:
			sprintf(testua, "%s", "eta objetuen menua ateratzeko.");
			break;
		case 11:
			sprintf(testua, "%s", " ");
			break;
		case 12:
			sprintf(testua, "%s", "Erasotzeko botoia:");
			xExtra = 20;
			break;
		case 13:
			sprintf(testua, "%s", "Etsaiari erasotzeko balio du.");
			break;
		case 14:
			sprintf(testua, "%s", "Jokoaren hasierako indarra: 20");
			break;
		case 15:
			sprintf(testua, "%s", " ");
			break;
		case 16:
			sprintf(testua, "%s", "Sendatzeko botoia:");
			xExtra = 20;
			break;
		case 17:
			sprintf(testua, "%s", "Arrain Gizon sendatzeko balio du.");
			break;
		case 18:
			sprintf(testua, "%s", "Jokoaren hasierako sendaketa: 20");
			break;
		case 19:
			sprintf(testua, "%s", " ");
			break;
		case 20:
			sprintf(testua, "%s", "Kontraerasotzeko botoia:");
			xExtra = 20;
			break;
		case 21:
			sprintf(testua, "%s", "Etsaiaren erasoa sahiesteko eta egin");
			break;
		case 22:
			sprintf(testua, "%s", "behar zuen minaren erdia bueltatzeko."); 
			break;
		case 23:
			sprintf(testua, "%s", " ");
			break;
		case 24:
			sprintf(testua, "%s", "Objetuak:");
			xExtra = 20;
			break;
		case 25:
			sprintf(testua, "%s", "Ur botila:");
			xExtra = 40;
			break;
		case 26:
			sprintf(testua, "%s", "50 puntu sendatzeko balio du.");
			break;
		case 27:
			sprintf(testua, "%s", "Barra:");
			xExtra = 40;
			break;
		case 28:
			sprintf(testua, "%s", "Etsaiari erasotzeko min bikoitza eginez.");
			break;
		case 29:
			sprintf(testua, "%s", "Ezkutua:");
			xExtra = 40;
			break;
		case 30:
			sprintf(testua, "%s", "Etsaiaren bi hurrengo erasoetan min");
			break;
		case 31:
			sprintf(testua, "%s", "erdia jasotzeko balio du.");
			break;
		case 32:
			sprintf(testua, "%s", " ");
			break;
		case 33:
			sprintf(testua, "%s", "NOLA ALDATU BOLUMENA"); 
			xExtra = 50;
			break;
		case 34:
			sprintf(testua, "%s", "Musikaren bolumena igotzeko: ctrl + i");
			break;
		case 35:
			sprintf(testua, "%s", "Musikaren bolumena geizteko: ctrl + k");
			break;
		case 36:
			sprintf(testua, "%s", "Efektuen bolumena igotzeko: ctrl + o");
			break;
		case 37:
			sprintf(testua, "%s", "Efektuen bolumena igotzeko: ctrl + l");
			break;
		case 38:
			sprintf(testua, "%s", "Edo mugikorraren 3 lineei heman.");
			break;
		case 39:
			sprintf(testua, "%s", " ");
			break;
		case 40:
			sprintf(testua, "%s", "NOLA ERABILI EGUNKARIA");
			xExtra = 50;
			break;
		case 41:
			sprintf(testua, "%s", "Etxetik hartu baldin baduzu,");
			break;
		case 42:
			sprintf(testua, "%s", "b sakatu sabaltzeko, eta b edo esc ixteko.");
			break;
		case 43:
			sprintf(testua, "%s", "Orriak pasatzeko, ezker/eskuin geziak,");
			break;
		case 44:
			sprintf(testua, "%s", "a, d, edo saguaren gurpila erabili.");
			break;
		case 45:
			sprintf(testua, "%s", " ");
			break;
		case 46:
			sprintf(testua, "%s", "MUGIKORRAREN AUKERAK");
			xExtra = 50;
			break;
		case 47:
			sprintf(testua, "%s", "n edo esc sakatuz sabaldu eta itxi.");
			break;
		case 48:
			sprintf(testua, "%s", "Mugikorraren geziarekin itxi ahal da ere.");
			break;
		case 49:
			sprintf(testua, "%s", "Etxea sakatu hasierako menura");
			break;
		case 50:
			sprintf(testua, "%s", "bueltatzeko.");
			break;
		case 51:
			sprintf(testua, "%s", "3 lineak sakatu bolumenaren menua");
			break;
		case 52:
			sprintf(testua, "%s", "sabaltzeko.");
			break;
		case 53:
			sprintf(testua, "%s", " ");
			break;
		case 54:
			sprintf(testua, "%s", "NOLA ERABILI TRENA");
			xExtra = 55;
			break;
		case 55:
			sprintf(testua, "%s", "Trenean sartzerakoan mapa bat agertzen");
			break;
		case 56:
			sprintf(testua, "%s", "da.");
			break;
		case 57:
			sprintf(testua, "%s", "Bertan klik egin joan nahi zaren lekura.");
			break;
		case 58:
			sprintf(testua, "%s", " ");
			break;
		case 59:
			sprintf(testua, "%s", "KREDITUAK");
			xExtra = 85;
			break;
		case 60:
			sprintf(testua, "%s", "Julen Gallastegui");
			xExtra = 65;
			break;
		case 61:
			sprintf(testua, "%s", "Haimar Ariceta");
			xExtra = 75;
			break;
		case 62:
			sprintf(testua, "%s", "Martin Preguntegi");
			xExtra = 65;
			break;
		case 63:
			sprintf(testua, "%s", "Aitor Ortiz");
			xExtra = 90;
			break;
		case 64:
			sprintf(testua, "%s", "Marco Martínez");
			xExtra = 75;
			break;
		default:
			sprintf(testua, "%s", "---");
			xExtra = 250;
			break;
	}

	return xExtra;
}