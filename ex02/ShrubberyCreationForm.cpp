/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:53:41 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/04 19:23:57 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
ShrubberyCreationForm::ShrubberyCreationForm() :
AForm::AForm("Shrubbery Creation Form", 145, 137),
_target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm::AForm("Shrubbery Creation Form", 145, 137),
_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) :
AForm::AForm(rhs.getName(), 145, 137),
_target(rhs._target)
{
	this->_signed = rhs.getSigned();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->setSigned(rhs.getSigned());
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkForExec(executor);
	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	ofs << "                      ___" << std::endl;
	ofs << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
	ofs << "             ,-'          __,,-- \\" << std::endl;
	ofs << "           ,'    __,--\"\"\"\"dF      )" << std::endl;
	ofs << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
	ofs << "        ,'       _Hb ___dF\"-._,-'" << std::endl;
	ofs << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
	ofs << "     (     ,-'                  `." << std::endl;
	ofs << "      `._,'     _   _             ;" << std::endl;
	ofs << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
	ofs << "       \\    ,'\"Hb.-'HH`-.dHF\"" << std::endl;
	ofs << "        `--'   \"Hb  HH  dF\"" << std::endl;
	ofs << "                \"Hb HH dF" << std::endl;
	ofs << "                 \"HbHHdF" << std::endl;
	ofs << "                  |HHHF" << std::endl;
	ofs << "                  |HHH|" << std::endl;
	ofs << "                  |HHH|" << std::endl;
	ofs << "                  |HHH|" << std::endl;
	ofs << "                  |HHH|" << std::endl;
	ofs << "                  dHHHb" << std::endl;
	ofs << "                .dFd|bHb.               o" << std::endl;
	ofs << "      o       .dHFdH|HbTHb.          o /" << std::endl;
	ofs << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
	ofs << "##########################################" << std::endl;
	ofs.close();
}