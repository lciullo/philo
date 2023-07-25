#include "philo.h"

static	int	routine(t_single *philo);

int loop_for_routine(t_single *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(philo->shared->launcher));
	while (i < philo->shared->nb_philo)
	{
		routine(&(philo)[i]);
		i++;
	}
	pthread_mutex_unlock(&(philo->shared->launcher));
	return (SUCCESS);
}

static	int	routine(t_single *philo)
{
	
	printf("Philo %d is thinking\n", philo->id);

	
	return (SUCCESS);
}
