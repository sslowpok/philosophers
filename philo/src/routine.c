/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:00 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/11 16:28:37 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_philo *philo)
{
	// if (philo->num of meals)

	if (philo->leftfirst)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print("has taken a fork", NULL, philo);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo_print("has taken a fork", NULL, philo);
		pthread_mutex_lock(philo->left_fork);
	}
	philo_print("has taken a fork", "is eating", philo);
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_philo *philo)
{
	// usleep(1);
	if (!take_forks(philo))
		return (0);
	pthread_mutex_lock(&philo->mutex);
	philo->xate++;
	philo->lasttime = get_time();
	
	pthread_mutex_unlock(&philo->mutex);
	my_sleep(philo->input.t2eat);
	drop_forks(philo);
	return (1);
}

int	sleep_think(t_philo *philo)
{
	// if (num_meals ...)

	philo_print("is sleeping", NULL, philo);
	my_sleep(philo->input.t2sleep);
	philo_print("is thinking", NULL, philo);
	return (1);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (!eat(philo))
			break ;
		if (!sleep_think(philo))
			break ;
	}
	return (0);
}