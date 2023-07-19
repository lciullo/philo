/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:40:00 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/19 16:27:04 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

enum {
	FAILURE = -1,
	SUCCESS = 1,
};

typedef struct s_philo {
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_philo_must_eat;
}	t_philo;

void    init_struct(t_philo *data);

int		ft_isdigit(int c);

int		ft_atoi(const char *str);

void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *str);

int		parsing_arg(int ac, char **av);

#endif