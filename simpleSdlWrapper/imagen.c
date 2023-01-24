#include "SDL.h"

#include "graphics.h"
#include "imagen.h"
#include <stdio.h>

int irudiarenPosizioaAurkitu(int id);

typedef struct Img
{
	int id;
	SDL_Surface* imagen;
	SDL_Texture* texture;
	SDL_Rect dest;
}IMG;

IMG irudiak[MAX_IMG];

int irudiaKargatu(char* fileName, int id)
{
	SDL_Texture* img;
	SDL_Renderer* gRenderer = getRenderer();

	if (id < MAX_IMG)
	{
		//surface = SDL_LoadBMP(fileName);
		img = IMG_LoadTexture(gRenderer, fileName);
		if (img == NULL)
		{
			fprintf(stderr, "Couldn't load %s: %s\n", fileName, SDL_GetError());
			return -1;
		}
		else
		{
			int w, h;

			SDL_QueryTexture(img, NULL, NULL, &w, &h);

			irudiak[id].texture = img;
			irudiak[id].dest.x = irudiak[id].dest.y = 0;
			irudiak[id].dest.w = w;
			irudiak[id].dest.h = h;

			irudiak[id].id = id;
		}
	}
	else
	{
		printf("Sartutako ID-a handiegia da. Limitea handitzeko Imagen.h-ko MAX_IMG handitu\n");
		return -1;
	}

	return id - 1;
}

void  irudiaMugitu(int numImg, int x, int y)
{
	int id = 0;

	id = numImg;

	irudiak[id].dest.x = x;
	irudiak[id].dest.y = y;
}

void irudiakMarraztu(void)
{
	int i = 0;

	for (i = 0; i < MAX_IMG; i++)
	{
		if (irudiak[i].texture != NULL)
			irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
	}
}


void irudiaKendu(int id)
{
	int pos = 0;

	pos = id;
	SDL_DestroyTexture(irudiak[pos].texture);
	
	irudiak[pos].texture = NULL;
}

int irudiarenPosizioaAurkitu(int id)
{
	int i = 0;

	for (i = 0; i < MAX_IMG; i++)
	{
		if (id == irudiak[i].id) return i;
	}
	return -1;
}

void irudiGuztiakKendu(void)
{
	for (int i = 0; i < MAX_IMG; i++)
	{
		if (irudiak[i].texture != NULL) irudiak[i].texture = NULL;
	}
}