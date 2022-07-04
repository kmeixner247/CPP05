/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:35:26 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 20:55:43 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <string>
AForm::AForm() :
_name("default"),
_signed(false),
_signGrade(150),
_execGrade(150)
{
}

AForm::AForm(AForm const &rhs) :
_name(rhs._name),
_signed(rhs._signed),
_signGrade(rhs._signGrade),
_execGrade(rhs._execGrade)
{
}

AForm::AForm(std::string name, int toSign, int toExec) :
_name(name),
_signed(false),
_signGrade(toSign),
_execGrade(toExec)
{
	if (toSign < 1 || toExec < 1)
		throw AForm::GradeTooHighException();
	if (toSign > 150 || toExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int  AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int  AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void AForm::setSigned(bool b)
{
	this->_signed = b;
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->_signed = true;
}

bool AForm::checkForExec(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormUnsignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	return (0);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::FormUnsignedException::what() const throw()
{
	return ("Form unsigned!");
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	std::cout << i.getName() << "(";
	std::cout << (i.getSigned() ? "SIGNED" : "UNSIGNED") << ", ";
	std::cout << "ToSign: " << i.getSignGrade() << ", ";
	std::cout << "ToExec: " << i.getExecGrade() << ")";
	return (o);
}
