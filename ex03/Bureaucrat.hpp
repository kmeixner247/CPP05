/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:51:10 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 19:00:51 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"
class AForm;
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
	void signForm(AForm &f) const;
	void executeForm(AForm const &form) const;
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