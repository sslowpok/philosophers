/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:50:36 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/12 17:26:33 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_philo *philo)
{
	if (!count_meals(philo) && philo->input.num_of_meals > 0)
		return (0);
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

int	is_dead(t_philo *philo)
{
	unsigned long	now;

	now = get_time();
	pthread_mutex_lock(&philo->mutex);
	if (now - philo->lasttime > philo->input.t2die)
		return (1);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	detach_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input.num)
	{
		if (pthread_detach(info->philos[i].thread) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	join_all_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input.num)
	{
		if (pthread_join(info->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
