/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:35:01 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/19 16:37:24 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	nb_of_arguments(int ac);
static int is_valid(char **av);

int	parsing_arg(int ac, char **av)
{
	if (nb_of_arguments(ac) == FAILURE)
		return (FAILURE);
	if (is_valid(av) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	nb_of_arguments(int ac)
{
	if (ac != 6 && ac != 5)
	{
		ft_putstr_fd("Warning : wrong number of arguments\n", 2);
		ft_putstr_fd("Usage : use five or six arguments\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_valid(char **av)
{
	size_t	row;
	size_t	i;
	
	row = 1;
	i = 0;
	while (av[row] != NULL)
	{
		i = 0;
		while (av[row][i] != '\0')
		{
			if (ft_isdigit(av[row][i]) == FAILURE)
			{
				ft_putstr_fd("Enter only digit without sign\n", 2);
				return (FAILURE);
			}
			i++;
		}
		row++;
	}
	return (SUCCESS);
}