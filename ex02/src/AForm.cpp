/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:55:14 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 12:57:53 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

#include <iostream>
#include <ostream>

AForm::AForm(void)
    : _name("unknown"), _signGrade(150), _execGrade(150), _isSigned(false)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signGrade(signGrade),
      _execGrade(execGrade),
      _isSigned(false)
{
  if (signGrade < 1 || execGrade < 1)
  {
    throw AForm::GradeTooHighException();
  }
  if (signGrade > 150 || execGrade > 150)
  {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade),
      _isSigned(other._isSigned)
{
}

AForm &AForm::operator=(const AForm &other)
{
  if (this != &other)
  {
    this->_isSigned = other.getIsSigned();
  }
  return (*this);
}

AForm::~AForm(){};

std::string AForm::getName() const { return (this->_name); }
int AForm::getSignGrade() const { return (this->_signGrade); }
int AForm::getExecGrade() const { return (this->_execGrade); }
bool AForm::getIsSigned() const { return (this->_isSigned); }

void AForm::setIsSigned(bool status) { this->_isSigned = status; }

void AForm::beSigned(Bureaucrat &b)
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
    throw AForm::GradeTooLowException();
  }
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "Grade is too high! (Range from 1 to 150)";
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return "Grade is too low! (Range from 1 to 150)";
}

const char *AForm::NotSignedException::what() const throw()
{
  return "The form is not signed!";
}

const char *AForm::NoExecException::what() const throw()
{
  return "Higher grade is needed for execution!";
}

void AForm::checkForm(const Bureaucrat &b) const
{
  if (this->getIsSigned() == false)
  {
    throw AForm::NotSignedException();
  }

  if (b.getGrade() > this->getExecGrade())
  {
    throw AForm::NoExecException();
  }
}

void AForm::execute(Bureaucrat const &executor) const
{
  AForm::checkForm(executor);
  this->executeDetail();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
  os << form.getName() << " , form sign grade " << form.getSignGrade()
     << " , execute grade " << form.getExecGrade() << " , sign status "
     << (form.getIsSigned() ? "Yes" : "No");
  return (os);
}
