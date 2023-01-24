#define _CRT_SECURE_NO_WARNINGS
#include "HasierakoMenua.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h>

int HasierakoArgazkiak(void)
{
	int hasierakoDenbora = SDL_GetTicks();
	irudiaKargatu(".\\img\\MUN logo.jpg", 0);
	irudiakMarraztu();
	pantailaBerriztu();
	while (SDL_GetTicks() - hasierakoDenbora < 1000)
	{
		if (ebentuaJasoGertatuBada() == GERTAERA_IRTEN) return -1; 
	}

	irudiaKargatu(".\\img\\Bakailao Mendekua logo.png", 0);
	irudiakMarraztu();
	pantailaBerriztu();
	hasierakoDenbora = SDL_GetTicks();
	while (SDL_GetTicks() - hasierakoDenbora < 2000)
	{
		if (ebentuaJasoGertatuBada() == GERTAERA_IRTEN) return -1;
	}

	return 1;
}
