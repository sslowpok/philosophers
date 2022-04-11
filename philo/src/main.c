/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/11 16:35:39 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	philo_print(char *s1, char *s2, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (!s2)
		printf("%lu philo %d %s\n", get_time() - philo->starttime, philo->id, s1);
	else
		printf("%lu philo %d %s\n%lu philo %d %s\n", get_time() - philo->starttime, philo->id, s1, get_time() - philo->starttime, philo->id, s2);
	pthread_mutex_unlock(philo->print);
}

// int	sleep_think(t_philo *philo)
// {
	
// }





int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &info.input);
	init_philos(&info);
	init_forks(&info);
	

	create_threads(&info);

	return (0);
}