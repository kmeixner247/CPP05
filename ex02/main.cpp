/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:14:56 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 19:13:28 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
int main()
{
	Bureaucrat phil("Phil", 1);
	Bureaucrat bill("Bill", 150);
	ShrubberyCreationForm form1("home");
	ShrubberyCreationForm form2(form1);
	RobotomyRequestForm form3("Bender");
	RobotomyRequestForm form4(form3);
	PresidentialPardonForm form5("Santa");
	PresidentialPardonForm form6(form5);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << form4 << std::endl;
	std::cout << form5 << std::endl;
	std::cout << form6 << std::endl;
	bill.signForm(form1);
	bill.signForm(form3);
	bill.signForm(form5);
	std::cout << std::string(80, '-') << std::endl;
	phil.executeForm(form1);
	std::cout << std::string(80, '-') << std::endl;
	phil.executeForm(form3);
	std::cout << std::string(80, '-') << std::endl;
	phil.executeForm(form5);
}