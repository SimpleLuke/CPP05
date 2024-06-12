/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 21:55:37 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Intern.hpp"

int main(void)
{
  std::cout << "===== Test Intern =====" << std::endl;

  try
  {
	  Intern i;

	  AForm *form = i.makeForm("Shrubbery Creation Form", "Target");
	  delete form;

	  form = i.makeForm("Robotomy Request Form", "Target");
	  delete form;

	  form = i.makeForm("Presidential Pardon Form", "Target");
	  delete form;

	  form = i.makeForm("Unknown", "Target");
	  delete form;
  }
  catch (std::exception &e)
  {
	  std::cout << e.what() << std::endl;
  }
}
