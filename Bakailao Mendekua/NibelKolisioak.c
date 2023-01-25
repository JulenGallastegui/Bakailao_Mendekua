#include "NibelKolisioak.h"
/* Kolisioen koordenatuak (Irudi baten koordenatuak)
(0,0)
 +----------->·X (1,0)
 |
 |
 |
 |
 |
\|/
 '
 ·Y (0,1)     ·  (1,1)
*/
int KolisioaJaso(int akuarioa, int zein, int(*kolisioa)[700])
{
	int i, j, defektuz = 0;

	if (akuarioa == -1 || (akuarioa == 0 && (zein == 0 || zein == 2)))
		defektuz = 1;

	for (i = 0; i < 700; i++) //Arraya 0-ra hasieratu
	{
		for (j = 0; j < 700; j++)
		{
			
			kolisioa[i][j] = defektuz;
		}
	}
	kolisioa[0][0] = 0;
	switch (akuarioa)
	{
		case -1:
#pragma region 
			for (i = 199; i < 700; i++) //Pasalekua liberatu
			{
				for (j = 381; j <= 509; j++)
				{
					kolisioa[i][j] = 0;
				}
			}
			kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
			return 1;
#pragma endregion menua
		break;
		case 0:
			switch (zein)
			{
				case 0:
#pragma region 
					for (i = 0; i < 700; i++) //Lurra liberatu
					{
						for (j = 317; j <= 628; j++)
						{
							kolisioa[i][j] = 0;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion etxea
				case 1:
#pragma region 
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 310; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 349; i < 518; i++) //Mahaia
					{
						for (j = 311; j <= 420; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 535; i < 699; i++) //Ohea
					{
						for (j = 311; j <= 530; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion etxeBarrua
				case 2:
#pragma region 
					for (i = 0; i < 700; i++) //Lurra libratu
					{
						for (j = 317; j <= 628; j++)
						{
							kolisioa[i][j] = 0;
						}
					}
					kolisioa[0][0] = 0; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion geltokiruntz

			}
		break;
		case 1: //Akuario 1
			switch (zein)
			{
				case -1:
#pragma region 
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 375; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion akuarioSarrera1
				case 0:
#pragma region 
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 500; j <= 530; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion anden1
				case 1:
#pragma region 
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 215; i < 500; i++) //Mostradorea
					{
						for (j = 256; j <= 400; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 33; i <= 103; i++) //Ezker landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 66; i <= 70; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 75; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 55; i <= 81; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 602; i <= 671; i++) //Eskuin landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 634; i <= 639; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 629; i <= 644; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 624; i <= 649; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion sarrera1
				case 2: 
#pragma region
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 39; i <= 108; i++) //Goi ezker landarea
					{
						for (j = 256; j <= 316; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 607; i <= 677; i++) //Goi eskuin landarea
					{
						for (j = 256; j <= 316; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 33; i <= 103; i++) //behe ezker landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 66; i <= 70; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 75; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 55; i <= 81; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 602; i <= 671; i++) //behe eskuin landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 634; i <= 639; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 629; i <= 644; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 624; i <= 649; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion pasaleku1_1
				case 3:
#pragma region
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 570; i < 678; i++) //kutxa
					{
						for (j = 255; j <= 306; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 33; i <= 103; i++) //Ezker landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 66; i <= 70; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 75; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 55; i <= 81; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 602; i <= 671; i++) //Eskuin landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 634; i <= 639; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 629; i <= 644; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 624; i <= 649; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion goikoBorroka
				case 4:
#pragma region 
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 38; i <= 108; i++) //Ezkerreko landarea
					{
						for (j = 630; j < 700; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 71; i <= 75; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 65; i <= 80; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 86; i++)
					{
						for (j = 624; j <= 628; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 313; i <= 383; i++) //Erdiko landarea
					{
						for (j = 630; j < 700; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 346; i <= 350; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 340; i <= 355; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 335; i <= 361; i++)
					{
						for (j = 624; j <= 628; j++)
						{
							kolisioa[i][j] = 1;
						}
					}

					for (i = 583; i <= 653; i++) //Eskuineko landarea
					{
						for (j = 630; j < 700; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 616; i <= 620; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 610; i <= 625; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 605; i <= 631; i++)
					{
						for (j = 624; j <= 628; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion pasaleku1_2
				case 5:
#pragma region
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 33; i <= 103; i++) //Ezkerreko landarea
					{
						for (j = 629; j < 700; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 66; i <= 70; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 75; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 55; i <= 81; i++)
					{
						for (j = 624; j <= 628; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 602; i <= 672; i++) //Eskuineko landarea
					{
						for (j = 629; j < 700; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 635; i <= 639; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 629; i <= 644; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 624; i <= 650; i++)
					{
						for (j = 624; j <= 628; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion pasalekua1_3 
				case 6:
#pragma region
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i =578; i < 674; i++) //Kutxa
					{
						for (j = 255; j <= 277; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 33; i <= 103; i++) //Ezker landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 66; i <= 70; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 60; i <= 75; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 55; i <= 81; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 602; i <= 671; i++) //Eskuin landarea
					{
						for (j = 630; j <= 699; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 634; i <= 639; i++)
					{
						for (j = 613; j <= 617; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 629; i <= 644; i++)
					{
						for (j = 618; j <= 623; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 624; i <= 649; i++)
					{
						for (j = 624; j <= 629; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion BehekoBorroka
				case 7:
#pragma region
					for (i = 0; i < 700; i++) //Goiko pareta
					{
						for (j = 0; j <= 255; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					for (i = 487; i < 700; i++) //Kutxak
					{
						for (j = 255; j <= 358; j++)
						{
							kolisioa[i][j] = 1;
						}
					}
					kolisioa[0][0] = 1; //0,0 beti 1 izan behar da
					return 1;
#pragma endregion Buruzagi
				default: //Mapa zenbakia gaizki dago
					return 0;
			}
		break;
		case 2: //Akuario 2
			switch (zein)
			{
				case 0:
					return 0;
				default:
					return 0;
			}
		break;
		case 3: //Akuario 3
			switch (zein)
			{
			case 0:
				return 1;
			default:
				return 0;
			}
		break;
		default:
			return 0;
	}
}

int GeziakJaso(int akuario, int nibela, int(*geziak)[700])
{
	int i, j;

	for (i = 0; i < 700; i++) //Arraya 0-ra hasieratu
	{
		for (j = 0; j < 700; j++)
		{
			geziak[i][j] = 0;
		}
	}
	switch (akuario)
	{
		case -1:
			//Jokua hasi
			for (i = 589; i < 700; i++)
			{
				for (j = 415; j <= 490; j++)
				{
					geziak[i][j] = 1;
				}
			}
			//Jokua itxi
			for (i = 199; i < 274; i++)
			{
				for (j = 381; j <= 518; j++)
				{
					geziak[i][j] = 2;
				}
			}
			break;
		case 0:
			switch (nibela)
			{
				case -1:
					//eskumako gezia   i==X  j==Y
					for (i = 589; i < 700; i++)
					{
						for (j = 415; j <= 490; j++)
						{
							geziak[i][j] = 1;
						}
					}
					return 1;
				case 0:
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 106; i++)
					{
						for (j = 434; j <= 510; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 592; i < 700; i++)
					{
						for (j = 434; j <= 509; j++)
						{
							geziak[i][j] = 2;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 311; i < 388; i++)
					{
						for (j = 257; j <= 366; j++)
						{
							geziak[i][j] = 3;
						}
					}
					return 1;
				case 1:
					//beheko gezia   i==X  j==Y
					for (i = 109; i < 185; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 1;
						}
					}
					break;
				case 2:
					//ezkerreko gezia   i==X  j==Y
					for (i = 59; i < 167; i++)
					{
						for (j = 415; j <= 490; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 521; i < 630; i++)
					{
						for (j = 417; j <= 493; j++)
						{
							geziak[i][j] = 2;
						}
					}


					break;
				case 3:
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 116; i++)
					{
						for (j = 596; j <= 652; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 394; i < 447; i++)
					{
						for (j = 541; j <= 650; j++)
						{
							geziak[i][j] = 2;
						}
					}

					break;
				default:
					break;
			}
			break;
		case 1:
			switch (nibela)
			{
			case -1: //Anden

				//eskumako gezia   i==X  j==Y
				for (i = 589; i < 700; i++)
				{
					for (j = 599; j <= 655; j++)
					{
						geziak[i][j] = 1;
					}
				}

				//goiko gezia   i==X  j==Y
				for (i = 394; i < 447; i++)
				{
					for (j = 541; j <= 650; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 0: //akuarioaren sarrera

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 122; i++)
				{
					for (j = 476; j <= 554; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//goiko gezia   i==X  j==Y
				for (i = 552; i < 629; i++)
				{
					for (j = 401; j <= 509; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 1: //sarrera

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 110; i++)
				{
					for (j = 394; j <= 470; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 590; i < 700; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 2: //Pasalekua 1

				//Goiko gezia   i==X  j==Y
				for (i = 310; i <= 387; i++)
				{
					for (j = 254; j <= 365; j++)
					{
						geziak[i][j] = 1;
					}
				}

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 110; i++)
				{
					for (j = 394; j <= 470; j++)
					{
						geziak[i][j] = 2;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 590; i < 700; i++)
				{
					for (j = 412; j <= 460; j++)
					{
						geziak[i][j] = 3;
					}
				}

				return 1;
			case 3: //Pasalekua 4

				//beheko gezia   i==X  j==Y
				for (i = 318; i <= 394; i++)
				{
					for (j = 590; j <= 700; j++)
					{
						geziak[i][j] = 1;
					}
				}
				return 1;

			case 4: //Pasalekua 2

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 112; i++)
				{
					for (j = 400; j <= 474; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 586; i < 700; i++)
				{
					for (j = 400; j <= 473; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;


			case 5: //Pasalekua 3

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 107; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 591; i < 700; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 2;
					}
				}
				//Beheko gezia   i==X  j==Y
				for (i = 312; i < 387; i++)
				{
					for (j = 591; j < 700; j++)
					{
						geziak[i][j] = 3;
					}
				}
				return 1;
			case 6: //Pasalekua 5

				//goiko gezia   i==X  j==Y
				for (i = 311; i <= 389; i++)
				{
					for (j = 256; j <= 367; j++)
					{
						geziak[i][j] = 1;
					}
				}
				return 1;
			case 7: //buruzagi

				//ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 139; i++)
				{
					for (j = 411; j <= 487; j++)
					{
						geziak[i][j] = 1;
					}
				}
				return 1;
			default:
				return 0;
			}
			break;
		case 2:
			switch (nibela)
			{
			case -1: //Anden

				//eskumako gezia   i==X  j==Y
				for (i = 589; i < 700; i++)
				{
					for (j = 599; j <= 655; j++)
					{
						geziak[i][j] = 1;
					}
				}

				//goiko gezia   i==X  j==Y
				for (i = 394; i < 447; i++)
				{
					for (j = 541; j <= 650; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 0: //akuarioaren sarrera

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 122; i++)
				{
					for (j = 476; j <= 554; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//goiko gezia   i==X  j==Y
				for (i = 552; i < 629; i++)
				{
					for (j = 401; j <= 509; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 1: //sarrera

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 110; i++)
				{
					for (j = 394; j <= 470; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 590; i < 700; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 2;
					}
				}

				return 1;
			case 2: //Pasalekua 1

				//Goiko gezia   i==X  j==Y
				for (i = 310; i <= 387; i++)
				{
					for (j = 254; j <= 365; j++)
					{
						geziak[i][j] = 1;
					}
				}

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 110; i++)
				{
					for (j = 394; j <= 470; j++)
					{
						geziak[i][j] = 2;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 590; i < 700; i++)
				{
					for (j = 412; j <= 460; j++)
					{
						geziak[i][j] = 3;
					}
				}

				return 1;
			case 3: //Pasalekua 2

				//beheko gezia   i==X  j==Y
				for (i = 318; i <= 394; i++)
				{
					for (j = 590; j <= 700; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//eskumako gezia   i==X  j==Y
				for (i = 592; i <= 700; i++)
				{
					for (j = 401; j <= 476; j++)
					{
						geziak[i][j] = 2;
					}
				}
				return 1;

			case 4: //Pasalekua 4

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 112; i++)
				{
					for (j = 400; j <= 474; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//goiko gezia   i==X  j==Y
				for (i = 310; i <= 387; i++)
				{
					for (j = 254; j <= 365; j++)
					{
						geziak[i][j] = 2;
					}
				}
				//Beheko gezia   i==X  j==Y
				for (i = 310; i <= 387; i++)
				{
					for (j = 589; j <= 700; j++)
					{
						geziak[i][j] = 3;
					}
				}

				return 1;

			case 5: //Pasalekua 5

				//Ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 107; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 591; i < 700; i++)
				{
					for (j = 398; j <= 473; j++)
					{
						geziak[i][j] = 2;
					}
				}
				//Beheko gezia   i==X  j==Y
				for (i = 312; i < 387; i++)
				{
					for (j = 591; j < 700; j++)
					{
						geziak[i][j] = 3;
					}
				}
				return 1;
			case 6: //Pasalekua 3

				//goiko gezia   i==X  j==Y
				for (i = 311; i <= 389; i++)
				{
					for (j = 256; j <= 367; j++)
					{
						geziak[i][j] = 1;
					}
				}
				return 1;
			case 7: //Pasaleku 6

				//ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 111; i++)
				{
					for (j = 387; j <= 466; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Eskumako gezia   i==X  j==Y
				for (i = 591; i < 700; i++)
				{
					for (j = 393; j <= 470; j++)
					{
						geziak[i][j] = 2;
					}
				}
				return 1;
			case 9: //Pasaleku 7

				//ezkerreko gezia   i==X  j==Y
				for (i = 0; i <= 139; i++)
				{
					for (j = 411; j <= 487; j++)
					{
						geziak[i][j] = 1;
					}
				}
				//Beheko gezia   i==X  j==Y
				for (i = 312; i < 387; i++)
				{
					for (j = 591; j < 700; j++)
					{
						geziak[i][j] = 2;
					}
				}
				return 1;
			case 10: //buruzagia

				//goiko gezia   i==X  j==Y
				for (i = 311; i <= 389; i++)
				{
					for (j = 256; j <= 367; j++)
					{
						geziak[i][j] = 1;
					}
				}
				return 1;
			default:
				return 0;
			}
			break;
		case 3:
			switch (nibela)
			{
				case -1: //Anden
					//eskumako gezia   i==X  j==Y
					for (i = 589; i < 700; i++)
					{
						for (j = 599; j <= 655; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 394; i < 447; i++)
					{
						for (j = 541; j <= 650; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 0: //Akuarioaren sarrera
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 119; i++)
					{
						for (j = 476; j <= 553; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 552; i < 629; i++)
					{
						for (j = 400; j <= 509; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 1: //sarrera
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 108; i++)
					{
						for (j = 398; j <= 473; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 590; i < 700; i++)
					{
						for (j = 294; j <= 469; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 2: //Pasaleku1
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 108; i++)
					{
						for (j = 409; j <= 486; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 256; j <= 366; j++)
						{
							geziak[i][j] = 2;
						}
					}
					//beheko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 592; j <= 700; j++)
						{
							geziak[i][j] = 3;
						}
					}
					return 1;
				case 3: //Pasaleku3
					//goiko gezia   i==X  j==Y
					for (i = 311; i < 388; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 592; i < 700; i++)
					{
						for (j = 416; j <= 491; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 4: //Pasaleku4
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 107; i++)
					{
						for (j = 385; j <= 462; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 590; i < 700; i++)
					{
						for (j = 379; j <= 456; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 5: //Pasaleku5
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 107; i++)
					{
						for (j = 410; j <= 485; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//eskumako gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 6: //Pasaleku6
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 107; i++)
					{
						for (j = 385; j <= 462; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//beheko gezia   i==X  j==Y
					for (i = 314; i < 391; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 7: //Pasaleku7
					//eskumako gezia   i==X  j==Y
					for (i = 591; i < 700; i++)
					{
						for (j = 416; j <= 491; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//beheko gezia   i==X  j==Y
					for (i = 316; i < 391; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 2;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 3;
						}
					}
					return 1;
				case 8: //Pasaleku8
					//goiko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 1;
						}
					}
					return 1;
				case 9: //Pasaleku9
					//eskumako gezia   i==X  j==Y
					for (i = 591; i < 700; i++)
					{
						for (j = 416; j <= 491; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//beheko gezia   i==X  j==Y
					for (i = 316; i < 391; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 2;
						}
					}
					//goiko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 3;
						}
					}
					return 1;
				case 10: //Pasaleku10
					//beheko gezia   i==X  j==Y
					for (i = 314; i < 391; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 1;
						}
					}
					return 1;
				case 11: //Pasaleku11
					//ezkerreko gezia   i==X  j==Y
					for (i = 0; i < 107; i++)
					{
						for (j = 385; j <= 462; j++)
						{
							geziak[i][j] = 1;
						}
					}
					//beheko gezia   i==X  j==Y
					for (i = 314; i < 391; i++)
					{
						for (j = 591; j <= 700; j++)
						{
							geziak[i][j] = 2;
						}
					}
					return 1;
				case 12: //buruzagia
					//goiko gezia   i==X  j==Y
					for (i = 312; i < 387; i++)
					{
						for (j = 257; j <= 365; j++)
						{
							geziak[i][j] = 1;
						}
					}
					return 1;
				case 13: //Pasaleku2
					//beheko gezia   i==X  j==Y
					for (i = 311; i < 388; i++)
					{
						for (j = 590; j <= 700; j++)
						{
							geziak[i][j] = 1;
						}
					}
					return 1;
				default:
					break;
			}
			break;
		default:
			break;
	}
	return 0;
}