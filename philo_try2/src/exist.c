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
/*   Created/Updated: 2021/07/11 00:21:17  /  2021/07/11 00:21:28 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	while ()
}

int thread_philo(t_param *param)
{
	t_philo *philo_ptr;

	philo_ptr = param->philo;
	while (philo_ptr)
	{
		if (pthread_create(&philo_ptr->thread, NULL, void))
			return (ERROR);
		philo_ptr = philo_ptr->next;
	}
}

int	exist(t_param *param)
{
	param
	if (thread_philo(param))
		return (wrt_err("Pthread Error!"));
	return (OK);
}
