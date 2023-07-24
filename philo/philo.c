/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:59:45 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/24 17:28:27 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg		shared;

	init_shared_struct(&shared);
	if (parsing_input(&shared, ac, av) == FAILURE)
		return (FAILURE);
	allocated_struct_of_philo(&shared);
	return (0);
}
