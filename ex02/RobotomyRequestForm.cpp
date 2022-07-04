/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:53:41 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:09 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
RobotomyRequestForm::RobotomyRequestForm() :
AForm::AForm("Robotomy Request Form", 72, 45),
_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm::AForm("Robotomy Request Form", 72, 45),
_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) :
AForm::AForm(rhs.getName(), 72, 45),
_target(rhs._target)
{
	this->_signed = rhs.getSigned();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->setSigned(rhs.getSigned());
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->checkForExec(executor);
	}
	catch(std::exception &e)
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because: ";
		std::cout << e.what() << std::endl;
		return ;
	}
	srand(time(NULL));
	std::cout << "* LOUD DRILLING NOISES *" << std::endl;
	std::cout << this->_target;
	std::cout << (rand() % 2 ? " has been successfully robotomized!" : "'s robotomy failed!") << std::endl;
}