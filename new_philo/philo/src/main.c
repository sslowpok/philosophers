/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:49:48 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/20 14:44:05 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
}

int	main(int argc, char **argv)
{
	t_table	table;
	
	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &table.input);
	init_philos(&table);
	init_forks(&table);
	// init_threads(&table);

	free_philo(&table);
	return (0);
}