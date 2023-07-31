/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:31:07 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/31 15:57:42 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_routine(t_single *philo, char *action)
{
	long	current_time;

	current_time = 0;
	current_time = get_time(&philo->shared->time_start_prog);
	if (ft_strcmp("EAT", action) == 0)
		printf("%ld %d is eating\n", current_time, philo->id);
	else if (ft_strcmp("THINK", action) == 0)
		printf("%ld %d is thinking\n", current_time, philo->id);
	else if (ft_strcmp("FORK", action) == 0)
		printf("%ld %d has taken a fork\n", current_time, philo->id);
	else if (ft_strcmp("SLEEP", action) == 0)
		printf("%ld %d is sleeping\n", current_time, philo->id);
	return (SUCCESS);
}
