/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:43:22 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void)
{
  std::cout << "===== Test ShrubberyCreationForm =====" << std::endl;

  try
  {
    AForm *sForm1 = new ShrubberyCreationForm();
    std::cout << *sForm1 << std::endl;

	Bureaucrat b1("Office1", 1);
    AForm *sForm2 = new ShrubberyCreationForm("Target1");
    std::cout << *sForm2 << std::endl;

	b1.signForm(*sForm2);
	b1.executeForm(*sForm2);

	Bureaucrat b2("Office2", 145);
    AForm *sForm3 = new ShrubberyCreationForm("Target2");
    std::cout << *sForm3 << std::endl;
	b2.executeForm(*sForm3);

	b2.signForm(*sForm3);
	b2.executeForm(*sForm3);

	delete sForm1;
	delete sForm2;
	delete sForm3;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "===== Test RobotomyRequestForm =====" << std::endl;

  try
  {
    AForm *sForm1 = new RobotomyRequestForm();
    std::cout << *sForm1 << std::endl;

	Bureaucrat b1("Office1", 45);
    AForm *sForm2 = new RobotomyRequestForm("Target1");
    std::cout << *sForm2 << std::endl;

	b1.signForm(*sForm2);
	b1.executeForm(*sForm2);

	Bureaucrat b2("Office2", 72);
    AForm *sForm3 = new RobotomyRequestForm("Target2");
    std::cout << *sForm3 << std::endl;
	b2.executeForm(*sForm3);

	b2.signForm(*sForm3);
	b2.executeForm(*sForm3);

	delete sForm1;
	delete sForm2;
	delete sForm3;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}
