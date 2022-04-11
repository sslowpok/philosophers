/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:23:21 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/11 16:18:47 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_sleep(unsigned long ms)
{
	unsigned long	starttime;
	unsigned long	currenttime;

	starttime = get_time();
	currenttime = starttime;
	while (currenttime - starttime < ms)
	{
		currenttime = get_time();
		usleep(ms);
	}
}

