/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:55:14 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 12:41:07 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

#include <iostream>
#include <ostream>

Form::Form(void)
    : _name("unknown"), _signGrade(150), _execGrade(150), _isSigned(false)
{
}

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signGrade(signGrade),
      _execGrade(execGrade),
      _isSigned(false)
{
  if (signGrade < 1 || execGrade < 1)
  {
    throw Form::GradeTooHighException();
  }
  if (signGrade > 150 || execGrade > 150)
  {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form &other)
    : _name(other._name),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade),
      _isSigned(other._isSigned)
{
}

Form &Form::operator=(const Form &other)
{
  if (this != &other)
  {
    this->_isSigned = other.getIsSigned();
  }
  return (*this);
}
Form::~Form(){};

std::string Form::getName() const { return (this->_name); }
int Form::getSignGrade() const { return (this->_signGrade); }
int Form::getExecGrade() const { return (this->_execGrade); }
bool Form::getIsSigned() const { return (this->_isSigned); }

void Form::setIsSigned(bool status) { this->_isSigned = status; }

void Form::beSigned(Bureaucrat &b)
{
  if (this->getIsSigned() == true)
  {
    std::cout << "This form is signed already!" << std::endl;
    return;
  }
  if (b.getGrade() <= this->getSignGrade())
  {
    setIsSigned(true);
  }
  else
  {
    throw Form::GradeTooLowException();
  }
}

const char *Form::GradeTooHighException::what() const throw()
{
  return "Grade is too high! (Range from 1 to 150)";
}

const char *Form::GradeTooLowException::what() const throw()
{
  return "Grade is too low! (Range from 1 to 150)";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
  os << form.getName() << " , form sign grade " << form.getSignGrade()
     << " , execute grade " << form.getExecGrade() << " , sign status "
     << (form.getIsSigned() ? "True" : "False");
  return (os);
}
