/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:51:10 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/01 23:24:44 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "Form.hpp"
class Form;
class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const name);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &rhs);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);
	std::string const getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f) const;
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	std::string const	_name;
	int					_grade;
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif