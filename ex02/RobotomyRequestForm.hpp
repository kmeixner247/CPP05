/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:53:43 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 18:43:35 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
};
#endif