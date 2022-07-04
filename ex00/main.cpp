/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:14:56 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/01 23:07:10 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
	Bureaucrat hermes("Hermes", 36);
	std::cout << "I just instanciated " << hermes << std::endl << std::endl;
	
	std::cout << "Trying to instanciate a bureaucrat with grade 151 now:" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout << "Trying to instanciate a bureaucrat with grade 0 now:" << std::endl;
	try
	{
		Bureaucrat lucy("Lucy", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout << "Trying to instanciate two bureaucrats with grade 1 and 150 respectively now:" << std::endl << std::endl;
	try
	{
		Bureaucrat balthazar("Balthazar", 1);
		Bureaucrat jim("Jim", 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "This time doing it for real:" << std::endl;
	Bureaucrat balthazar("Balthazar", 1);
	Bureaucrat jim("Jim", 150);
	std::cout << "Here they are:" << std::endl;
	std::cout << balthazar << std::endl;
	std::cout << jim << std::endl << std::endl;
	
	std::cout << "Trying to increment Balthazar:" << std::endl;
	try
	{
		balthazar.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << balthazar << std::endl << std::endl;
	
	std::cout << "Trying to decrement Jim:" << std::endl;
	try
	{
		jim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << jim << std::endl << std::endl;
	
	std::cout << "Trying to increment Jim:" << std::endl;
	try
	{
		jim.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << jim << std::endl << std::endl;
	std::cout << "Trying to decrement Balthazar:" << std::endl;
	try
	{
		balthazar.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << balthazar << std::endl << std::endl;
}