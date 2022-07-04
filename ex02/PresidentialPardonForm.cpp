/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:53:41 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 19:23:47 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm::PresidentialPardonForm() :
AForm::AForm("Presidential Pardon Form", 25, 5),
_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm::AForm("Presidential Pardon Form", 25, 5),
_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) :
AForm::AForm(rhs.getName(), 25, 5),
_target(rhs._target)
{
	this->_signed = rhs.getSigned();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->setSigned(rhs.getSigned());
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkForExec(executor);
	std::cout << this->_target << " has been pardoned by president Zaphod Beeblebrox!" << std::endl;
}