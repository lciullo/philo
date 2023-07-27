/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/27 13:24:36 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(struct timeval *time_start_prog)
{
	struct timeval	actual_time;
	int				second_res;
	int				microsec_res;
	int				result; 

	gettimeofday(&actual_time, NULL);
	second_res = actual_time.tv_sec - time_start_prog->tv_sec;
	microsec_res = actual_time.tv_usec - time_start_prog->tv_usec;
	second_res = second_res * 1000;
	microsec_res = microsec_res / 1000;
	result = second_res + microsec_res;
	return (result);
}
