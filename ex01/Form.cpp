/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:23:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/01 10:33:04 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _is_signed(false)
{
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _is_signed(false)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &source) : _name(source._name), _grade_to_sign(source._grade_to_sign), _grade_to_execute(source._grade_to_execute), _is_signed(source._is_signed)
{
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form &Form::operator=(const Form &source)
{
	if (this == &source)
		return (*this);
	_is_signed = source._is_signed;
	return (*this);
}

const std::string Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (_grade_to_execute);
}

bool Form::getIsSigned() const
{
	return (_is_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	if (form.getIsSigned())
		out << " and is signed";
	else
		out << " and is not signed";
	return (out);
}

