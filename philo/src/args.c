/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:05:13 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/09 11:51:47 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	str_error(char *s)
{
	write(2, s, ft_strlen(s));
	return (0);
}

static int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 2147483647 && \
			ft_strncmp(argv[i], "2147483647", 10))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}	
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (str_error("Error: wrong number of args\n"));
	if (!check_digits(argc, argv))
		return (str_error("Error: invalid argument\n"));
	if (!check_int(argc, argv))
		return (str_error("Error: invalid argument\n"));
	return (1);
}

void	input(int argc, char **argv, t_info *info)
{
	// philo->args.count = ft_atoi(argv[1]);
	// philo->args.time_to_die = ft_atoi(argv[2]);
	// philo->args.time_to_eat = ft_atoi(argv[3]);
	// philo->args.time_to_sleep = ft_atoi(argv[4]);
	// if (argc == 6)
	// 	philo->args.num_of_eat = ft_atoi(argv[5]);
	// else if (argc == 5)
	// 	philo->args.num_of_eat= -1;


	info->num = ft_atoi(argv[1]);
	info->t2die = ft_atoi(argv[2]);
	info->t2eat = ft_atoi(argv[3]);
	info->t2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_meals = ft_atoi(argv[5]);
	else
		info->num_of_meals = -1;
}
