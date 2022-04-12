/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:06:18 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/12 17:27:03 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	count_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->xate >= philo->input.num_of_meals)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (1);
}

void	philo_print(char *s1, char *s2, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (!s2)
		printf("%lu philo %d %s\n", \
		get_time() - philo->starttime, philo->id, s1);
	else
		printf("%lu philo %d %s\n%lu philo %d %s\n", \
		get_time() - philo->starttime, philo->id, s1, \
		get_time() - philo->starttime, philo->id, s2);
	pthread_mutex_unlock(philo->print);
}
