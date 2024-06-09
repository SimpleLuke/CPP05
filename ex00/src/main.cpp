/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/09 20:28:27 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Bureaucrat.hpp"

int main(void)
{
  Bureaucrat b1("office1", 150);
  Bureaucrat b3("office3", 1);

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
    b1.decrementGrade();
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // Grade too high
  std::cout << "===== Test Grade too high =====" << std::endl;
  try
  {
    b3.decrementGrade();
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

  std::cout << b1 << std::endl;
  std::cout << b3 << std::endl;
}
