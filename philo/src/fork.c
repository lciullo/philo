#include "philo.h"

int	take_fork(t_single *philo)
{
	if (philo->right_fork == AVAILABLE)
	{
		philo->right_fork = UNAVAILABLE;
		philo->nb_fork++;
	}
	if (*(philo->left_fork) == AVAILABLE)
	{
		*(philo->left_fork) = UNAVAILABLE;
		philo->nb_fork++;
	}
	display_routine(philo, "FORK");
	return (SUCCESS);
}

int	put_down_fork(t_single *philo)
{
	if (philo->right_fork == UNAVAILABLE)
	{
		philo->right_fork = AVAILABLE;
		philo->nb_fork--;
	}
	if (*(philo->left_fork) == UNAVAILABLE)
	{
		*(philo->left_fork) = AVAILABLE;
		philo->nb_fork--;
	}
	return (SUCCESS);
}
