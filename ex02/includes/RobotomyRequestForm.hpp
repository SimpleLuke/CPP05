/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:21:35 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:25:35 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &);
  ~RobotomyRequestForm();

  std::string getTarget(void) const;

  void executeDetail(void) const;

 private:
  std::string _target;
};

#endif  // !ROBOTOMYREQUESTFORM_HPP
