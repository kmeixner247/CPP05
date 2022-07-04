/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:14:56 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 20:45:24 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
int main()
{
	Form tmp("C34", 98, 23);
	Form tmp2(tmp);
	std::cout << "Trying to create a form with a too low grade!" << std::endl;
	try
	{
		Form tmp3("OHNO", 151, 23);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Trying to create a form with a too high grade!" << std::endl;
	try
	{
		Form tmp3("OHNO", 98, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat billy("Billy", 98);
	Bureaucrat bobby("Bobby", 99);
	std::cout << std::endl << tmp << std::endl;
	std::cout << tmp2 << std::endl;
	bobby.signForm(tmp);
	billy.signForm(tmp);
	tmp2 = tmp;
	std::cout << tmp2 << std::endl;
	
}