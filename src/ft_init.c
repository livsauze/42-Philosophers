/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:27:45 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/06 11:09:12 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_mutex(t_p *p)
{
	pthread_mutex_init(&p->data.time_m, NULL);
	pthread_mutex_init(&p->data.meal_m, NULL);
	pthread_mutex_init(&p->data.write_m, NULL);
	pthread_mutex_init(&p->data.dead_m, NULL);
}

void	ft_init_philos(t_p *p)
{
	int	i;

	i = 0;
	p->ph = malloc(sizeof(t_philo) * p->data.philos_nb);
	if (p->ph == NULL)
		ft_exit("Malloc error");
	while (i < p->data.philos_nb)
	{
		p->ph[i].philo_id = i + 1;
		p->ph[i].meal_count = 0;
		p->ph[i].last_eat = p->data.start_time;
		p->ph[i].r_fork = NULL;
		pthread_mutex_init(&p->ph[i].l_fork, NULL);
		if (p->data.philos_nb - 1 == i)
			p->ph[i].r_fork = &p->ph[0].l_fork;
		else
			p->ph[i].r_fork = &p->ph[i + 1].l_fork;
		i++;
	}
}

void	ft_init_data(char **av, int ac, t_p *p)
{
	p->data.philos_nb = ft_atol(av[1]);
	p->data.time_to_die = ft_atol(av[2]);
	p->data.time_to_eat = ft_atol(av[3]);
	p->data.time_to_sleep = ft_atol(av[4]);
	p->data.stop = 0;
	p->data.full = 0;
	if (p->data.time_to_die < 60 || p->data.time_to_eat < 60
		|| p->data.time_to_sleep < 60)
		ft_exit("Do not use values lower than 60ms");
	if (ac == 6)
		p->data.max_meal = ft_atol(av[5]);
	else
		p->data.max_meal = -1;
	p->data.start_time = ft_get_time();
	ft_init_mutex(p);
	ft_init_philos(p);
}
