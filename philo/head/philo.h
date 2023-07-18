/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:40:00 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/18 01:31:34 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

enum {
	FAILURE = -1,
	SUCCESS = 1,
};

void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *str);

int		parsing_arg(int ac, char **av);

#endif