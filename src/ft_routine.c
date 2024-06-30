/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:22 by livsauze          #+#    #+#             */
/*   Updated: 2024/06/30 20:12:09 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_fork(t_philo *ph)
{
	if (ph->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&ph->l_fork);
		ft_write("has taken a fork", ph);
		pthread_mutex_lock(ph->r_fork);
		ft_write("has taken a fork", ph);
	}
	else
	{
		pthread_mutex_lock(ph->r_fork);
		ft_write("has taken a fork", ph);
		pthread_mutex_lock(&ph->l_fork);
		ft_write("has taken a fork", ph);
	}
}

void	ft_eat(t_philo *ph)
{
	ft_fork(ph);
	pthread_mutex_lock(&ph->p_data->time_m);
	ph->last_eat = ft_get_time();
	pthread_mutex_unlock(&ph->p_data->time_m);
	ft_write("is eating", ph);
	ph->meal_count++;
	ft_usleep(ph->p_data->time_to_eat, ph);		
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	*ft_dinner(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->p_data->philos_nb == 1)
	{
		ft_write("has taken a fork", ph);
		ft_usleep(ph->p_data->time_to_die, ph);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&ph->p_data->dead_m);
		if (ph->p_data->stop)
		{
			pthread_mutex_unlock(&ph->p_data->dead_m);
			return(NULL);
		}
		pthread_mutex_unlock(&ph->p_data->dead_m);
		ft_eat(ph);
		ft_write("is sleeping", ph);
		ft_usleep(ph->p_data->time_to_sleep, ph);
		ft_write("is thinking", ph);
		usleep(1000);
	}
	return (NULL);
}

void	ft_start_routine(t_p *p)
{
	int	i;

	i = 0;

	while (i < p->data.philos_nb)
	{
		p->ph[i].p_data = &p->data;
		if (pthread_create(&p->ph[i].thread, NULL, ft_dinner, &p->ph[i]) != 0)
			ft_exit("Error encountered while creatinh threads\n");
		i++;
	}
	if (pthread_create(&p->ph->die, NULL, ft_death, p->ph) != 0)
		ft_exit("Error encountered while creatinh threads\n");
	pthread_join(p->ph->die, NULL);
	i = 0;
	while (i < p->data.philos_nb)
	{
		pthread_join(p->ph[i].thread, NULL);
		i++;
	}
}
