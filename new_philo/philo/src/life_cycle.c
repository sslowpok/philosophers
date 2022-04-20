/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:48 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/20 15:26:36 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_philo *philo)
{
	
}

int	eat(t_philo *philo)
{
	

	return (1);
}

int	sleep_think(t_philo *philo)
{
	

	return (1);
}

void	*life_cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// if (philo->id % 2 != 0)
	// 	usleep(150);
	while (!philo->is_dead)
	{
		if (!eat(philo))
			break ;
		if (!sleep_think(philo))
			break ;
	}
	return (0);
}