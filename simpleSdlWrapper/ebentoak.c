#include "ebentoak.h"

POSIZIOA saguPos;
SDL_Event event;

POSIZIOA saguarenPosizioa() { return saguPos;}

int ctrl, alt, shift;
extern int idazten;

int ebentuaJasoGertatuBada(void){
	int ret = 0;
	if( SDL_PollEvent( &event ))
	{
		/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
		//Idazten ez denean
		if (idazten == 0)
		{
			switch( event.type )
			{
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_LEFT:
							ret = TECLA_LEFT;
							//actualizaPlayer(-15);
							break;
						case SDLK_RIGHT:
							ret = TECLA_RIGHT;
							//actualizaPlayer(15);
							break;
						case SDLK_DOWN:
							ret = TECLA_DOWN;	
							break;
						case SDLK_UP:
							ret = TECLA_UP;
							break;
						case SDLK_RCTRL:
						case SDLK_LCTRL:
							ctrl = 1;
							break;
						case SDLK_RALT:
						case SDLK_LALT:
							alt = 1;
							break;
						case SDLK_RSHIFT:
						case SDLK_LSHIFT:
							shift = 1;
							break;
						case SDLK_TAB:
							ret = TECLA_TAB;
							break;
						case SDLK_SPACE:
							ret = TECLA_SPACE;
							break;
						default:
							ret = event.key.keysym.sym;
							break;
					}
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
						case SDLK_RCTRL:
						case SDLK_LCTRL:
							ctrl = 0;
							break;
						case SDLK_RALT:
						case SDLK_LALT:
							alt = 0;
							break;
						case SDLK_RSHIFT:
						case SDLK_LSHIFT:
							shift = 0;
							break;
						case SDLK_i:
							ret = TECLA_i_UP;
							break;
						case SDLK_k:
							ret = TECLA_k_UP;
							break;
						case SDLK_o:
							ret = TECLA_o_UP;
							break;
						case SDLK_l:
							ret = TECLA_l_UP;
							break;
						default:
							break;
					}
					break;
				case SDL_QUIT:
					ret = GERTAERA_IRTEN;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT)
						ret = SAGU_BOTOIA_EZKERRA_DOWN;
					break;
				case SDL_MOUSEBUTTONUP:
					switch ( event.button.button ){
						case SDL_BUTTON_LEFT:
							ret = SAGU_BOTOIA_EZKERRA;
							break;
						case SDL_BUTTON_RIGHT:
							ret = SAGU_BOTOIA_ESKUMA;
							break;
						default:
							ret = event.button.button;
							break;
					}
					break;
				case SDL_MOUSEMOTION:
					//ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
					saguPos.x = event.motion.x;
					saguPos.y =event.motion.y;
					ret = SAGU_MUGIMENDUA;
					break;
				case SDL_MOUSEWHEEL:
					if(event.wheel.y > 0)
						ret = SAGU_SCROLL_GORA;
					else if (event.wheel.y < 0)
						ret = SAGU_SCROLL_BEHERA;
					else if (event.wheel.x > 0)
						ret = SAGU_SCROLL_ESKUMA;
					else if (event.wheel.x < 0)
						ret = SAGU_SCROLL_EZKERRA;
					break;
				default:
					break;
			}
		}
		//Idazten dagoenean
		else
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_RETURN:
						case SDLK_KP_ENTER:
							ret = TECLA_RETURN;
							break;
						case SDLK_SPACE:
							ret = TECLA_SPACE;
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
					case SDLK_RCTRL:
					case SDLK_LCTRL:
						ctrl = 0;
						break;
					case SDLK_RALT:
					case SDLK_LALT:
						alt = 0;
						break;
					case SDLK_RSHIFT:
					case SDLK_LSHIFT:
						shift = 0;
						break;
					default:
						break;
					}
					break;
				case SDL_QUIT:
					ret = GERTAERA_IRTEN;
					break;
				case SDL_MOUSEBUTTONUP:
					switch (event.button.button)
					{
						case SDL_BUTTON_RIGHT:
							ret = SAGU_BOTOIA_ESKUMA;
						case SDL_BUTTON_LEFT:
							ret = SAGU_BOTOIA_EZKERRA;
							break;
							break;
						default:
							break;
					}
					break;
				case SDL_MOUSEMOTION:
					//ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
					saguPos.x = event.motion.x;
					saguPos.y = event.motion.y;
					ret = SAGU_MUGIMENDUA;
					break;
				default:
					break;
			}
		} 
	}
	return ret;
}

