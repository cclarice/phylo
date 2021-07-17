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
/*   Created/Updated: 2021/07/17 15:31:46  /  2021/07/17 15:31:52 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_until_all_starts(t_philo *philo)
{
	printf("Philo %d Wait Until Start\n", philo->id);
	while (philo->param->allalive == -1)
		usleep(100);
	printf("Philo %d Started\n", philo->id);
}

void	eat(t_philo *philo)
{
	if ((philo->id % 2))
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
	}
	else
	{
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(philo->left);
	}
	printf("%d %d has taken a fork\n", gettime(philo->param->timestamp), philo->id + 1);
	printf("%d %d has taken a fork\n", gettime(philo->param->timestamp), philo->id + 1);
	printf("%d %d is eating\n", gettime(philo->param->timestamp), philo->id + 1);
	gettimeofday(&philo->timestamp, NULL);
	sleepto(philo->timestamp, philo->param->timetoeat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*life(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	sleep_until_all_starts(philo);
	while (philo->param->allalive)
	{
		eat(philo);
		printf("%d %d is sleeping\n", gettime(philo->param->timestamp), philo->id + 1);
		sleepto(philo->timestamp, philo->param->timetosleep);
		printf("%d %d is thinking\n", gettime(philo->param->timestamp), philo->id + 1);
	}
	return (NULL);
}

int thread_philo(t_param *param)
{
	t_philo *philo_ptr;

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
		if ((pthread_join(philo_ptr->thread, NULL)))
			return (ERROR);
		philo_ptr = philo_ptr->next;
	}
	return (OK);
}

int	exist(t_param *param)
{
	param->allalive = -1;
	if (thread_philo(param))
		return (wrt_err("Pthread Error!"));
	return (OK);
}
