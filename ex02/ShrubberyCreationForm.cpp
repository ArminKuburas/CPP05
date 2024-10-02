/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:00:41 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/02 13:37:42 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source), _target(source._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _target << " destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	if (this == &source)
		return (*this);
	_target = source._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		std::cerr << "File " << this->_target << "_shrubbery could not be created/opened." << std::endl;
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			file << "       _-_\n"
				 << "    /~~   ~~\\\n"
				 << " /~~         ~~\\\n"
				 << "{               }\n"
				 << " \\  _-     -_  /\n"
				 << "   ~  \\\\ //  ~\n"
				 << "_- -   | | _- _\n"
				 << "  _ -  | |   -_\n"
				 << "      // \\\\\n"
				 << std::endl;
		}
		file.close();
		std::cout << "Shrubbery has been created." << std::endl;
	}
}