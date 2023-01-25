
#include "SDL_TTF.h"
#include "SDL.h"

#include "text.h"
#include "graphics.h"
#include "imagen.h"
#include "ebentoak.h"
#include <stdio.h>
#include <string.h>

TTF_Font *font=0;
int idazten = 0;
SDL_Color textColor = { 255, 255, 255 };

void textuaGaitu(int tamaina){
	font=TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\Arial.TTF", tamaina, 0);
	if(!font) 
	{
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

void textuaIdatzi(int x, int y, char *str)
{
	SDL_Surface* textSurface;
	SDL_Texture *mTexture;
	SDL_Rect src, dst;
	SDL_Renderer* gRenderer;

	if (font == 0) 
		return;
	gRenderer = getRenderer();
	textSurface = TTF_RenderUTF8_Solid(font, str, textColor);
	mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	src.x = 0; dst.x = x;
	src.y = 0; dst.y = y;
	src.w = dst.w = textSurface->w;
	src.h = dst.h = textSurface->h;
	SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
}

void textuaIdatziPixkanaka(int x, int y, int denbora, char* str)
{
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	SDL_Rect src, dst;
	SDL_Renderer* gRenderer;
	int ebentu = 0;

	int hurrengoLetra = 0;
	char str2[MAX_STRLEN];

	if (font == 0)
		return;
	gRenderer = getRenderer();

	if (strlen(str) > 255)
	{
		str = "Textua luzeegia da.";
		textSurface = TTF_RenderUTF8_Solid(font, str, textColor);
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		src.x = 0; dst.x = x;
		src.y = 0; dst.y = y;
		src.w = dst.w = textSurface->w;
		src.h = dst.h = textSurface->h;
		SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(mTexture);
	}
	else
	{
		idazten = 1;
		hurrengoLetra = SDL_GetTicks();
		for (size_t i = 0; i < strlen(str); i++)
		{
			while (hurrengoLetra > SDL_GetTicks())
			{

			}
			ebentu = ebentuaJasoGertatuBada();
			if (ebentu == TECLA_RETURN || ebentu == TECLA_SPACE || ebentu == SAGU_BOTOIA_EZKERRA)
				break;
			hurrengoLetra += denbora;
			str2[i] = str[i];
			str2[i + 1] = '\0';
			textSurface = TTF_RenderUTF8_Solid(font, str2, textColor);
			mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
			src.x = 0; dst.x = x;
			src.y = 0; dst.y = y;
			src.w = dst.w = textSurface->w;
			src.h = dst.h = textSurface->h;
			SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
			SDL_FreeSurface(textSurface);
			SDL_DestroyTexture(mTexture);
			pantailaBerriztu();
		}

		if (ebentu == TECLA_RETURN || ebentu == TECLA_SPACE || ebentu == SAGU_BOTOIA_EZKERRA)
		{
			textuaIdatzi(x, y, str);
			pantailaBerriztu();
		}

		idazten = 0;
	}

}

void textuaDesgaitu(void)
{
	if (font != 0) TTF_CloseFont(font);
	font = 0;
}
