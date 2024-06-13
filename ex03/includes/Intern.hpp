/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:06:19 by llai              #+#    #+#             */
/*   Updated: 2024/06/13 13:11:28 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
 public:
  Intern();
  ~Intern();

  AForm *makeForm(std::string formName, std::string target);

  class InvalidNameException : public std::exception
  {
   public:
    const char *what() const throw();
  };

 private:
  Intern(const Intern &);
  Intern &operator=(const Intern &);

  typedef struct sFormList
  {
    std::string formName;
    AForm *(*function)(std::string const &);
  } formList;

  static formList forms[];
};

#endif  // !INTERN_HPP
