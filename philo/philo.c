/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:59:45 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/04 16:39:22 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg		shared;

	ft_bzero((void *)&shared, sizeof(t_arg));
	if (init_shared_struct(&shared) == FAILURE)
		return (FAILURE);
	if (parsing_input(&shared, ac, av) == FAILURE)
		return (FAILURE);
	if (allocated_struct_of_philo(&shared) == FAILURE)
		return (FAILURE);
	loop_struct(&shared);
	destroy_philo(&shared);
	free(shared.philo);
	return (0);
}
