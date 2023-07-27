/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:59:45 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/27 17:30:03 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg		shared;

	ft_bzero((void *)&shared, sizeof(t_arg));
	init_shared_struct(&shared);
	if (parsing_input(&shared, ac, av) == FAILURE)
		return (FAILURE);
	allocated_struct_of_philo(&shared);
	loop_struct(&shared);
	return (0);
}
