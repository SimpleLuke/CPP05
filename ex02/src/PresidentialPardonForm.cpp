/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:57:27 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 21:01:42 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5), _target("NoTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src), _target(src._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::string PresidentialPardonForm::getTarget(void) const
{
  return (this->_target);
}

void PresidentialPardonForm::executeDetail(void) const
{
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
