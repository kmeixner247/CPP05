/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:51:10 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/01 22:12:45 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
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