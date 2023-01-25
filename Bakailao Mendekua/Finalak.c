#define _CRT_SECURE_NO_WARNINGS
#include "Finalak.h"
#include "graphics.h"
#include "imagen.h"
#include "text.h"
#include "soinua.h"
#include "ebentoak.h"
#include "stdio.h"

int Dialogoak(int buruzagia);
int Animazioa(int buruzagia);
void TestuFinalaJaso(int buruzagia, int zein, char* testua);

int BuruzagiAnimazioa(int zein)
{

	kargatuMusika(".\\sound\\BuruzagiaIrabazita.wav");

	if (Dialogoak(zein) == -1)
		return -1;

	if(Animazioa(zein) == -1)
		return -1;

	irudiaKendu(1);
	irudiaKendu(2);
	irudiaKendu(9);
	return 2;
}

int Dialogoak(int buruzagia)
{
	int irten = 1;
	int bukatuta = 0;
	char testua[255];
	int max = 0;

	irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon behera.png", 1);
	if (buruzagia == 1)
	{
		irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi1.png", 2);
		max = 12;
	}
	else if (buruzagia == 2)
	{
		irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi2.png", 2);
		max = 12;
	}
	else if (buruzagia == 3)
	{
		irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi3.png", 2);
		max = 21;
	}

	irudiaMugitu(1, 130, 175);
	irudiaMugitu(2, 380, 175);
	irudiakMarraztu();
	pantailaBerriztu();

	textuaGaitu(22);

	for (int i = 0; i <= max; i++)
	{
		TestuFinalaJaso(buruzagia, i, testua);
		textuaIdatziPixkanaka(50, 600, 10, testua);
		irten = 0;
		while (!irten)
		{
			pantailaGarbitu();
			switch (ebentuaJasoGertatuBada())
			{
				case TECLA_e:
				case SAGU_BOTOIA_EZKERRA:
				case TECLA_SPACE:
					irten = 1;
					break;
				case GERTAERA_IRTEN:
					return -1;
			}
			irudiakMarraztu();
			if(!irten)
			textuaIdatzi(50, 600, testua);
			pantailaBerriztu();
		}
	}

	textuaGaitu(14);

	return 1;

}

int Animazioa(int buruzagia)
{

	int irten = 0;
	int hasiera = 0;

	for (int i = 0; i < 4; i++)
	{
		printf("a%d\n", i);
		pantailaGarbitu();
		if (i == 0)
			irudiaKargatu(".\\img\\Finala\\Irabazi1.png", 9);
		else if(i == 1)
			irudiaKargatu(".\\img\\Finala\\Irabazi2.png", 9);
		else if(i == 2)
			irudiaKargatu(".\\img\\Finala\\Irabazi3.png", 9);
		else if(i == 3)
			irudiaKargatu(".\\img\\Finala\\Irabazi4.png", 9);
		irudiakMarraztu();
		pantailaBerriztu();
		hasiera = SDL_GetTicks();
		while (SDL_GetTicks() - hasiera < 100)
		{
			if (ebentuaJasoGertatuBada() == GERTAERA_IRTEN)
				return -1;
		}
		printf("b%d\n", i);
	}
	pantailaGarbitu();
	irudiaKargatu(".\\img\\Finala\\Irabazi5.png", 9);
	irudiakMarraztu();
	pantailaBerriztu();
	hasiera = SDL_GetTicks();
	while (!irten)
	{
		switch (ebentuaJasoGertatuBada())
		{
			case GERTAERA_IRTEN:
				return -1;
			case TECLA_e:
				irten = 1;
				break;
			default:
				break;
		}
	}

	return 1;
}

void TestuFinalaJaso(int buruzagia, int zein, char *testua)
{
	switch (buruzagia)
	{
		case 1:
			switch (zein)
			{
				case 0:
					sprintf(testua, "%s", "Arraingizon: Irabazi dizut, horain arrainak askatu.");
					break;
				case 1:
					sprintf(testua, "%s", "Elon Crab: Baina zu nor zara?");
					break;
				case 2:
					sprintf(testua, "%s", "E.C.: Zergatik nahi duzu arrainak askatzea?");
					break;
				case 3:
					sprintf(testua, "%s", "A.G: Ni Arraingizon naiz.");
					break;
				case 4:
					sprintf(testua, "%s", "A.G.: eta arrainak askatu nahi ditut esperimentazioak gelditzeko.");
					break;
				case 5:
					sprintf(testua, "%s", "E.C.: Barkatu? Zertaz hitz egiten zaude?");
					break;
				case 6:
					sprintf(testua, "%s", "A.G.: Ez egin zoroarena, badakizu zertaz hari naizen.");
					break;
				case 7:
					sprintf(testua, "%s", "E.C.: Eta nola dakizu esperimentazioei buruz?");
					break;
				case 8:
					sprintf(testua, "%s", "A.G.: Arrain bihurtzen nago zuen marmoka batek ziztatu ninduelako,");
					break;
				case 9:
					sprintf(testua, "%s", "A.G.: eta orain oroimen galerak eta aldaketa fisikoak dauzkat.");
					break;
				case 10:
					sprintf(testua, "%s", "A.G.: Ez badituzu arrainak liberatzen, arrain bihurtuko zaitut.");
					break;
				case 11:
					sprintf(testua, "%s", "E.C.: Familia daukat mesedez, ez bihurtu nazazu arraina.");
					break;
				case 12:
					sprintf(testua, "%s", "E.C.: Egia esanda, soldata txikia daukat. Arrainak liberatuko ditut.");
					break;
			}
			break;
		case 2: 
			switch (zein)
			{
				case 0:
					sprintf(testua, "%s", "Arraingizon: Irabazi dizut, horain arrainak askatu.");
					break;
				case 1:
					sprintf(testua, "%s", "Jeff Besuga: Zu Arraingizon zara, ezta?");
					break;
				case 2:
					sprintf(testua, "%s", "A.G.: Ala da.");
					break;
				case 3:
					sprintf(testua, "%s", "J.B.: Arrainak askatu nahi dituzu?");
					break;
				case 4:
					sprintf(testua, "%s", "A.G.: Bai, edo nire bidea ostopatuko duzu?");
					break;
				case 5:
					sprintf(testua, "%s", "J.B.: Elon Crab-ek erraz amore eman zuen");
					break;
				case 6:
					sprintf(testua, "%s", "J.B.: baina bakarrik soldata txikia zuelako.");
					break;
				case 7:
					sprintf(testua, "%s", "J.B.: Nik hirukoitza irabazten dut, ez ditut arrainak soltatuko.");
					break;
				case 8:
					sprintf(testua, "%s", "A.G.: Zure soldata ez zait axola, arrainak ez badituzu askatzen,");
					break;
				case 9:
					sprintf(testua, "%s", "A.G.: arrainekin botako dizut.");
					break;
				case 10:
					sprintf(testua, "%s", "J.B.: Ongi da, nahiago dut gutxiago irabazi, arrainekin bizi baino.");
					break;
				case 11:
					sprintf(testua, "%s", "J.B.: Askatuko ditut.");
					break;
				case 12:
					sprintf(testua, "%s", "A.G.: Hobe duzu.");
					break;
			}
			break;
		case 3:
			switch (zein)
			{
			case 0:
				sprintf(testua, "%s", "Arraingizon: Bakailaoman, irabazi dizut.");
				break;
			case 1:
				sprintf(testua, "%s", "Bakailaoman: blblblblblblblblblblblblblbl");
				break;
			case 2:
				sprintf(testua, "%s", "A.G.: Arrain hitz egiten duzu? Uste nuen pertsona bat zinela...");
				break;
			case 3:
				sprintf(testua, "%s", "B.M.: (itzulita) Ez, ni bakailao bat nintzen jaiotzan,");
				break;
			case 4:
				sprintf(testua, "%s", "B.M.: baina izpi kosmiko batek jo ninduen eta eboluzionatu dut.");
				break;
			case 5:
				sprintf(testua, "%s", "A.G.: Baina zergatik egiten dituzu esperimentuak bakailaoekin?");
				break;
			case 6:
				sprintf(testua, "%s", "B.M.: Itsasokoek pentsatzen dute arrain perfektua lortu nahi dudala,");
				break;
			case 7:
				sprintf(testua, "%s", "B.M.: baina ni bezalako arrain gehiago nahi ditut munduan,");
				break;
			case 8:
				sprintf(testua, "%s", "B.M.: eta nire klonak sortzen saiatzen hari naiz.");
				break;
			case 9:
				sprintf(testua, "%s", "A.G: Baina zergatik? Bakarrik sentitzen zara?");
				break;
			case 10:
				sprintf(testua, "%s", "B.M.: Karkarkar! Ez, ez da horregatik.");
				break;
			case 11:
				sprintf(testua, "%s", "B.M.: Nire klonak sortu nahi ditut mundu osoaren jabea izateko!");
				break;
			case 12:
				sprintf(testua, "%s", "A.G: Badirudi ez dela posible izan behar zure ideiak aldatzea,");
				break;
			case 13:
				sprintf(testua, "%s", "A.G: Ondorioz, bi aukera emango dizkizut: ");
				break;
			case 14:
				sprintf(testua, "%s", "A.G: 1: Arrainontzi txiki batean igaro zure bizitza osoa.");
				break;
			case 15:
				sprintf(testua, "%s", "A.G: 2: Itzuli itsasora, eta otoitz egin zure bizitzaren alde.");
				break;
			case 16:
				sprintf(testua, "%s", "B.M.: Nola? Benetan uste duzu horrela tratatu ahal nazakezula?");
				break;
			case 17:
				sprintf(testua, "%s", "A.G: Erantzun. Bat edo bi.");
				break;
			case 18:
				sprintf(testua, "%s", "B.M.: Ez dakizu non sartzen zaude, mutiko.");
				break;
			case 19:
				sprintf(testua, "%s", "A.G: Bat edo bi. Bazenekizun zure kupula oso ahula dela?");
				break;
			case 20:
				sprintf(testua, "%s", "B.M.: Bale... Arrainontzi batean geldituko naiz.");
				break;
			case 21:
				sprintf(testua, "%s", "A.G: Aukera ona hartu duzu...");
				break;
			}
			break;
	}
}