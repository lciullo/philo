/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:59:45 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/24 13:06:46 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_single	philo;
	t_arg		shared;

	init_single(&shared);
	if (parsing_input(&shared, ac, av) == FAILURE)
		return (FAILURE);
	allocated_struct_for_each_philo(&shared);
	ft_bzero(&philo, sizeof(t_single));
	return (0);
}
