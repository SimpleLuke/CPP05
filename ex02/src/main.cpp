/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 13:07:40 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
  std::cout << "===== Test ShrubberyCreationForm =====" << std::endl;

  try
  {
    std::cout << "===== Case 1 =====" << std::endl;
    AForm *sForm1 = new ShrubberyCreationForm();
    Bureaucrat b("Office", 1);
    std::cout << *sForm1 << std::endl;
    b.signForm(*sForm1);
    b.executeForm(*sForm1);

    std::cout << "===== Case 2 =====" << std::endl;
    Bureaucrat b1("Office1", 1);
    AForm *sForm2 = new ShrubberyCreationForm("Target1");
    std::cout << *sForm2 << std::endl;

    b1.signForm(*sForm2);
    b1.executeForm(*sForm2);

    std::cout << "===== Case 3 =====" << std::endl;
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
  std::srand(time(NULL));
  try
  {
    std::cout << "===== Case 1 =====" << std::endl;
    AForm *sForm1 = new RobotomyRequestForm();
    Bureaucrat b("Office", 45);
    std::cout << *sForm1 << std::endl;
    b.signForm(*sForm1);
    b.executeForm(*sForm1);

    std::cout << "===== Case 2 =====" << std::endl;
    Bureaucrat b1("Office1", 45);
    AForm *sForm2 = new RobotomyRequestForm("Target1");
    std::cout << *sForm2 << std::endl;

    b1.signForm(*sForm2);
    b1.executeForm(*sForm2);

    std::cout << "===== Case 3 =====" << std::endl;
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

  std::cout << "===== Test PresidentialPardonForm =====" << std::endl;

  try
  {
    std::cout << "===== Case 1 =====" << std::endl;
    AForm *sForm1 = new PresidentialPardonForm();
    Bureaucrat b("Office", 5);
    std::cout << *sForm1 << std::endl;
    b.signForm(*sForm1);
    b.executeForm(*sForm1);

    std::cout << "===== Case 2 =====" << std::endl;
    Bureaucrat b1("Office1", 5);
    AForm *sForm2 = new PresidentialPardonForm("Target1");
    std::cout << *sForm2 << std::endl;

    b1.signForm(*sForm2);
    b1.executeForm(*sForm2);

    std::cout << "===== Case 3 =====" << std::endl;
    Bureaucrat b2("Office2", 25);
    AForm *sForm3 = new PresidentialPardonForm("Target2");
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
