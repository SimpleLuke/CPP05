/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:02:30 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:12:45 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string name);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  std::string getTarget(void) const;

  void executeDetail(void) const;

 private:
  std::string _target;
};

#endif  // !SHRUBBERYCREATIONFORM_HPP
