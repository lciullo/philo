/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/31 14:31:53 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*printf("second res %d\n", second_res);
	printf("microsec res %d\n", microsec_res);
	printf("actual time usec %ld\n", current_time.tv_usec);
	printf("time start prog  usec%ld\n", time_start_prog->tv_usec);
	printf("actual time sec %ld\n", current_time.tv_sec);
	printf("time start prog sec %ld\n", time_start_prog->tv_sec);
	printf("================\n");
	printf("second res %d\n", second_res);
	printf("microsec res %d\n", second_res);
	*/

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
