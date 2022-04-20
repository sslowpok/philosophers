/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:01:48 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/20 15:27:16 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(t_mutex) * table->input.num);
	if (!table->forks)
	{
		str_error("Error: malloc error.\n");
		return ;
	}
	while (i < table->input.num)
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print, NULL);
}

void	init_philos(t_table *table)
{
	int	i;

	i = -1;
	table->starttime = get_time();
	table->philos = malloc(sizeof(t_philo) * table->input.num);
	if (!table->philos)
	{
		str_error("Error: malloc error.\n");
		return ;
	}
	while (++i < table->input.num)
	{
		table->philos[i].id = i;
		table->philos[i].xate = 0;
		table->philos[i].is_dead = 0;
		// pthread_mutex_init(&table->philos[i].mutex, NULL);
		table->philos[i].left = (i + 1) % table->input.num;
		table->philos[i].right = i;
		table->philos[i].lasttime = table->starttime;
		table->philos[i].starttime = table->starttime;
	}
}

void	init_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->input.num)
	{
		if (pthread_create(&table->philos[i].thread, NULL, life_cycle, (void *)&table->philos[i]))
			return ;
		i++;
	}
	// check_dead
}