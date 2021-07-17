/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   grave.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/17 14:59:51  /  2021/07/17 15:06:38 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_check(t_param *param, t_philo *philo)
{
	t_time time;

	while (param->allalive)
	{
		philo = param->philo;
		gettimeofday(&time, NULL);
		while (philo)
		{
			if ((gettime(philo->timestamp) - gettime(time)) > param->timetodie)
			{
				pthread_mutex_lock(param->mut_canwritealive);
				param->allalive = 0;
			}
			philo = philo->next;
			usleep(100);
		}
	}
}

void	*death(void *param_ptr)
{
	t_param *param;
	t_philo *philo_ptr;

	param = (t_param *)param_ptr;
	philo_ptr = param->philo;
	gettimeofday(&param->timestamp, NULL);
	while (philo_ptr)
	{
		philo_ptr->timestamp = param->timestamp;
		philo_ptr = philo_ptr->next;
	}
	param->allalive = 1;
	death_check(param, philo_ptr);
	return (NULL);
}

int	grave(t_param *param)
{
	pthread_create(&param->deadcheck, NULL, death, param);
	pthread_join(param->deadcheck, NULL);
	return (OK);
}