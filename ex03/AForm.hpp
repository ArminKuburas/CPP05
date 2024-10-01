/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:50:46 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 10:52:48 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	AForm
{
	public:
		AForm();
		AForm(const std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm &source);
		virtual ~AForm();

		AForm &operator=(const AForm &source);

		const std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		private:
			const std::string _name;
			const int _grade_to_sign;
			const int _grade_to_execute;
			bool _is_signed;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif