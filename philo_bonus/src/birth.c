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
/*   birth.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/17 22:27:54  /  2021/07/17 22:27:59 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(t_param *param, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->next = NULL;
	philo->param = param;
	return (philo);
}

int	alloc_philo(t_param *param)
{
	int		ptr;
	t_philo	*philo_ptr;

	param->philo = new_philo(param, 0);
	philo_ptr = param->philo;
	if (!philo_ptr)
		return (ERROR);
	ptr = 1;
	while (ptr < param->numofphilo)
	{
		philo_ptr->next = new_philo(param, ptr);
		if (!philo_ptr)
			return (ERROR);
		philo_ptr = philo_ptr->next;
		ptr++;
	}
	return (OK);
}

int	mutex_philo(t_param *param)
{
	t_philo	*philo_ptr;

	philo_ptr = param->philo;
	while (philo_ptr)
	{
		philo_ptr->right = malloc(sizeof(t_mutex));
		if (!philo_ptr->right || pthread_mutex_init(philo_ptr->right, NULL))
			return (ERROR);
		if (philo_ptr->next)
			philo_ptr->next->left = philo_ptr->right;
		else
			param->philo->left = philo_ptr->right;
		philo_ptr = philo_ptr->next;
	}
	param->mut_canwritealive = malloc(sizeof(t_mutex));
	if (pthread_mutex_init(param->mut_canwritealive, NULL))
		return (ERROR);
	return (OK);
}

int	birth(t_param *param)
{
	if (alloc_philo(param))
		return (wrt_err("Malloc Error!"));
	if (mutex_philo(param))
		return (wrt_err("Mutex Error!"));
	return (OK);
}
