/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 12:22:52 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Bureaucrat.hpp"

int main(void)
{
  std::cout << "===== Test contructor =====" << std::endl;
  try
  {
    Bureaucrat b2("office2", 151);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    Bureaucrat b4("office4", 0);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // Grade too low
  std::cout << "===== Test Grade too low =====" << std::endl;

  try
  {
    Bureaucrat b1("office1", 149);
    std::cout << b1 << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // Grade too high
  std::cout << "===== Test Grade too high =====" << std::endl;

  try
  {
    Bureaucrat b3("office3", 3);
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << b3 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}
