// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 15:07:19 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 15:07:20 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATATIME_HPP
# define DATATIME_HPP

#include <iostream>
#include <unistd.h>
#include "Module.hpp"
# include <SDL.h>


class DateTime : Module {


	public:

		SDL_Surface		*_bmp;

		DateTime();
		DateTime(SDL_Surface *bmp);
		DateTime(DateTime const & src);
		~DateTime();

		DateTime    	&operator= (const DateTime &rhs);
		const char*		getHour( void );
		void			setHour( void );
		//void 			drow(); //  для н керсес
		SDL_Surface * 	drow();

		char			_buffer[80];

		
};

#endif