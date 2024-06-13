/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:45 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 12:45:50 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

#include <exception>
#include <iostream>

#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
  if (grade < 1)
  {
    throw Bureaucrat::GradeTooHighException();
  }
  else if (grade > 150)
  {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  if (this != &other)
  {
    this->_grade = other.getGrade();
  }
  return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade(void)
{
  if (this->getGrade() - 1 < 1) throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
  if (this->getGrade() + 1 > 150) throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << *this << " signed " << form << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << *this << " couldn't sign " << form << " because " << e.what()
              << "." << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const
{
  try
  {
    form.execute(*this);
	std::cout << *this << " executed " << form  << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high! (Range from 1 to 150)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low! (Range from 1 to 150)";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
  os << bureaucrat.getName() << ", bereaucrat grade " << bureaucrat.getGrade();
  return (os);
}
