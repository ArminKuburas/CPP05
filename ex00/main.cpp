/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 03:58:41 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 15:10:08 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat steve("Steve", 20);
		std::cout << steve << std::endl;
		steve.decrementGrade();
		std::cout << steve << std::endl;
		steve.incrementGrade();
		std::cout << steve << std::endl;
	}
	try
	{
		Bureaucrat steve("Steve", 20);
		while (true)
		{
			std::cout << steve << std::endl;
			steve.incrementGrade();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("John", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}