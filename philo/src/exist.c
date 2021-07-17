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
/*   exist.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/17 22:31:50  /  2021/07/17 22:31:51 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	say(t_philo *philo, char *message)
{
	int	id;

	id = philo->id + 1;
	pthread_mutex_lock(philo->param->mut_canwritealive);
	printf("%-9d %d %s\n", gettime(philo->param->timestamp), id, message);
	pthread_mutex_unlock(philo->param->mut_canwritealive);
	return (OK);
}

void	eat(t_philo *philo)
{
	if ((philo->id % 2))
	{
		pthread_mutex_lock(philo->left);
		say(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
		say(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right);
		say(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
		say(philo, "has taken a fork");
	}
	say(philo, "is eating");
	gettimeofday(&philo->timestamp, NULL);
	sleepto(philo->timestamp, philo->param->timetoeat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*life(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (philo->param->allalive == -1)
		usleep(100);
	philo->count = 0;
	while (philo->param->allalive)
	{
		if (philo->param->numofeating != -1)
			if (philo->param->numofeating == philo->count)
				return (NULL);
		eat(philo);
		philo->count++;
		say(philo, "is sleeping");
		sleepto(philo->timestamp, philo->param->timetosleep);
		say(philo, "is thinking");
	}
	return (NULL);
}

int	thread_philo(t_param *param)
{
	t_philo	*philo_ptr;

	philo_ptr = param->philo;
	while (philo_ptr)
	{
		if (pthread_create(&philo_ptr->thread, NULL, life, philo_ptr))
			return (ERROR);
		philo_ptr = philo_ptr->next;
	}
	grave(param);
	philo_ptr = param->philo;
	while (philo_ptr)
	{
		pthread_join(philo_ptr->thread, NULL);
		philo_ptr = philo_ptr->next;
	}
	param->allalive = 0;
	return (OK);
}

int	exist(t_param *param)
{
	param->allalive = -1;
	if (thread_philo(param))
		return (wrt_err("Pthread Error!"));
	return (OK);
}
