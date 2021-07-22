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
/*   Created/Updated: 2021/07/17 23:01:46  /  2021/07/17 23:02:42 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_not_eaten(t_param *param, t_philo *philo)
{
	philo = param->philo;
	if (param->numofeating == -1)
		return (TRUE);
	while (philo)
	{
		if (param->numofeating != philo->count)
			return (TRUE);
		philo = philo->next;
	}
	return (FALSE);
}

void	death_check(t_param *param, t_philo *philo)
{
	t_time	time;

	while (param->allalive && all_not_eaten(param, philo))
	{
		philo = param->philo;
		gettimeofday(&time, NULL);
		while (philo && param->allalive)
		{
			if ((gettime(philo->timestamp) - gettime(time)) > param->timetodie
				&& philo->param->numofeating != philo->count)
			{
				param->allalive = 0;
				say(philo, "died");
			}
			philo = philo->next;
			usleep(100);
		}
	}
}

void	*death(void *param_ptr)
{
	t_param	*param;
	t_philo	*philo_ptr;

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
	philo_ptr = param->philo;
	while (philo_ptr)
	{
		pthread_detach(philo_ptr->thread);
		philo_ptr = philo_ptr->next;
	}
	return (NULL);
}

int	grave(t_param *param)
{
	if (param->allalive == 0)
		return (OK);
	pthread_create(&param->deadcheck, NULL, death, param);
	pthread_join(param->deadcheck, NULL);
	return (OK);
}
