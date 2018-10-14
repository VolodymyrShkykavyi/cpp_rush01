// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 13:04:12 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 13:04:13 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include <iostream>

#include "graphic.hpp"
#include "DateTime.hpp"


int main () {

	std::cout << "Select display" << std::endl << "1: Graphic" << std::endl << "2: Terminal" << std::endl;
	std::string input;
	std::cin >> input;
	if (input == "1")
    {
    	std::cout << "Grafic" << std::endl;
    	Graphic	graph;
    	graph.start();
    }
    else if (input == "2")
    {
    	 std::cout << "Ncerces" << std::endl;
    }
    else
        std::cout << "ERROR: Please Select1 or 2." << std::endl;
    return 0;
}

