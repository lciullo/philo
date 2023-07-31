/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/31 15:07:51 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(struct timeval *time_start_prog)
{
	struct timeval		current_time;
	long				second_res;
	long				microsec_res;
	long				result; 

	gettimeofday(&current_time, NULL);
	second_res = current_time.tv_sec - time_start_prog->tv_sec;
	microsec_res = current_time.tv_usec - time_start_prog->tv_usec;
	second_res = second_res * 1000;
	microsec_res = microsec_res / 1000;
	result = second_res + microsec_res;
	return (result);
}
