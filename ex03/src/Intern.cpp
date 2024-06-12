/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:12:32 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 21:54:33 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

#include <iostream>

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

const char *Intern::InvalidNameException::what() const throw()
{
  return ("Invalid form name!");
}

static AForm *createShrubberyForm(std::string const &target)
{
  return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyForm(std::string const &target)
{
  return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialForm(std::string const &target)
{
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
  AForm *form = NULL;

  static formList const forms[3] = {
      {"Shrubbery Creation Form", createShrubberyForm},
      {"Robotomy Request Form", createRobotomyForm},
      {"Presidential Pardon Form", createPresidentialForm}};

  for (int i = 0; i < 3; i++)
  {
    if (forms[i].formName == formName)
    {
      form = forms[i].function(target);
      std::cout << "Intern creates " << *form << std::endl;
      return (form);
    }
  }
  throw InvalidNameException();
}
