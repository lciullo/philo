/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:35:01 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/18 02:10:33 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	nb_of_arguments(int ac)
{
	if (ac != 6 && ac != 5)
	{
		ft_putstr_fd("Warning : wrong number of arguments\n", 2);
		ft_putstr_fd("Usage : use five or six arguments\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	parsing_arg(int ac, char **av)
{
	(void)av;
	if (nb_of_arguments(ac) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
