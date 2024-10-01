/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:54:29 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 10:57:50 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _is_signed(false)
{
}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _is_signed(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &source) : _name(source._name), _grade_to_sign(source._grade_to_sign), _grade_to_execute(source._grade_to_execute), _is_signed(source._is_signed)
{
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

AForm &AForm::operator=(const AForm &source)
{
	if (this == &source)
		return (*this);
	_is_signed = source._is_signed;
	return (*this);
}

const std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSign() const
{
	return (_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (_grade_to_execute);
}

bool AForm::getIsSigned() const
{
	return (_is_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	if (form.getIsSigned())
		out << " and is signed";
	else
		out << " and is not signed";
	return (out);
}