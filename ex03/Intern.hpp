/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:26:42 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 20:34:48 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern {
public:
	Intern();
	Intern(Intern const &rhs);
	~Intern();
	Intern &operator=(Intern const &rhs);
	AForm *makeForm(std::string form, std::string target);
	class UnknownFormException : public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	AForm *decideForm(std::string form, std::string target);
	AForm *makeShrubberyCreationForm(std::string target);
	AForm *makeRobotomyRequestForm(std::string target);
	AForm *makePresidentialPardonForm(std::string target);
};
#endif