/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:40:00 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/02 16:18:23 by lciullo          ###   ########.fr       */
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
	UNAVAILABLE = 4,
	THINK = -2,
	FORK = -3,
	EAT = -4,
	SLEEP = -5
};

typedef struct s_arg {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				enough_eat;
	int				is_end;
	struct timeval	time_start_prog;
	pthread_mutex_t	launcher;
	pthread_mutex_t	speaker;
	pthread_mutex_t	watcher;
	t_single		*philo;
}	t_arg;

typedef struct s_single {
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*m_left_fork;
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
	struct timeval	current_time;
	t_arg			*shared;
}	t_single;

//=== Libft utils === //

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nb_elements, size_t size);

//=== Philo === //

int		init_shared_struct(t_arg *shared);
int		parsing_input(t_arg *shared, int ac, char **av);
int		allocated_struct_of_philo(t_arg *shared);
int		loop_to_init_each_philo(t_arg *shared);
int		loop_struct(t_arg *shared);
long	get_time(struct timeval *time_start_prog);
void	routine(t_single *philo);
int		display_routine(t_single *philo, int action);
void	check_death(t_single *philo);
int		eating(t_single *philo);
int		take_fork(t_single *philo);
int		enough_eat(t_single *philo);
int		put_down_fork(t_single *philo);
#endif