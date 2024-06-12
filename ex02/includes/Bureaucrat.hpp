/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:25 by llai              #+#    #+#             */
/*   Updated: 2024/06/12 20:09:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class AForm;

class Bureaucrat
{
 public:
  Bureaucrat(void);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  void signForm(AForm &form);
  void executeForm(AForm const &form) const;

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

 private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif  // !BUREAUCRAT_HPP
