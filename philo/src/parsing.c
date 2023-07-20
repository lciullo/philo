/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:35:01 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/20 15:58:14 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	nb_of_arguments(int ac);
static int	is_valid(char **av);
static int	convert_and_check_overflow(t_philo *data, char **av);
static int	is_valid_integer_value(t_philo *data);

int	parsing_arg(t_philo *data, int ac, char **av)
{
	if (nb_of_arguments(ac) == FAILURE)
		return (FAILURE);
	if (is_valid(av) == FAILURE)
		return (FAILURE);
	if (convert_and_check_overflow(data, av) == FAILURE)
		return (FAILURE);
	if (is_valid_integer_value(data) == FAILURE)
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

static int	convert_and_check_overflow(t_philo *data, char **av)
{
	data->arg.nb_philo = ft_atoi(av[1]);
	if (data->arg.nb_philo == FAILURE)
		return (FAILURE);
	data->arg.time_to_die = ft_atoi(av[2]);
	if (data->arg.time_to_die == FAILURE)
		return (FAILURE);
	data->arg.time_to_eat = ft_atoi(av[3]);
	if (data->arg.time_to_eat == FAILURE)
		return (FAILURE);
	data->arg.time_to_sleep = ft_atoi(av[4]);
	if (data->arg.time_to_sleep == FAILURE)
		return (FAILURE);
	if (av[5] && ft_strcmp(av[5], "0"))
	{
		data->arg.nb_meals = ft_atoi(av[5]);
		if (data->arg.nb_meals == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_valid_integer_value(t_philo *data)
{
	if ((data->arg.nb_philo <= 0) || (data->arg.time_to_die <= 0)
		|| (data->arg.time_to_eat <= 0) || (data->arg.time_to_sleep <= 0))
		return (FAILURE);
	if ((data->arg.time_to_die < 60) || (data->arg.time_to_eat < 60)
		|| (data->arg.time_to_sleep < 60))
	{
		ft_putstr_fd("Warning\n", 2);
		ft_putstr_fd("With value bellow 60 the program might not run good\n", 2);
	}
	return (SUCCESS);
}
