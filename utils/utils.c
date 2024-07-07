/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:15:09 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/07 17:32:31 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_exit(char *s)
{
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}

void	ft_write(char *s, t_philo *ph)
{
	long long	time;

	pthread_mutex_lock(&ph->p_data->write_m);
	pthread_mutex_lock(&ph->p_data->dead_m);
	time = ft_get_time() - ph->p_data->start_time;
	if (time >= 0 && !ph->p_data->stop)
		printf("%lld, Philo %d %s\n", time, ph->philo_id, s);
	pthread_mutex_unlock(&ph->p_data->dead_m);
	pthread_mutex_unlock(&ph->p_data->write_m);
}

void	ft_usleep(long long time, t_philo *ph)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() < start + time && !ft_is_dead(ph))
	{
		usleep(900);
	}
}

long long	ft_get_time(void)
{
	struct timeval	time;
	long long		res;

	if (gettimeofday(&time, NULL) == -1)
		exit(EXIT_FAILURE);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}
