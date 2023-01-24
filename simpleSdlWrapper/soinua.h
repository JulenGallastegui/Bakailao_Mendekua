#ifndef SOINUA_H
#define SOINUA_H

#define MAX_SOUNDS 100

#include <SDL_mixer.h>

void audioInit();
int soinuaDago(int channel);
int loadSound(char *fileName);
int kargatuMusika(char *fileName);
int playSound(int idSound);
int playMusic(void);
void playPauseMusika(void);
void audioTerminate();
int aldatuMusika(char* fileName);
int geldituMusika(void);
int musikarenBolumena(int vol);
int soinuenBolumena(int vol);
int bolumenaAldatu(int ebentu);
int MusikaBolumenaJaso(void);
int SoinuenBolumenaJaso(void);
#endif