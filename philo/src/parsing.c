/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:35:01 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/27 13:16:10 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	nb_of_arguments(int ac);
static int	is_valid(char **av);
static int	convert_and_check_overflow(t_arg *shared, char **av);
static int	is_valid_integer_value(t_arg *shared);

int	parsing_input(t_arg *shared, int ac, char **av)
{
	if (nb_of_arguments(ac) == FAILURE)
		return (FAILURE);
	if (is_valid(av) == FAILURE)
		return (FAILURE);
	if (convert_and_check_overflow(shared, av) == FAILURE)
	{
		printf("The digit has overflow\n");
		return (FAILURE);
	}
	if (is_valid_integer_value(shared) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	nb_of_arguments(int ac)
{
	if (ac != 6 && ac != 5)
	{
		printf("Warning : wrong number of arguments\n");
		printf("Usage : use five or six arguments\n");
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
				printf("Enter only digit without sign\n");
				return (FAILURE);
			}
			i++;
		}
		row++;
	}
	return (SUCCESS);
}

static int	convert_and_check_overflow(t_arg *shared, char **av)
{
	shared->nb_philo = ft_atoi(av[1]);
	if (shared->nb_philo == FAILURE)
		return (FAILURE);
	shared->time_to_die = ft_atoi(av[2]);
	if (shared->time_to_die == FAILURE)
		return (FAILURE);
	shared->time_to_eat = ft_atoi(av[3]);
	if (shared->time_to_eat == FAILURE)
		return (FAILURE);
	shared->time_to_sleep = ft_atoi(av[4]);
	if (shared->time_to_sleep == FAILURE)
		return (FAILURE);
	if (av[5] && ft_strcmp(av[5], "0"))
	{
		shared->nb_meals = ft_atoi(av[5]);
		if (shared->nb_meals == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_valid_integer_value(t_arg *shared)
{
	if ((shared->nb_philo <= 0) || (shared->time_to_die <= 0)
		|| (shared->time_to_eat <= 0) || (shared->time_to_sleep <= 0))
	{
		printf("Error, send digit greater than or equal to zéro\n");
		return (FAILURE);
	}
	if ((shared->time_to_die < 60) || (shared->time_to_eat < 60)
		|| (shared->time_to_sleep < 60))
	{
		printf("Warning\n");
		printf("With value bellow 60 the program might not run good\n");
	}
	return (SUCCESS);
}
