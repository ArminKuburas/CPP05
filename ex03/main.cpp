/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:56:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 11:56:16 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* form4 = someRandomIntern.makeForm("nonexistent form", "Nobody");

        Bureaucrat alice("Alice", 45);
        Bureaucrat bob("Bob", 5);

        if (form1)
        {
            alice.signForm(*form1);
            alice.executeForm(*form1);
            delete form1;
        }

        std::cout << "------------------" << std::endl;

        if (form2)
        {
            alice.signForm(*form2);
            alice.executeForm(*form2);
            delete form2;
        }

        std::cout << "------------------" << std::endl;

        if (form3)
        {
            bob.signForm(*form3);
            bob.executeForm(*form3);
            delete form3;
        }

        std::cout << "------------------" << std::endl;

        if (form4)
        {
            delete form4; // should be nullptr, but just to be safe
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}