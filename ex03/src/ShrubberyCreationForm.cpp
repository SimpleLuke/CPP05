/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:02:07 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:26:25 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation", 145, 137), _target("NoTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    _target = other._target;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget(void) const
{
  return (this->_target);
}

void ShrubberyCreationForm::executeDetail(void) const
{
  std::string filename = this->getTarget() + "_shrubbery";

  std::ofstream file(filename.c_str());

  if (!file.is_open())
  {
    std::cerr << "Error: Failed to open file " << filename << std::endl;
    return;
  }

  file << "      /\\      \n";
  file << "     /\\*\\     \n";
  file << "    /\\O\\*\\    \n";
  file << "   /*/\\/\\/\\   \n";
  file << "  /\\O\\/\\*\\/\\  \n";
  file << " /\\*\\/\\*\\/\\/\\ \n";
  file << "/\\O\\/\\/*/\\/O/\\\n";
  file << "      ||      \n";
  file << "      ||      \n";
  file << "      ||      \n";

  file.close();
}
