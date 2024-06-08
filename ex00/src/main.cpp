/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/07 17:42:19 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	b1;
	Bureaucrat	b2("office", 151);

	std::cout << b2 << std::endl;

}
