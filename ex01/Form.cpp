/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:35:26 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/01 23:15:04 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>
Form::Form() :
_name("default"),
_signed(false),
_signGrade(150),
_execGrade(150)
{
}

Form::Form(Form const &rhs) :
_name(rhs._name),
_signed(rhs._signed),
_signGrade(rhs._signGrade),
_execGrade(rhs._execGrade)
{
}

Form::Form(std::string name, int toSign, int toExec) :
_name(name),
_signed(false),
_signGrade(toSign),
_execGrade(toExec)
{
	if (toSign < 1 || toExec < 1)
		throw Form::GradeTooHighException();
	if (toSign > 150 || toExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int  Form::getSignGrade() const
{
	return (this->_signGrade);
}

int  Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	std::cout << "Form " << i.getName() << "(";
	std::cout << (i.getSigned() ? "SIGNED" : "UNSIGNED") << ", ";
	std::cout << "ToSign: " << i.getSignGrade() << ", ";
	std::cout << "ToExec: " << i.getExecGrade() << ")";
	return (o);
}
