/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 12:44:32 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
  std::cout << "===== Test Form contructor =====" << std::endl;
  std::cout << "===== Try 1 =====" << std::endl;
  try
  {
    Form f1;
    std::cout << f1 << std::endl;
    Form f2("form2", 150, 150);
    std::cout << f2 << std::endl;
    Form f3("form3", 150, 0);
    std::cout << f3 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "===== Try 2 =====" << std::endl;
  try
  {
    Form f3("form3", 151, 1);
    std::cout << f3 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // Test signed
  std::cout << "===== Test succuessfully signed =====" << std::endl;

  std::cout << "===== Try 3 =====" << std::endl;
  try
  {
    Bureaucrat b1("office1", 2);
    Form f1("form1", 3, 5);

    b1.signForm(f1);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "===== Try 4 =====" << std::endl;
  try
  {
    Bureaucrat b1("office1", 2);
    Form f1("form1", 2, 5);

    b1.signForm(f1);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "===== Test NOT succuessfully signed =====" << std::endl;

  std::cout << "===== Try 5 =====" << std::endl;
  try
  {
    Bureaucrat b1("office1", 2);
    Form f1("form1", 1, 5);

    b1.signForm(f1);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}
