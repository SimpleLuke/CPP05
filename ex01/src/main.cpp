/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/09 21:56:30 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
  std::cout << "===== Test Form contructor =====" << std::endl;
  try
  {
    Form f1;
    std::cout << f1 << std::endl;
    Form f2("form2", 151, 0);
    std::cout << f2 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

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
  // // Grade too high
  // std::cout << "===== Test Grade too high =====" << std::endl;
  //
  // Bureaucrat b3("office3", 3);
  // try
  // {
  //   b3.incrementGrade();
  //   std::cout << b3 << std::endl;
  //   b3.incrementGrade();
  //   std::cout << b3 << std::endl;
  //   b3.incrementGrade();
  //   std::cout << b3 << std::endl;
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }
  //
  // // Result
  // std::cout << "===== Test result =====" << std::endl;
  // std::cout << b1 << std::endl;
  // std::cout << b3 << std::endl;
}
