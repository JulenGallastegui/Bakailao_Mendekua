#define _CRT_SECURE_NO_WARNINGS
#include "Egunkaria.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "imagen.h"
#include "graphics.h"

#include <stdio.h>

void EgunkarikoTestuaIdatzi();

extern SDL_Color textColor;
extern int haserreNibela;

int orria = 0;
int orriMax = 10;

int EgunkariaJarri(void)
{
	int ebentu = 0;
	int irten = 0;

	if (haserreNibela == 1)
		orriMax = 12;
	else if (haserreNibela == 2 || haserreNibela == 3)
		orriMax = 14;

	SDL_Color koloreZaharra = textColor;
	
	textColor.r = 0;
	textColor.g = 0;
	textColor.b = 0;

	irudiaKargatu(".\\img\\Egunkaria.png", MAX_IMG-1);

	while (irten == 0)
	{
		pantailaGarbitu();

		ebentu = ebentuaJasoGertatuBada();
		bolumenaAldatu(ebentu);

		switch (ebentu)
		{
			case TECLA_ESCAPE:
			case TECLA_b:
				irten = 1;
				break;
			case GERTAERA_IRTEN:
				return -1;
			case TECLA_RIGHT:
			case TECLA_d:
			case SAGU_SCROLL_BEHERA:
			case SAGU_SCROLL_ESKUMA:
				if(orria != orriMax) orria+=2;
				break;
			case TECLA_LEFT:
			case TECLA_a:
			case SAGU_SCROLL_GORA:
			case SAGU_SCROLL_EZKERRA:
				if(orria != 0) orria-=2;
				break;

		}
		irudiakMarraztu();
		EgunkarikoTestuaIdatzi();
		pantailaBerriztu();
	}

	irudiaKendu(MAX_IMG - 1);
	pantailaBerriztu();

	return 1;
}

void EgunkarikoTestuaIdatzi()
{
	char zenbakia[3];
	//Ezkerreko data: 150, 140
	//Eskumako data: 460, 140
	//Ezkerreko testua: 70, 180 - 520
	//Eskumako testua: 375, 180 - 520
	//Ezkerreko zenbakia: 300, 540
	//Eskumako zenbakia: 610, 540
	switch (orria)
	{

	case 0://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 16");
		textuaIdatzi(70, 180, "Gaur, beti bezala, hondartzara joan naiz.");
		textuaIdatzi(70, 200, "Baina marmoka batek ziztau nau.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 18");
		textuaIdatzi(375, 180, "Atzo sukarra eduki nuen, eta gaur");
		textuaIdatzi(375, 200, "arraro samar sentitzen naiz.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 2://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 19");
		textuaIdatzi(70, 180, "Uste dut zoratzen ari naizela, ahotsak ");
		textuaIdatzi(70, 200, "entzuten ditut eta ez dakit nondik datozen.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 20");
		textuaIdatzi(375, 180, "Gaur hobeto nago, sukarra joan da eta ");
		textuaIdatzi(375, 200, "egia esan inoiz baino erosoago ");
		textuaIdatzi(375, 220, "sentitzen naiz.");
		textuaIdatzi(375, 240, "Bihar hondartzara bueltatuko naiz.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 4://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 21");
		textuaIdatzi(70, 180, "??????????? Zer ostia. Arrainak esaten");
		textuaIdatzi(70, 200, "dutena ulertzen dut. Zer demontre");
		textuaIdatzi(70, 220, "gertatzen ari zait. ");
		textuaIdatzi(70, 240, "Marmoka hark zerbait zuen.");
		textuaIdatzi(70, 260, "Beldurra daukat.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 22");
		textuaIdatzi(375, 180, "Aurreko urteko egunkaria irakurtzen hasi ");
		textuaIdatzi(375, 200, "naiz, eta gauza asko ez nituen ");
		textuaIdatzi(375, 220, "gogoratzen. Uste dut oroimena ari  ");
		textuaIdatzi(375, 240, "galtzen naizela.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 6://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 23");
		textuaIdatzi(70, 180, "Aurreko sarrera irakurri dut. Ez nintzen ");
		textuaIdatzi(70, 200, "hortaz gogoratzen. Egia esanda, ez dut ");
		textuaIdatzi(70, 220, "egunkarian dagoen ezer gogoratzen. ");
		textuaIdatzi(70, 240, "Ez dut gogoratzen ezer.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 24");
		textuaIdatzi(375, 180, "Ideia bat izan dut. Marmoka hori ikertu ");
		textuaIdatzi(375, 200, "egin behar dut, eta nola ez dudanez ezer ");
		textuaIdatzi(375, 220, "gogoratzen, beti idatziko dut aurkitutako ");
		textuaIdatzi(375, 240, "informazioa.");
		textuaIdatzi(375, 280, "Biharko: hondartzara joan eta ");
		textuaIdatzi(375, 300, "konprobatu arrainek ulertzen badidate.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 8://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 25");
		textuaIdatzi(70, 180, "Ez dut gogoratzen atzo egin nuena, ");
		textuaIdatzi(70, 200, "baina dirudienez oso ideia ona izan nuen. ");
		textuaIdatzi(70, 220, "Hondartzara joan naiz eta arrainekin ");
		textuaIdatzi(70, 240, "komunikatu naiteke, ulertzen naute.");
		textuaIdatzi(70, 260, "Galdetu diet ea zerbait baldin badakite ");
		textuaIdatzi(70, 280, "marmokari buruz, eta porrot egin duen ");
		textuaIdatzi(70, 300, "esperimentu bat izan dela esan didate, ");
		textuaIdatzi(70, 320, "Aquariland-ren arrainontzi nagusitik ");
		textuaIdatzi(70, 340, "ateratakoa.");
		textuaIdatzi(70, 380, "Biharko: Aquariland zer den ikertu.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 26");
		textuaIdatzi(375, 180, "Dirudienez, Aquariland arrainontzi ");
		textuaIdatzi(375, 200, "enpresa bat da, eta arrainontzi ");
		textuaIdatzi(375, 220, "nagusietako bat ondoko herrian dago. ");
		textuaIdatzi(375, 240, "Enpresa honek beste bi arrainontzi ditu. ");
		textuaIdatzi(375, 260, "Arrainei galdetuko diet ea zer dakiten ");
		textuaIdatzi(375, 280, "hauei buruz.");
		textuaIdatzi(375, 320, "Biharko: Arrainei galdetu zer dakiten ");
		textuaIdatzi(375, 340, "Aquariland-i buruz.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 10://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 27");
		textuaIdatzi(70, 180, "Arrainak esan didate arrainontziak ");
		textuaIdatzi(70, 200, "sistema hierarkiko bat dutela, lehenengo ");
		textuaIdatzi(70, 220, "arrainontziak arrain normalak ditu batez ");
		textuaIdatzi(70, 240, "ere, bigarrenak arrain handiak ditu, eta ");
		textuaIdatzi(70, 260, "nagusiak oso arrain bereziak ");
		textuaIdatzi(70, 280, "eta esperimentalak ditu.");
		textuaIdatzi(70, 300, "Arrainontzi bakoitzak bere buruzagia du, ");
		textuaIdatzi(70, 320, "bata bestea baino garrantzitsuagoa. ");
		textuaIdatzi(70, 340, "Euren kontra joan nahi badut, ");
		textuaIdatzi(70, 360, "ahulenarengandik hasi beharko ");
		textuaIdatzi(70, 380, "nintzateke.");
		textuaIdatzi(70, 420, "Biharko: arrainontzi bakoitzaren ");
		textuaIdatzi(70, 440, "informazio gehiago lortu arrainen bidez.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 1 / 28");
		textuaIdatzi(375, 180, "Arrainontzien buruzagiei buruz galdetu ");
		textuaIdatzi(375, 200, "diet, lehenengo biak gizakiak dira, ");
		textuaIdatzi(375, 220, "baina azkena, bakailao mutante gaizto ");
		textuaIdatzi(375, 240, "bat da, BakailaoMan izenekoa.");
		textuaIdatzi(375, 260, "BakailaoMan arrainekin esperimentatzen ");
		textuaIdatzi(375, 280, "du arrain esperimental gehiago lortzeko, ");
		textuaIdatzi(375, 300, "horrela arrain arraza perfektua lortuz ");
		textuaIdatzi(375, 320, "eta arrainontzi ederrena lortuz, ");
		textuaIdatzi(375, 340, "diru mordoak irabaziz.");
		textuaIdatzi(375, 360, "Adostu dut arrainontziekin akabatuko ");
		textuaIdatzi(375, 380, "dudala, BakailaoMan-en ");
		textuaIdatzi(375, 400, "esperimentazioari bukaera emateko.");
		textuaIdatzi(375, 440, "Biharko: lehenengo arrainontzira ");
		textuaIdatzi(375, 460, "joan eta arrainak askatuko ditut.");
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 12://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 29");
		textuaIdatzi(70, 180, "Lehenengo arrainontziko arrainak askatu");
		textuaIdatzi(70, 200, "ditut. Bertako buruzagia Elon Crab");
		textuaIdatzi(70, 220, "deitzen zen. Crab-ek nahiko erraz");
		textuaIdatzi(70, 240, "eman du amore. Arrainontzian botila bat");
		textuaIdatzi(70, 260, "aurkidu dut, gehiago sendatzeko balio");
		textuaIdatzi(70, 280, "duena. Gainera kutxa batean bizitza ");
		textuaIdatzi(70, 300, "puntu gehiago lortu egin ditut ur espezial");
		textuaIdatzi(70, 320, "bat zegoelako. Horain gai sentitzen naiz");
		textuaIdatzi(70, 340, "bigarrena askatzeko.");
		textuaIdatzi(70, 360, "Buruzagiari ez zitzaion inporta arrainen");
		textuaIdatzi(70, 380, "bizitza. Horrek haserretu nau.");
		textuaIdatzi(70, 420, "Biharko: bigarren arrainontzira joan");
		textuaIdatzi(70, 440, "eta arrainak askatu.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);
		if (haserreNibela == 2)
		{
			textuaIdatzi(460, 140, "2000 / 1 / 30");
			textuaIdatzi(375, 180, "Bigarren arrainotzia askatu dut.");
			textuaIdatzi(375, 200, "Buruzagia Jeff Besuga deitzen zen.");
			textuaIdatzi(375, 220, "Jeff-ri irabaztea pixkat gehiago kostatu");
			textuaIdatzi(375, 240, "kostatu zait, baina arrainak askatzea");
			textuaIdatzi(375, 260, "lortu dut.");
			textuaIdatzi(375, 280, "Arrainontzi honetan ezkutu bat aurkitu");
			textuaIdatzi(375, 300, "dut. Gainera kontraerasoa egiterakoan,");
			textuaIdatzi(375, 320, "egin behar zidaten min guztia");
			textuaIdatzi(375, 340, "bueltatzeko gai bihurtu naiz.");
			textuaIdatzi(375, 360, "Gero eta hasarreago nago.");
			textuaIdatzi(375, 380, "Esperimentu hauek bukatu behar ditut");
			textuaIdatzi(375, 400, "bihar.");
			textuaIdatzi(375, 440, "Biharko: Bakailaoman-en arraiontziara");
			textuaIdatzi(375, 460, "joan eta bertako arrain guztiak askatu.");
		}
		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		break;
	case 14://aIdatzi(                                                a");
		textuaIdatzi(150, 140, "2000 / 1 / 31");
		textuaIdatzi(70, 180, "Lortu dut! Bakailaoman esperimentuekin");
		textuaIdatzi(70, 200, "gelditu da, oso borroka zaila baten ");
		textuaIdatzi(70, 220, "ondoren. Momentu batez birritan borrokatu");
		textuaIdatzi(70, 240, "behar genuela uste nuen, baina");
		textuaIdatzi(70, 260, "zortea izan dut eta ez da beharrezkoa");
		textuaIdatzi(70, 280, "izan. ");
		textuaIdatzi(70, 300, "Aquariland suntsitu dut, eta arrainekin");
		textuaIdatzi(70, 320, "esperimentuak bukatu dira.");
		textuaIdatzi(70, 340, "Arrain guztiei jakinarazi behar diet hau,");
		textuaIdatzi(70, 360, "oso berri garrantsitzua da eta.");
		textuaIdatzi(70, 400, "Biharko: itsasora bueltatu, ahalik eta");
		textuaIdatzi(70, 420, "arrain gehien bildu, eta berri hau");
		textuaIdatzi(70, 440, "helarazi itsaso guztira.");
		sprintf(zenbakia, "%d", orria + 1);
		textuaIdatzi(300, 540, zenbakia);

		sprintf(zenbakia, "%d", orria + 2);
		textuaIdatzi(610, 540, zenbakia);
		textuaIdatzi(460, 140, "2000 / 2 / 1");
		textuaIdatzi(375, 180, "Arrainei esan diet gertatutako guztia");
		textuaIdatzi(375, 200, "eta denek ezkerrak eman didate.");
		textuaIdatzi(375, 220, "Uste dut pixkat pasatu naizela arrainak");
		textuaIdatzi(375, 240, "biltzen, ziur asko eleberrietan agertuko");
		textuaIdatzi(375, 260, "da gaur zonaldeko itsas izaki gehienak");
		textuaIdatzi(375, 280, "ondartzan bildu direlako: marrazoak,");
		textuaIdatzi(375, 300, "baleak eta guzti, era  pazifiko batean.");
		textuaIdatzi(375, 320, "Lortutako gaitasun guztiei esker, erdi");
		textuaIdatzi(375, 340, "arrain erdi gizaki bihurtu naiz, eta");
		textuaIdatzi(375, 360, "gizakiak baino askoz denbora gehiago");
		textuaIdatzi(375, 380, "egon ahal naiz ur azpian. Agian ur azpian");
		textuaIdatzi(375, 400, "arnasteko gai bihurtzen naiz, nor daki...");
	default:
		break;
	}
}

/*

		case X://aIdatzi(                                                a");
			textuaIdatzi(150, 140, "2000 / 1 / XX");
			textuaIdatzi(70, 180, "");
			sprintf(zenbakia, "%d", orria + 1);
			textuaIdatzi(300, 540, zenbakia);
			textuaIdatzi(460, 140, "2000 / 1 / XX");
			textuaIdatzi(375, 180, "");
			sprintf(zenbakia, "%d", orria + 2);
			textuaIdatzi(610, 540, zenbakia);
			break;
			
*/