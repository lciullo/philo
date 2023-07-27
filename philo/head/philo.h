/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:40:00 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/27 16:56:49 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>

typedef struct s_single	t_single;

enum {
	FAILURE = -1,
	SUCCESS = 2,
	TRUE = 1,
	FALSE = 0,
	AVAILABLE = 3,
	UNAVAILABLE = 4
};

typedef struct s_arg {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				is_end;
	int				enough_eat;
	struct timeval	time_start_prog;
	pthread_mutex_t	launcher; //lance tous les philos en même temps
	pthread_mutex_t	gossiper; //il annonce logs nouvelles gossiper
	pthread_mutex_t	controller; // il check les infos 
	t_single		*philo;
}	t_arg;

typedef struct s_single {
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*m_left_fork; //verrouille les fourchettes
	pthread_mutex_t	m_right_fork;
	int				*left_fork;
	int				right_fork;
	int				time_start_meal;
	int				time_end_meal;
	int				time_start_sleep;
	int				time_end_sleep;
	int				nb_meals_eaten;
	long int		lifespan;
	int				is_dead;
	int				nb_fork;
	t_arg			*shared;
}	t_single;

//=== Libft utils === //

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nb_elements, size_t size);

//=== Philo === //

void	init_shared_struct(t_arg *shared);
int		parsing_input(t_arg *shared, int ac, char **av);
int		allocated_struct_of_philo(t_arg *shared);
int		loop_to_init_each_philo(t_arg *shared);
// int		loop_struct(t_single *philo);
int		loop_struct(t_arg *shared);
int		get_time(struct timeval *time_start_prog);
#endif