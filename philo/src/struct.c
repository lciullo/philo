#include "philo.h"

void	init_struct(t_philo *data)
{
	data->nb_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->time_philo_must_eat = 0;
}