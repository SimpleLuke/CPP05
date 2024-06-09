/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:44:46 by llai              #+#    #+#             */
/*   Updated: 2024/06/09 21:28:20 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

#include "./Bureaucrat.hpp"
class Form
{
 public:
  Form();
  Form(std::string name, int signGrade, int execGrade);
  Form(const Form &);
  Form &operator=(const Form &);
  ~Form();

  class GradeTooHighException : public std::exception
  {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception
  {
   public:
    virtual const char *what() const throw();
  };

  std::string getName() const;
  int getSignGrade() const;
  int getExecGrade() const;
  bool getIsSigned() const;
  void	setIsSigned(bool status);

  void beSigned(Bureaucrat &b);

 private:
  const std::string _name;
  const int _signGrade;
  const int _execGrade;
  bool _isSigned;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif  // !FORM_HPP
