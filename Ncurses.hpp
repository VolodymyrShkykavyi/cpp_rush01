// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurses.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 15:26:56 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/14 15:26:57 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSES_HPP
# define NCURSES_HPP

//# define WIDTH		320
//# define HEIGHT        1000
# define CYCLEDELAY    100000

#include <iostream>
#include <unistd.h>
#include <ncurses.h>


#include "DateTime.hpp"
#include "CPU.hpp"
#include "IMonitorDisplay.hpp"


class Ncurses : public IMonitorDisplay {
private:
    DateTime *_data;
    CPU *_cpu;

    int		_maxheight;
    int		_maxwidth;
    char 	oldalchar;


public:

    Ncurses();
    Ncurses(Ncurses const &src);
    ~Ncurses();


    //	Ncurses & operator=(Ncurses const & src);


    //SDL_Surface		*_time; // Серфейс который будет получать время

    // void	GetSurface();
    // void set_pixel(int x, int y, Uint32 pixel);

    void printmodule();
    void box();
    virtual void start();

};

#endif