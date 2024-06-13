/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:23:43 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 13:06:11 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request Form", 72, 45), _target("NoTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    _target = other._target;
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

std::string RobotomyRequestForm::getTarget(void) const
{
  return (this->_target);
}

void RobotomyRequestForm::executeDetail(void) const
{
	std::cout << "Drilling noisessssssssssssssss" << std::endl;

	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() << " has been failed to robotomized!" << std::endl;
}
