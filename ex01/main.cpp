/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:14:56 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/01 23:26:36 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
int main()
{
	Form tmp("C34", 98, 23);
	Form tmp2("C34", 98, 23);
	Bureaucrat billy("Billy", 98);
	Bureaucrat bobby("Bobby", 99);
	std::cout << tmp << std::endl;
	billy.signForm(tmp);
	bobby.signForm(tmp2);
}