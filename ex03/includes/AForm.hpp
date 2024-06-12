/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:44:46 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:11:09 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>

#include "./Bureaucrat.hpp"
class AForm
{
 public:
  AForm();
  AForm(std::string name, int signGrade, int execGrade);
  AForm(const AForm &);
  AForm &operator=(const AForm &);
  virtual ~AForm();

  class GradeTooHighException : public std::exception
  {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception
  {
   public:
    const char *what() const throw();
  };

  class NotSignedException : public std::exception
  {
   public:
    const char *what() const throw();
  };

  class NoExecException : public std::exception
  {
   public:
    const char *what() const throw();
  };

  std::string getName() const;
  int getSignGrade() const;
  int getExecGrade() const;
  bool getIsSigned() const;
  void setIsSigned(bool status);

  void beSigned(Bureaucrat &b);
  void checkForm(const Bureaucrat &b) const;
  virtual void executeDetail(void) const =0;
  void execute(Bureaucrat const &executor) const;

 private:
  const std::string _name;
  const int _signGrade;
  const int _execGrade;
  bool _isSigned;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif  // !AFORM_HPP
