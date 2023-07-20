/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:14:26 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/20 15:42:40 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	size_t		len;
	long		result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	len = ft_strlen(str);
	if (len > 10)
		return (FAILURE);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result != (result * 10 + (str[i] - 48)) / 10 && sign == -1)
			return (FAILURE);
		if (result != (result * 10 + (str[i] - 48)) / 10 && sign == 1)
			return (FAILURE);
		i++;
	}
	return ((int)(result * sign));
}
