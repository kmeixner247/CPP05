/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:35:28 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 18:58:37 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm {
public:
	AForm();
	AForm(AForm const &rhs);
	AForm(std::string name, int toSign, int toExec);
	virtual ~AForm();
	AForm &operator=(AForm const &rhs);
	std::string const getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void setSigned(bool b);
	void beSigned(Bureaucrat const &b);
	bool checkForExec(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class FormUnsignedException : public std::exception
	{
		const char *what() const throw();
	};
protected:
	const std::string	_name;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;
};
std::ostream &operator<<(std::ostream &o, AForm const &i);
#endif