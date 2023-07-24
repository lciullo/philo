#include "philo.h"

static int  init_struct(t_single *philo, t_single *last_philo, t_arg *data);

int fill_each_philo(t_arg *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (i == 0)
			init_struct(&(data->philo)[i], NULL, data);
		else
			init_struct(&(data->philo)[i], &(data->philo)[i - 1], data);
		i++;
	}
	(data->philo)[0].left_fork = &((data->philo)[i - 1].right_fork);
	(data->philo)[0].mute_left_fork = &((data->philo)[i - 1].mute_right_fork);
	return (SUCCESS);
}

static int  init_struct(t_single *philo, t_single *last_philo, t_arg *data)
{
	philo->is_dead = FALSE;
	philo->lifespan = data->time_to_die;
	philo->nb_meals_eaten = 0;
	philo->right_fork = AVAILABLE;
	pthread_mutex_init(&(philo->mute_right_fork), NULL);
	if (last_philo != NULL)
	{	
		philo->left_fork = &(last_philo->right_fork);
		philo->mute_left_fork = &(philo->mute_right_fork);
	}
	return (SUCCESS);
}