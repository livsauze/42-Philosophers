/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:00:11 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/07 18:14:08 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				philos_nb;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				stop;
	int				max_meal;
	int				full;
	long long		start_time;
	pthread_mutex_t	time_m;
	pthread_mutex_t	meal_m;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	write_m;
}		t_data;

typedef struct s_philo
{
	t_data			*p_data;
	unsigned int	philo_id;
	long long		last_eat;
	int				meal_count;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	pthread_t		thread;
	pthread_t		die;
}		t_philo;

typedef struct s_p
{
	t_data	data;
	t_philo	*ph;
}		t_p;

/* **********************************ERRORS********************************** */
int			ft_errors(int ac, char **av);

/* **********************************INIT************************************ */
void		ft_init_data(char **av, int ac, t_p *p);

/* *********************************ROUTINE********************************** */
void		ft_start_routine(t_p *p);

/* **********************************DEATH*********************************** */
int			ft_is_dead(t_philo *ph);
int			ft_check_death(t_philo *philo, int flag);
void		*ft_death(void	*arg);
void		*ft_stop(t_philo *ph);

/* **********************************UTILS*********************************** */
long long	ft_get_time(void);
long		ft_atol(char *str);
int			ft_isdigit(int c);
void		ft_exit(char *s);
void		ft_usleep(long long int time, t_philo *ph);
void		ft_write(char *s, t_philo *ph);

#endif