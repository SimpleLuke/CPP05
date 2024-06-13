/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 13:22:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/Intern.hpp"

int main(void)
{
  std::cout << "===== Test Intern =====" << std::endl;

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
