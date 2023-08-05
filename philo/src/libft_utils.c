/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:58:58 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/05 16:11:38 by lciullo          ###   ########.fr       */
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
	int			i;
	size_t		len;
	long int	result;
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
