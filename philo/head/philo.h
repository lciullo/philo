/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:40:00 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/24 14:48:50 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdint.h>

typedef struct s_single t_single;

enum {
	FAILURE = -1,
	SUCCESS = 2,
	TRUE = 1,
	FALSE = 0
	
};

typedef struct s_shared {
	
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				is_end;
	int				enough_eat;
	pthread_mutex_t	launcher; //lance tous les philos en même temps
	pthread_mutex_t	gossiper; //il annonce lgoes nouvelles gossiper
	pthread_mutex_t	controller; // il check les infos 
	t_single		*philo;
}	t_arg;

typedef struct s_single {
	
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	mute_left_fork; //verrouille les fourchettes
	pthread_mutex_t	*mute_right_fork;
	int				left_fork;
	int				*right_fork;
	int				time_start_meal;
	int				time_end_meal;
	int				time_start_sleep;
	int				time_end_sleep;
	int				nb_meals_eaten;
	long int		lifespan;
	int				is_dead;
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

void	init_single(t_arg *shared);
int		parsing_input(t_arg *shared, int ac, char **av);
int		allocated_struct_for_each_philo(t_arg *shared);
#endif