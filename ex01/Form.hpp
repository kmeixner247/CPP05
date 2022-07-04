/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:35:28 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 12:44:57 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
public:
	Form();
	Form(Form const &rhs);
	Form(std::string name, int toSign, int toExec);
	~Form();
	Form &operator=(Form const &rhs);
	std::string const getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat const &b);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
private:
	const std::string	_name;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;
};
std::ostream &operator<<(std::ostream &o, Form const &i);
#endif