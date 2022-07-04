/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:53:08 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 19:24:16 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs._name), _grade(rhs._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string const Bureaucrat::getName() const
{
	return (this->_name);

}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm &f) const
{
	std::cout << this->_name;
	try
	{
		f.beSigned(*this);
		std::cout << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << " couldn't sign " << f.getName() << " because: ";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f) const
{
	try
	{
		f.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't execute the fucking " << f.getName() << " because: ";
		std::cout << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	std::cout << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}
