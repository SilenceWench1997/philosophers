/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:53 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 19:55:43 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	isnum(char *arg)
{
	if (*arg == '0')
	{
		ft_putstr_fd("Argument should not be 0\n", 2);
		return (0);
	}
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
		{
			ft_putstr_fd("Argument Should be Numeric\n", 2);
			return (0);
		}
		arg++;
	}
	return (1);
}

int	check_args(int number_arg, char **args, char *save)
{
	if (number_arg < 5 || number_arg > 6)
	{
		ft_putstr_fd("Wrong Number of Arguments\n", 2);
		return (0);
	}
	args++;
	while (*args != NULL)
	{
		if (isnum(*args) == 0)
			return (0);
		else if (ft_atoi(*args) == -1)
		{
			ft_putstr_fd("Argument is too Big\n", 2);
			return (0);
		}
		else if (!(**args))
		{
			ft_putstr_fd("Argument Should not be Empty\n", 2);
			return (0);
		}
		args++;
	}
	args = &save;
	return (1);
}

void	add_info(t_info *start_info, char **argv)
{
	int	i;

	i = 0;
	argv++;
	while (*argv && argv)
	{
		if (i == 0)
			start_info->num_of_phil = ft_atoi(*argv);
		else if (i == 1)
			start_info->time_to_die = ft_atoi(*argv);
		else if (i == 2)
			start_info->time_to_eat = ft_atoi(*argv);
		else if (i == 3)
			start_info->time_to_sleep = ft_atoi(*argv);
		else if (i == 4)
			start_info->num_of_meals = ft_atoi(*argv);
		argv++;
		i++;
	}
	start_info->start = get_time();
	if (i == 4)
		start_info->num_of_meals = (-1);
}
