/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:51:24 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 11:55:43 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &source)
{
	*this = source;
	std::cout << "Intern copied" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &source)
{
	if (this == &source)
		return (*this);
	return (*this);
}

AForm* Intern::createShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string form, const std::string target)
{
	formCreator creators[3] = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; ++i)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern could not create " << form << std::endl;
	return (NULL);
}