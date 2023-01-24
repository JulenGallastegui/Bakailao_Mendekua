#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "Mugimendua.h"
#include "OurTypes.h"
#include "Egunkaria.h"
#include "Mugikorra.h"
#include "Combate.h"
#include "pantailaAldatu.h"
#include "HasierakoMenua.h"
#include "GalduPantaila.h"
#include "Finalak.h"
#include "PowerUp.h"
#include <stdio.h>


char* soundFiles[]= {".\\sound\\Normal\\Paso grava 1.wav", ".\\sound\\Normal\\Paso grava 2.wav", ".\\sound\\Normal\\Paso madera 1.wav", ".\\sound\\Normal\\Paso madera 2.wav", 
                     ".\\sound\\Haserre\\Paso grava 1.wav", ".\\sound\\Haserre\\Paso grava 2.wav", ".\\sound\\Haserre\\Paso madera 1.wav", ".\\sound\\Haserre\\Paso madera 2.wav",
                     ".\\sound\\Oso haserre\\Paso grava 1.wav", ".\\sound\\Oso haserre\\Paso grava 2.wav", ".\\sound\\Oso haserre\\Paso madera 1.wav", ".\\sound\\Oso haserre\\Paso madera 2.wav" };


GURE_GAUZAK gureGauzak;

int hasieratu(void);
extern int ctrl, shift, alt;
int akuarioa = -1, gela = 0;

int mugimenduaItxita = 1;
int arrainGizonAbiadura = 5;

int haserreNibela = 0;

int borroka1_1 = 0;
int borroka1_2 = 0;
int buruzagi1 = 0;

extern SDL_Window* window;

int main(int argc, char * str[]) 
{
    int ebentu = 0, irten=0, akuarioAktuala = 1, gelaAktuala = -9;
 
    hasieratu();
    
    if(HasierakoArgazkiak() == -1) irten = 1;

    akuarioAktuala = akuarioa;
    gelaAktuala = gela;
    MapaHasieratu();

    while(!irten)
    {
        pantailaGarbitu();

        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
            case GERTAERA_IRTEN:
                irten = 1;
                break;
            case TECLA_b:
                if (EgunkariaJarri() == -1) irten = 1;
                break;
            case TECLA_n:
            case TECLA_ESCAPE:
                switch (MugikorraAtera())
                {
                case -1:
                    irten = 1;
                    break;
                case -2:
                    akuarioa = -1;
                    gela = 0;
                    break;
                }
                break;
            case TECLA_e:
                PowerUpJaso();
                break;
            default:
                break;
        }

        bolumenaAldatu(ebentu);

        if (mugimenduaItxita == 0) 
        {
            MugituPertsonaia(ebentu, arrainGizonAbiadura + arrainGizonAbiadura * haserreNibela);
        }

        irudiakMarraztu();
        pantailaBerriztu();

        if(AldatuGela(ebentu) == -1) irten = 1;

        if (gelaAktuala != gela || akuarioAktuala != akuarioa) //Nola aldatu gelaz
        {

            akuarioAktuala = akuarioa;
            gelaAktuala = gela;

            switch (MapaHasieratu())
            {
                case -1:
                    irten = 1;
                    break;
                case 2:
                    akuarioa = 1;
                    gela = 0;
                    break;
                case -2:
                    if (GalduPantaila() == -1)
                        irten = 1;
                    break;
                default:
                    break;
            }

        }

    }
    audioTerminate();
    sgItxi();
    return 0;
}


int hasieratu(void)
{

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 700x700 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    for (int i = 0; i < (sizeof(soundFiles) / sizeof(soundFiles[0])); i++)
    {
        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
    }

    textuaGaitu(14);
    

    return 0;

}

int MapaHasieratu()
{
    int mugimenduHasieratuReturn = 1;
    int ezKargatuMusika = 0;
    mugimenduaItxita = 1;
    switch (akuarioa)
    {
        case -1:
            irudiaKargatu(".\\img\\Menu.png", 0);
            GeziakHasieratu("menu");
            mugimenduHasieratuReturn = MugimenduaHasieratu(435, 450, "menu");
            break;
        case 0:
            break;
        case 1:
            switch (gela)
            {
                case -1:
                    irudiaKargatu(".\\img\\Anden.png", 0);
                    GeziakHasieratu("anden1");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 620, "anden1");
                    break;
                case 0:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Akuarioaren sarrera.png", 0);
                    GeziakHasieratu("akuarioarenSarrera1");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "akuarioarenSarrera1");
                    break;
                case 1:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Sarrera.png", 0);
                    GeziakHasieratu("sarrera1");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "sarrera1");
                    break;
                case 2:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Pasalekua 1.png", 0);
                    GeziakHasieratu("pasaleku1_1");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_1");
                    break;
                case 3:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Pasalekua 4.png", 0);
                    PowerUpHasieratu();
                    if (borroka1_1 == 0)
                    {
                        switch (borrokaHasi(0))
                        {
                            case 1:
                                borroka1_1 = 1;
                                break;
                            case -1:
                                return -1;
                            case -2:
                                return -2;
                        }
                    }
                    GeziakHasieratu("pasaleku1_4");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_4");
                    break;
                case 4:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Pasalekua 2.png", 0);
                    GeziakHasieratu("pasaleku1_2");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_2");
                    break;
                case 5:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Pasalekua 3.png", 0);
                    GeziakHasieratu("pasaleku1_3");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_3");
                    break;
                case 6:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\Pasalekua 5.png", 0);
                    PowerUpHasieratu();
                    if (borroka1_2 == 0)
                    {
                        switch (borrokaHasi(0))
                        {
                        case 1:
                            borroka1_2 = 1;
                            break;
                        case -1:
                            return -1;
                        case -2:
                            return -2;
                        }
                    }
                    GeziakHasieratu("pasaleku1_5");
                    mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_5");
                    break;
                case 7:
                    irudiaKargatu(".\\img\\Akuarioak\\1\\buruzagi.png", 0);
                    if (buruzagi1 == 0)
                    {
                        switch (borrokaHasi(1))
                        {
                        case 1:
                            buruzagi1 = 1;
                            haserreNibela = 1;
                            return BuruzagiAnimazioa(1);
                            break;
                        case -1:
                            return -1;
                        case -2:
                            return -2;
                        }
                    }
                    break;
                case 8:
                    irudiaKendu(ARRAIN_GIZON_ID);
                    MaparenAukerak();
                    break;
                default:
                    printf("Gela gaizki dago");
                    break;
            }
            if (ezKargatuMusika == 0 && !kargatuMusika(".\\sound\\Musica fondo 1.wav")) printf("Ezin izan da musika kargatu. %s\n", SDL_GetError());
            break;
        case 2:
            switch (gela)
            {
            case -1:
                irudiaKargatu(".\\img\\Anden.png", 0);
                GeziakHasieratu("anden2");
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 620, "anden1");
                break;
            case 0:
                irudiaKargatu(".\\img\\Akuarioak\\1\\Akuarioaren sarrera.png", 0);
                GeziakHasieratu("akuarioarenSarrera2");
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "akuarioarenSarrera1");
                break;
            case 1:
                irudiaKargatu(".\\img\\Akuarioak\\2\\sarrera.png", 0);
                GeziakHasieratu("sarrera2");
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "sarrera1");
                break;

            case 2:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua1.png", 0);
                GeziakHasieratu("pasaleku2_1");
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_1");
                break;
            case 3:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua2.png", 0);
                GeziakHasieratu("pasaleku2_2");
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_4");

                break;
            case 4:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua4.png", 0);
                GeziakHasieratu("pasaleku2_4");
                //borrokaHasi() borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_4");
                break;
            case 5:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua5.png", 0);
               GeziakHasieratu("pasaleku2_5");
                //borrokaHasi() borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_3");
                break;
            case 6:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua3.png", 0);
                GeziakHasieratu("pasaleku2_6");
                //borrokaHasi() borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_4");
                break;
            case 7:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua6.png", 0);
                GeziakHasieratu("pasaleku2_7");
                //if(borrokaHasi() ==-1) return -1 borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_3");
                break;
            case 8:
                irudiaKendu(ARRAIN_GIZON_ID);
                MaparenAukerak();
                break;
            case 9:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Pasalekua7.png", 0);
                GeziakHasieratu("pasaleku2_9");
                //if(borrokaHasi() ==-1) return -1 borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "pasaleku1_3");
                break;
            case 10:
                irudiaKargatu(".\\img\\Akuarioak\\2\\Buruzagia.png", 0);
                GeziakHasieratu("buruzagia2");
                //if(borrokaHasi() ==-1) return -1 borroka badago
                mugimenduHasieratuReturn = MugimenduaHasieratu(350, 450, "buruzagia1");
                break;
            default:
                printf("Gela gaizki dago");
                break;
            }
            break;
        case 3:
            break;
        default:
            printf("Akuario zenbakia gaizki dago");
            break;
    }
    if (mugimenduHasieratuReturn != 1)
    {
        switch (mugimenduHasieratuReturn)
        {
        case -2:
            printf("MugimenduaHasieratu()-ko koordenatuak kolisio baten barruan daude.");
            break;
        case -1:
            printf("Kolisioak kargatzeko izena gaizki dago.");
            break;
        case 0:
            printf("Mugimendua hasieratzeko sartu diren koordenatuak ez daude ondo.");
            break;
        default:
            break;
        }
        return -1;
    }

    return 1;
}