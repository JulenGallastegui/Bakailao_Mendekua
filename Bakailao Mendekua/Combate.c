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

typedef struct S_ArrainGizonBorroka
{
    int bizitza;
    int bizitzaMax;
    int indarra;
    int sendaketa;
    int kontSen;
    int kontKon;
    int uraErabilita;
    int barraErabilita;
    int protekzioaErabilita;
} ArrainGizonBorroka;

typedef struct S_EtsaiaBorroka
{
    int bizitza;
    int bizitzaMax;
    int indarra;
    int sendaketa;
    int probabilitateaKontra;
    int probabilitateaSendatu;
    int kontSen;
    int kontKon;
} EtsaiaBorroka;


void atk();
int random_number(int min_num, int max_num);
void cur();
void kon();
void ura();
void barra();
void protekzioa();
int MatoiarenAukerak(int kolpeaJasoDu);
void BorrokaBukatu();
void pertsonaiarenAukerakArratoia();
void AnimatuArrainGizon(int zein);
void AnimatuEtsaia(int zein);
void EtsaiaSortu(int buruzagiaDa);

//Jolasenak
int irten = 0;
int ebentu;
extern GURE_GAUZAK gureGauzak;
POSIZIOA pos;
extern SDL_Color textColor;

//Arrain gizon
ArrainGizonBorroka arrainGizon;
char vidaPersonajestr[7];
int objektuak;
extern int haserreNibela;
int bizitzaExtra = 0;
int indarExtra = 0;
int sendaketaExtra = 0;
int kontraerasoTotala = 0;
int botilaDu = 0;
int barraDu = 0;
int ezkutuaDu = 0;

//Etsaia
EtsaiaBorroka etsaia;
char vidaEnemigastr[7];
extern int akuarioa;

int borrokaHasi(int buruzagiaDa)
{
    irten = 0;
    //--------------------------
    arrainGizon.bizitzaMax = 100 + bizitzaExtra;
    arrainGizon.bizitza = arrainGizon.bizitzaMax;
    arrainGizon.indarra = 20 + indarExtra;
    arrainGizon.sendaketa = 10 + sendaketaExtra;
    arrainGizon.kontSen = 0;
    arrainGizon.kontKon = 0;
    arrainGizon.uraErabilita = 0;
    arrainGizon.barraErabilita = 0;
    arrainGizon.protekzioaErabilita = 0;

    //--------------------------
    if (buruzagiaDa == 0)
    {
        if (!kargatuMusika(".\\sound\\CombateMaton.wav"))
            fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
    }
    else
    {
        if (!kargatuMusika(".\\sound\\CombateBoss.wav"))
            fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
    }

    //Arrain Gizonen irudia jarri
    switch (haserreNibela)
    {
        case 0:
            irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Normal\\Arrain Gizon behera.png", 1);
            break;
        case 1:
            irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Haserre\\Arrain Gizon behera.png", 1);
            break;
        case 2:
            irudiaKargatu(".\\img\\Pertsonaiak\\ArrainGizon\\Oso haserre\\Arrain Gizon behera.png", 1);
            break;
    }

    EtsaiaSortu(buruzagiaDa);

    irudiaKargatu(".\\img\\Borroka\\Borroka.png", 2);

    irudiaMugitu(1, 130, 175);

    while (!irten)
    {
        pantailaGarbitu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == GERTAERA_IRTEN)
            return -1;

        bolumenaAldatu(ebentu);

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pertsonaiarenAukerakArratoia();
        }
        irudiakMarraztu();

        textColor.r = textColor.g = textColor.b = 0;
        if (objektuak == 0)
        {
            if (arrainGizon.kontKon == 1)
            {
                textuaIdatzi(320, 670, "Ezin da erabili");
            }
            if (arrainGizon.kontSen == 1)
            {
                textuaIdatzi(180, 670, "Ezin da erabili");
            }
        }
        else
        {
            if(arrainGizon.uraErabilita == 1 || botilaDu == 0)
                textuaIdatzi(40, 670, "Ezin da erabili");
            if(arrainGizon.barraErabilita == 1 || barraDu == 0)
                textuaIdatzi(180, 670, "Ezin da erabili");
            if (arrainGizon.protekzioaErabilita == 1 || ezkutuaDu == 0)
                textuaIdatzi(320, 670, "Ezin da erabili");
        }
        textColor.r = textColor.g = textColor.b = 255;

        sprintf(vidaPersonajestr, "%d", arrainGizon.bizitza);
        if (arrainGizon.bizitza < 100)
            vidaPersonajestr[2] = ' ';
        else if (arrainGizon.bizitza < 10)
            vidaPersonajestr[1] = ' ';
        vidaPersonajestr[3] = ' ';
        vidaPersonajestr[4] = 'H';
        vidaPersonajestr[5] = 'P';
        vidaPersonajestr[6] = '\0';
        textuaIdatzi(220, 430, vidaPersonajestr);

        sprintf(vidaEnemigastr, "%d", etsaia.bizitza);
        if (etsaia.bizitza < 100)
            vidaEnemigastr[2] = ' ';
        else if (etsaia.bizitza < 10)
            vidaEnemigastr[1] = ' ';
        vidaEnemigastr[3] = ' ';
        vidaEnemigastr[4] = 'H';
        vidaEnemigastr[5] = 'P';
        vidaEnemigastr[6] = '\0';
        textuaIdatzi(475, 430, vidaEnemigastr);

        if (arrainGizon.bizitza <= 0)
        {
            irudiaKendu(1);
            BorrokaBukatu();
            return -2;
        }
        else if (etsaia.bizitza <= 0)
        {
            BorrokaBukatu();

        }
        pantailaBerriztu();
    }
    return 1;
}

void BorrokaBukatu()
{
    pantailaGarbitu();
    irudiaKendu(1);
    irudiaKendu(2);
    irudiaKendu(3);
    irudiaKendu(4);
    irudiakMarraztu();
    pantailaBerriztu();

    irten = 1;
}

void itm()
{
    if (objektuak == 0)
    {
        irudiaKargatu(".\\img\\Borroka\\Borroka2.png", 4);
        irudiaMugitu(4, 0, 0);
        objektuak = 1;
    }
    else
    {
        irudiaKendu(4);
        objektuak = 0;
    }
}

void atk()
{
    int seg = 0;
    int kolpeaJasoDu = 0;

    etsaia.bizitza = etsaia.bizitza - arrainGizon.indarra;
    kolpeaJasoDu = 1;
    AnimatuArrainGizon(1);

    arrainGizon.kontSen = 0;
    arrainGizon.kontKon = 0;
    if(etsaia.bizitza > 0)
        MatoiarenAukerak(kolpeaJasoDu);

}

void protekzioa()
{
    int kolpeaJasoDu = 0;
    if (arrainGizon.protekzioaErabilita == 0 && ezkutuaDu == 1)
    {
        arrainGizon.protekzioaErabilita = 1;
        AnimatuArrainGizon(6);
        MatoiarenAukerak(kolpeaJasoDu);
    }
    else
    {
        printf("Gabe gelditu zara\n");
    }
    irudiaKendu(4);
}

void ura()
{
    int kolpeaJasoDu = 0;
    if (arrainGizon.uraErabilita == 0 && botilaDu == 1)
    {
        arrainGizon.bizitza = arrainGizon.bizitza + 50;
        arrainGizon.uraErabilita = 1;
        if (arrainGizon.bizitza > arrainGizon.bizitzaMax)
        {
            arrainGizon.bizitza = arrainGizon.bizitzaMax;
        }
        AnimatuArrainGizon(4);
        MatoiarenAukerak(kolpeaJasoDu);
    }
    else
    {
        printf("Gabe gelditu zara\n");
    }
    irudiaKendu(4);
}

void barra()
{
    int kolpeaJasoDu = 0;
    if (arrainGizon.barraErabilita == 0 && barraDu == 1)
    {
        etsaia.bizitza = etsaia.bizitza - arrainGizon.indarra * 2;
        AnimatuArrainGizon(5);
        if(etsaia.bizitza > 0)
            MatoiarenAukerak(kolpeaJasoDu);
        arrainGizon.barraErabilita = 1;
    }
    else
    {
        printf("Gabe gelditu zara\n");
    }
    irudiaKendu(4);
}

void cur()
{
    int kolpeaJasoDu = 0;
    if (arrainGizon.kontSen != 1)
    {
        if (arrainGizon.bizitza < arrainGizon.bizitzaMax)
        {
            arrainGizon.bizitza = arrainGizon.bizitza + arrainGizon.sendaketa;
            arrainGizon.kontSen = 1;
            if (arrainGizon.bizitza >= arrainGizon.bizitzaMax)
            {
                arrainGizon.bizitza = arrainGizon.bizitzaMax;
            }
            AnimatuArrainGizon(2);
        }
        arrainGizon.kontKon = 0;
        MatoiarenAukerak(kolpeaJasoDu);
    }
    else
    {
        printf("Ezin dezu bi aldiz eman\n");
    }

}

void kon()
{
    int kolpeaJasoDu = 0;

    if (arrainGizon.kontKon != 1)
    {
        if (MatoiarenAukerak(kolpeaJasoDu) == 1)
        {
            arrainGizon.bizitza = arrainGizon.bizitza + etsaia.indarra;
            if(kontraerasoTotala == 0)
                etsaia.bizitza = etsaia.bizitza - (etsaia.indarra / 2);
            else
                etsaia.bizitza = etsaia.bizitza - etsaia.indarra;

            arrainGizon.kontKon = 1;
            AnimatuArrainGizon(3);
        }

        arrainGizon.kontSen = 0;
    }
    else
    {
        printf("ezin dezu bi aldiz eman\n");
    }
}

int MatoiarenAukerak(int kolpeaJasoDu)
{
    int zenbakia = random_number(0, 100);
    printf("jasota: %d ", kolpeaJasoDu);
    printf("%d: ", zenbakia);
    int kolpeaEmandu = 0;


    if (kolpeaJasoDu == 1 && etsaia.kontKon == 0 && etsaia.probabilitateaKontra >= zenbakia) //Kontraatakea
    {
        printf("Contra\n");
        AnimatuEtsaia(3);
        etsaia.bizitza = etsaia.bizitza + arrainGizon.indarra;
        if (arrainGizon.protekzioaErabilita == 0 || arrainGizon.protekzioaErabilita >= 3)
            arrainGizon.bizitza = arrainGizon.bizitza - (etsaia.indarra / 2);
        else
        {
            arrainGizon.bizitza = arrainGizon.bizitza - (etsaia.indarra / 4);
            arrainGizon.protekzioaErabilita++;
        }

        etsaia.kontKon = 1;
        etsaia.kontSen = 0;
        kolpeaEmandu = 1;
    }
    else if (etsaia.probabilitateaSendatu >= zenbakia && etsaia.kontSen == 0 && etsaia.bizitza < etsaia.bizitzaMax) //Curar
    {
        printf("Curar\n");
        AnimatuEtsaia(2);
        etsaia.bizitza = etsaia.bizitza + etsaia.sendaketa;
        if (etsaia.bizitza > etsaia.bizitzaMax)
        {
            etsaia.bizitza = etsaia.bizitzaMax;
        }
        etsaia.kontSen = 1;
        etsaia.kontKon = 0;
        kolpeaEmandu = 0;
    }
    else //Atakatu
    {
        printf("Atacar\n");
        AnimatuEtsaia(1);

        if (arrainGizon.protekzioaErabilita == 0 || arrainGizon.protekzioaErabilita >= 3)
            arrainGizon.bizitza = arrainGizon.bizitza - etsaia.indarra;
        else
        {
            arrainGizon.bizitza = arrainGizon.bizitza - (etsaia.indarra / 2);
            arrainGizon.protekzioaErabilita++;
        }

        etsaia.kontSen = 0;
        etsaia.kontKon = 0;
        kolpeaEmandu = 1;
    }

    return kolpeaEmandu;
}

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    }
    else
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(SDL_GetTicks());
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void pertsonaiarenAukerakArratoia()
{
    pos = saguarenPosizioa();
    if (pos.x > 13 && pos.x < 148 && pos.y > 561 && pos.y < 690)
    {
        if (objektuak == 0)
        {
            atk();

        }
        else
        {
            ura();
            objektuak = 0;
        }
    }
    else if (pos.x > 154 && pos.x < 289 && pos.y > 561 && pos.y < 690)
    {
        if (objektuak == 0)
        {
            cur();
        }
        else
        {
            barra();
            objektuak = 0;
        }
    }
    else if (pos.x > 294 && pos.x < 429 && pos.y > 561 && pos.y < 690)
    {
        if (objektuak == 0)
        {
            kon();
        }
        else
        {
            protekzioa();
            objektuak = 0;
        }
    }
    else if (pos.x > 552 && pos.x < 687 && pos.y > 561 && pos.y < 690)
    {
        itm();
    }
}

void AnimatuArrainGizon(int zein)
{
    int animazioaBukatu = 0;
    int kont = 0;
    unsigned int hurrengoMugimendua = 0, mugimenduDenbora = 30;

    while (animazioaBukatu == 0)
    {
        ebentu = ebentuaJasoGertatuBada();

        pantailaGarbitu();
        if (hurrengoMugimendua < SDL_GetTicks())
        {
            switch (zein)
            {
            case 1:
                if (kont <= 6)
                    irudiaMugitu(1, 130 + 5 * kont, 175);
                else
                    irudiaMugitu(1, 160 - 5 * (kont - 6), 175);
                if(kont == 12)
                    animazioaBukatu = 1;
                break;
            case 2:
                if (kont <= 6)
                    irudiaMugitu(1, 130, 175 - 5 * kont);
                else
                    irudiaMugitu(1, 130, 145 + 5 * (kont - 6));
                if (kont == 12)
                    animazioaBukatu = 1;
                break;
            case 3:
                if (kont <= 6)
                    irudiaMugitu(1, 130 - 5 * kont, 175);
                else if (kont <= 12)
                    irudiaMugitu(1, 100 + 5 * (kont - 6), 175);
                else if (kont <= 18)
                    irudiaMugitu(1, 130 + 5 * (kont - 12), 175);
                else if (kont <= 24)
                    irudiaMugitu(1, 160 - 5 * (kont - 18), 175);

                if(kont == 24)
                    animazioaBukatu = 1;
                break;
            case 4:

                if (kont <= 6)
                    irudiaMugitu(1, 130, 175 - 5 * kont);
                else if (kont <= 12)
                    irudiaMugitu(1, 130, 145 + 5 * (kont - 6));
                else if (kont <= 18)
                    irudiaMugitu(1, 130, 175 - 5 * (kont - 12));
                else if (kont <= 24)
                    irudiaMugitu(1, 130, 145 + 5 * (kont - 18));

                if(kont == 24)
                    animazioaBukatu = 1;
                break;
            case 5:
                if (kont <= 6)
                    irudiaMugitu(1, 130 + 5 * kont, 175);
                else if (kont <= 12)
                    irudiaMugitu(1, 160 - 5 * (kont - 6), 175);
                else if (kont <= 18)
                    irudiaMugitu(1, 130 + 5 * (kont - 12), 175);
                else if (kont <= 24)
                    irudiaMugitu(1, 160 - 5 * (kont - 18), 175);

                if(kont == 24)
                    animazioaBukatu = 1;
                break;
            case 6:
                if(kont <= 6)
                    irudiaMugitu(1, 130 - 5 * kont, 175);
                else if(kont <= 12)
                    irudiaMugitu(1, 100 + 5 * (kont - 6), 175);

                if (kont == 12)
                    animazioaBukatu = 1;
                break;
            default:
                break;
            }
            hurrengoMugimendua = SDL_GetTicks() + mugimenduDenbora;
            kont++;
        }
        irudiakMarraztu();
        pantailaBerriztu();
    }
}

void AnimatuEtsaia(int zein)
{
    int animazioaBukatu = 0;
    int kont = 0;
    unsigned int hurrengoMugimendua = 0, mugimenduDenbora = 30;
    while (animazioaBukatu == 0)
    {
        ebentu = ebentuaJasoGertatuBada();

        pantailaGarbitu();
        if (hurrengoMugimendua < SDL_GetTicks())
        {
            switch (zein)
            {
            case 1:
                if (kont <= 6)
                    irudiaMugitu(3, 380 - 5 * kont, 175);
                else if (kont <= 12)
                    irudiaMugitu(3, 350 + 5 * (kont - 6), 175);
                if(kont == 12)
                    animazioaBukatu = 1;
                break;
            case 2:
                if (kont <= 6)
                    irudiaMugitu(3, 380, 175 - 5 * kont);
                else if (kont <= 12)
                    irudiaMugitu(3, 380, 145 + 5 * (kont - 6));

                if(kont == 12)
                    animazioaBukatu = 1;
                break;
            case 3:
                if(kont <= 6)
                    irudiaMugitu(3, 380 + 5 * kont, 175 );
                else if(kont <= 12)
                    irudiaMugitu(3, 410 - 5 * (kont - 6), 175);
                else if(kont <= 18)
                    irudiaMugitu(3, 380 - 5 * (kont - 12), 175);
                else if(kont <= 24)
                    irudiaMugitu(3, 350 + 5 * (kont - 18), 175);

                if(kont == 24)
                    animazioaBukatu = 1;
                break;
            default:
                break;
            }
            hurrengoMugimendua = SDL_GetTicks() + mugimenduDenbora;
            kont++;
        }
        irudiakMarraztu();
        pantailaBerriztu();
    }
}

void EtsaiaSortu(int buruzagiaDa)
{
    switch (akuarioa)
    {
        case 1:
            if (buruzagiaDa == 0)
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Maton1.png", 3);
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 60;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 10;
                etsaia.sendaketa = 10;
                etsaia.probabilitateaKontra = 40;
                etsaia.probabilitateaSendatu = 0;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            else
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi1.png", 3); //CAMBIAR EL DIBUJO PARA QUE TENGA EL TAMAÑO BIEN Y HACER QUE CADA ETSAIA TENGA SU X E Y PARA QUE AUN TENIENDO TAMAÑOS DISTINTOS LAS ANIMACIONES VAYAN BIEN.
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 80;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 20;
                etsaia.sendaketa = 10;
                etsaia.probabilitateaKontra = 33;
                etsaia.probabilitateaSendatu = 66;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            break;
        case 2:
            if (buruzagiaDa == 0)
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Maton2.png", 3);
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 110;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 25;
                etsaia.sendaketa = 10;
                etsaia.probabilitateaKontra = 33;
                etsaia.probabilitateaSendatu = 66;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            else
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi2.png", 3);
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 150;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 20;
                etsaia.sendaketa = 40;
                etsaia.probabilitateaKontra = 33;
                etsaia.probabilitateaSendatu = 43;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            break;
        case 3:
            if (buruzagiaDa == 0)
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Maton3.png", 3);
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 120;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 25;
                etsaia.sendaketa = 10;
                etsaia.probabilitateaKontra = 33;
                etsaia.probabilitateaSendatu = 66;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            else
            {
                irudiaKargatu(".\\img\\Pertsonaiak\\Buruzagi3.png", 3);
                irudiaMugitu(3, 380, 175);
                etsaia.bizitzaMax = 200;
                etsaia.bizitza = etsaia.bizitzaMax;
                etsaia.indarra = 30;
                etsaia.sendaketa = 20;
                etsaia.probabilitateaKontra = 33;
                etsaia.probabilitateaSendatu = 70;
                etsaia.kontSen = 0;
                etsaia.kontKon = 0;
            }
            break;
    }
}