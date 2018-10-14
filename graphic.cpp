// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   graphic.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 13:12:40 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 13:12:42 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "graphic.hpp"
# include <SDL_ttf.h>
# include <SDL.h>

Graphic::Graphic() {

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    _window = SDL_CreateWindow("ft_gkrellm",
                               0, 0, WIDTH, HEIGHT, 0);
    _bmp = SDL_GetWindowSurface(_window);
    SDL_memset(_bmp->pixels, 54, _bmp->h * _bmp->pitch);
    _state = SDL_GetKeyboardState(NULL);
    std::srand(time(NULL));
    this->quit = 0;

    image = SDL_LoadBMP("image/header1.bmp");
    image2 = SDL_LoadBMP("image/body1.bmp");


    _data = new DateTime();
    _cpu = new CPU();
    _system = new System();
    _ram = new RAM();
    _network = new Network();
}

void 	Graphic::set_pixel(int x, int y, Uint32 pixel)
{

    Uint8 *target_pixel = (Uint8 *)_bmp->pixels + y * _bmp->pitch + x * 4;
    *(Uint32 *)target_pixel = pixel;
}

void	Graphic::printmodule() {


    TTF_Font* font = TTF_OpenFont("frameworks/ARIAL.TTF", 24);

    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 50;

    SDL_Surface *TTF_TextSolid = TTF_RenderText_Solid(font, "SYSTEM INFO", color);
    SDL_Rect rect = {90, 5, 50, 30};

    SDL_BlitSurface(TTF_TextSolid, NULL, _bmp, &rect);
    SDL_FreeSurface(TTF_TextSolid);

    TTF_TextSolid = TTF_RenderText_Solid(font, "CPU", color);
    SDL_Rect zrect = {130, 180, 50, 30};
    SDL_BlitSurface(TTF_TextSolid, NULL, _bmp, &zrect);
    SDL_FreeSurface(TTF_TextSolid);

    TTF_TextSolid = TTF_RenderText_Solid(font, "RAM", color);
    SDL_Rect crect = {130, 355, 50, 30};
    SDL_BlitSurface(TTF_TextSolid, NULL, _bmp, &crect);
    SDL_FreeSurface(TTF_TextSolid);

    TTF_TextSolid = TTF_RenderText_Solid(font, "DISK", color);
    SDL_Rect ccrect = {130, 530, 50, 30};
    SDL_BlitSurface(TTF_TextSolid, NULL, _bmp, &ccrect);
    SDL_FreeSurface(TTF_TextSolid);

    TTF_TextSolid = TTF_RenderText_Solid(font, "NETWORK", color);
    SDL_Rect pcrect = {110, 705, 50, 30};
    SDL_BlitSurface(TTF_TextSolid, NULL, _bmp, &pcrect);
    SDL_FreeSurface(TTF_TextSolid);

    TTF_CloseFont(font);

}

Graphic::Graphic(Graphic const & src) {

    *this = src;
}

Graphic::~Graphic() {


    SDL_DestroyWindow(_window);
    SDL_Quit();
}


void Graphic::GetSurface (){   // от времени я получаю серфейс который копирую в основной Серфейс что бы рисовать

    //system
    {
        SDL_Rect dstrect = {0, 0, 0, 0};
        SDL_BlitSurface(image, NULL, _bmp, &dstrect);

        SDL_Rect rstrect = {0, 40, 0, 0};
        SDL_BlitSurface(image2, NULL, _bmp, &rstrect);

        SDL_Rect lstrect = {15, 48, 0, 0};
        SDL_BlitSurface(_data->getSurfaceData(), NULL, _bmp, &lstrect);

        SDL_Rect userNameRect = {15, 65, 0, 0};
        SDL_BlitSurface(_system->getSurfaceUserName(), NULL, _bmp, &userNameRect);

        SDL_Rect hostNameRect = {15, 85, 0, 0};
        SDL_BlitSurface(_system->getSurfaceHostName(), NULL, _bmp, &hostNameRect);

        SDL_Rect osNameRect = {15, 105, 0, 0};
        SDL_BlitSurface(_system->getSurfaceOSName(), NULL, _bmp, &osNameRect);

        SDL_Rect osVersRect = {15, 125, 0, 0};
        SDL_BlitSurface(_system->getSurfaceOSVersion(), NULL, _bmp, &osVersRect);
    }

    //cpu
    {
        //img
        SDL_Rect cstrect = {0, 175, 10, 10};
        SDL_BlitSurface(image, NULL, _bmp, &cstrect);
        SDL_Rect mstrect = {0, 215, 10, 10};
        SDL_BlitSurface(image2, NULL, _bmp, &mstrect);

        //info
        SDL_Rect cInfostrect = {11, 223, 0, 0};
        SDL_BlitSurface(_cpu->getSurfaceInfo(), NULL, _bmp, &cInfostrect);

        SDL_Rect cUsageRect = {11, 240, 0, 0};
        SDL_BlitSurface(_cpu->getSurfaceUsage(), NULL, _bmp, &cUsageRect);

        SDL_Rect cCountRect = {11, 260, 0, 0};
        SDL_BlitSurface(_cpu->getSurfaceCPUCount(), NULL, _bmp, &cCountRect);

    }


    //ram
    {
        SDL_Rect strect = {0, 350, 10, 10};
        SDL_BlitSurface(image, NULL, _bmp, &strect);

        SDL_Rect ystrect = {0, 390, 10, 10};
        SDL_BlitSurface(image2, NULL, _bmp, &ystrect);

        SDL_Rect rUsedrect = {11, 400, 0, 0};
        SDL_BlitSurface(_ram->getSurfaceUsed(), NULL, _bmp, &rUsedrect);

        SDL_Rect rUnusedrect = {11, 415, 0, 0};
        SDL_BlitSurface(_ram->getSurfaceUnused(), NULL, _bmp, &rUnusedrect);

        SDL_Rect rMemoryrect = {11, 435, 0, 0};
        SDL_BlitSurface(_ram->getSurfaceMemory(), NULL, _bmp, &rMemoryrect);
    }


    //disk
    {
        SDL_Rect rtrect = {0, 525, 10, 10};
        SDL_BlitSurface(image, NULL, _bmp, &rtrect);

        SDL_Rect tstrect = {0, 565, 10, 10};
        SDL_BlitSurface(image2, NULL, _bmp, &tstrect);
    }


    //network
    {
        SDL_Rect ttrect = {0, 700, 10, 10};
        SDL_BlitSurface(image, NULL, _bmp, &ttrect);

        SDL_Rect ustrect = {0, 740, 10, 10};
        SDL_BlitSurface(image2, NULL, _bmp, &ustrect);

        SDL_Rect netwInrect = {11, 750, 0, 0};
        SDL_BlitSurface(_network->getSurfaceIn(), NULL, _bmp, &netwInrect);

        SDL_Rect netwOutrect = {11, 770, 0, 0};
        SDL_BlitSurface(_network->getSurfaceOut(), NULL, _bmp, &netwOutrect);
    }
    // 		_time = _data->drow();
    // 	SDL_Rect rect;
    // 	rect.x = 50;
    // 	rect.y = 50;
    // 	rect.w = 50;
    // 	rect.h = 30;
    // SDL_BlitSurface(_time, NULL, _bmp, &rect);
}

void Graphic::start() {

    while(!quit)
    {
        GetSurface();
        printmodule();
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;

            else if (e.type == SDL_KEYDOWN)
            {
                if (_state[SDL_SCANCODE_ESCAPE])
                    quit = 1;
            }
        }
        SDL_UpdateWindowSurface(_window);
     //   usleep(CYCLEDELAY);
        //	SDL_memset(_bmp->pixels, 54, _bmp->h * _bmp->pitch);
    }
}