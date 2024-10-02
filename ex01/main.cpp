/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 03:58:41 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/02 13:28:04 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
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
	}
	std::cout << "----------------" << std::endl;
	{
		try
		{
			Bureaucrat Bob("Bob", 50);
			Form formA("FormA", 50, 75);
			std::cout << Bob << std::endl;
			Bob.signForm(formA);
			std::cout << formA << std::endl;
			//formA.beSigned(Bob);
			//std::cout << formA << std::endl;
			std::cout << "reached end of try box" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Within catch box" << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}