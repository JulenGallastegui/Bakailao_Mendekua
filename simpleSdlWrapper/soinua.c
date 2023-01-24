#define SOINUA_C
#include "soinua.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "ebentoak.h"
#include <stdio.h>
//#include <cstring>

void musicUnload(void);
void soundsUnload();

Mix_Chunk* soinuak[MAX_SOUNDS];
int soinuKop = 0;
Mix_Music * musika=NULL;
char *musikaFileName = "";

extern int ctrl;
int urrengoBolumenAldaketa = 0, bolumenaAldatzekoDenborartea = 250;
int musikaBolumena = 8, soinuBolumena = 8;

void audioInit()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

int soinuaDago(int channel)
{
	return Mix_Playing(channel);
}

int loadSound(char *fileName)
{
	if (soinuKop == MAX_SOUNDS)
		return -1;
	if((soinuak[soinuKop] = Mix_LoadWAV(fileName))==NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return -1;
	}
	soinuKop++;
	return soinuKop-1;
}

int kargatuMusika(char *fileName)
{
	if (musikaFileName == fileName && musikaFileName != "")
		return 1;

	musikaFileName = fileName;

	if (musika != NULL)
	{
		Mix_HaltMusic();
		//Mix_FreeMusic(musika);
	}
	if ((musika = Mix_LoadMUS(fileName)) == NULL) 
		return 0;
	if (Mix_PlayingMusic() == 0)
		playMusic();

	return 1;
}

int playSound(int idSound)
{
	if ((idSound<=0)&&(idSound>=soinuKop)) 
		return -1;
	return Mix_PlayChannel(-1, soinuak[idSound], 0);
}

int playMusic(void)
{
	if (musika != NULL)
	{
		Mix_PlayMusic(musika, -1);
		return 1;
	}
	return 0;
}

void playPauseMusika(void)
{
	if (musika != NULL)
	{
		if (Mix_PlayingMusic() != 0)
		{
			if (Mix_PausedMusic()) Mix_ResumeMusic();
			else Mix_PauseMusic();
		}
		else playMusic();
	}
}


void musicUnload(void)
{
	if (musika != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(musika);
	}
}

void soundsUnload()
{
	int i;

	for (i = 0; i < soinuKop; i++)
	{
		Mix_FreeChunk(soinuak[i]);
		soinuak[i] = NULL;
	}
	soinuKop = 0;
}

void audioTerminate(void)
{
	Mix_HaltChannel(-1);
	soundsUnload();
	musicUnload();
	Mix_Quit();
}

int aldatuMusika(char *fileName)
{
	musikaFileName = fileName;
	Mix_PauseMusic();
	musicUnload();
	return kargatuMusika(fileName);
}

int geldituMusika(void)
{
	return aldatuMusika(musikaFileName);
}

int musikarenBolumena(int vol)
{
	if (vol < 0 || vol > 8)
		return 0;

	musikaBolumena = vol;
	
	Mix_VolumeMusic(16 * vol);
	return 1;
}

int soinuenBolumena(int vol)
{
	if (vol < 0 || vol > 8)
		return 0;

	soinuBolumena = vol;

	Mix_Volume(-1, 16 * vol);
	return 1;
}

int bolumenaAldatu(int ebentu)
{
	if (ctrl == 1)
	{
		switch (ebentu)
		{
		case TECLA_i:
			if (urrengoBolumenAldaketa < SDL_GetTicks() && musikaBolumena != 8)
			{
				urrengoBolumenAldaketa = SDL_GetTicks() + bolumenaAldatzekoDenborartea;
				musikaBolumena++;
			}
			break;
		case TECLA_k:
			if (urrengoBolumenAldaketa < SDL_GetTicks() && musikaBolumena != 0)
			{
				urrengoBolumenAldaketa = SDL_GetTicks() + bolumenaAldatzekoDenborartea;
				musikaBolumena--;
			}
			break;
		case TECLA_o:
			if (urrengoBolumenAldaketa < SDL_GetTicks() && soinuBolumena != 8)
			{
				urrengoBolumenAldaketa = SDL_GetTicks() + bolumenaAldatzekoDenborartea;
				soinuBolumena++;
			}
			break;
		case TECLA_l:
			if (urrengoBolumenAldaketa < SDL_GetTicks() && soinuBolumena != 0)
			{
				urrengoBolumenAldaketa = SDL_GetTicks() + bolumenaAldatzekoDenborartea;
				soinuBolumena--;
			}
			break;
		case TECLA_i_UP:
		case TECLA_k_UP:
		case TECLA_o_UP:
		case TECLA_l_UP:
			urrengoBolumenAldaketa = 0;
			break;
		default:
			break;
		}
	}
	Mix_VolumeMusic(musikaBolumena * 16);
	Mix_Volume(-1, soinuBolumena * 16);
	return 1;
}

int MusikaBolumenaJaso(void)
{
	return Mix_VolumeMusic(-1) / 16;
}

int SoinuenBolumenaJaso(void)
{
	return Mix_Volume(-1, -1) / 16;
}