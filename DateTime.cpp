// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 15:30:51 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 15:30:52 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTime.hpp"
#include <string>
#include <iostream>


DateTime::DateTime() : _bmp(NULL) {

};

DateTime::DateTime(SDL_Surface *bmp) {

	_bmp = bmp;
	setHour();
};

DateTime::~DateTime() {


};

void         DateTime::setHour( void ) {

    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(_buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
}

const char *      DateTime::getHour(void)
{
    setHour();
    return _buffer;
}

SDL_Surface *		DateTime::drow() {

	setHour();
	TTF_Font* font = TTF_OpenFont("SDL/OpenSans-Regular.ttf", 30);
	SDL_Color color;
	color.r = 255;
	color.g = 255;
	color.b = 0;
	SDL_Surface *TTF_TextSolid = TTF_RenderText_Solid(font, "AS313311321S", color);
	TTF_CloseFont(font);
	return (TTF_TextSolid);
};
