/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:56:07 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/20 14:07:12 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	input(int argc, char **argv, t_input *input)
{
	input->num = ft_atoi(argv[1]);
	input->t2die = ft_atoi(argv[2]);
	input->t2eat = ft_atoi(argv[3]);
	input->t2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->num_of_meals = ft_atoi(argv[5]);
	else
		input->num_of_meals = -1;
}