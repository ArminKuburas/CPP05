/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 11:55:58 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 45);
		Bureaucrat alice("Alice", 5);
		
		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm robotForm("target1");
		PresidentialPardonForm pardonForm("target2");

		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);

		std::cout << "------------------" << std::endl;

		bob.signForm(robotForm);
		bob.executeForm(robotForm);

		std::cout << "------------------" << std::endl;

		alice.signForm(pardonForm);
		alice.executeForm(pardonForm);

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
