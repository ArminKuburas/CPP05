/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:50:15 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 11:52:41 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &source);
		~Intern();

		Intern &operator=(const Intern &source);

		AForm *makeForm(const std::string form, const std::string target);
	private:
		typedef AForm *(Intern::*formCreator)(const std::string target);
		AForm *createPresidentialPardonForm(const std::string target);
		AForm *createRobotomyRequestForm(const std::string target);
		AForm *createShrubberyCreationForm(const std::string target);
};

#endif