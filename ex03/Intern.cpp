/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:26:45 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 21:01:39 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &rhs)
{
	*this = rhs;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

const char *Intern::UnknownFormException::what() const throw()
{
	return ("Not a known Form!");
}

AForm *Intern::decideForm(std::string form, std::string target)
{
	std::string knownforms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(Intern::*fptr[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	int i = 0;
	while (i < 3 && form.compare(knownforms[i]))
		i++;
	if (i == 3)
		throw Intern::UnknownFormException();
	else
		return ((this->*fptr[i])(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	try
	{
		return (Intern::decideForm(form, target));
	}
	catch (std::exception &e)
	{
		std::cout << "The Intern couldn't create the fucking " << form << " form because: ";
		std::cout << e.what() << std::endl;
	}
	return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
