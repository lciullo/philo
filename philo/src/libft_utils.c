/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:58:58 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/06 14:26:10 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	return (FAILURE);
}

int	ft_atoi(const char *str)
{
	long int		result;

	result = 0;
	if (!str)
		return (FAILURE);
	if (ft_strlen(str) > 10)
		return (FAILURE);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + *str++ - '0';
			if (result > 2147483647)
				return (FAILURE);
		}
		else
			return (FAILURE);
	}
	return ((int)(result));
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nb_elements, size_t size)
{
	void	*ptr;

	if (!nb_elements || !size)
		return (malloc(0));
	if (size != 0 && nb_elements > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nb_elements * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb_elements * size);
	return (ptr);
}
