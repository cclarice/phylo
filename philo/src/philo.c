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
/*   philo.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/29 18:14:23  /  2021/06/29 18:14:32 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		all_alive(t_phl *phl)
{
	unsigned int p;

	p = phl->n0phl;
	while (p)
	{
		if (phl->phls[p - 1].t2die == 0)
			return (0);
		p--;
	}
	return (1);
}

int		all_n0eat(t_phl *phl)
{
	unsigned int p;

	p = phl->n0phl;
	while (p)
	{
		if (phl->phls[p - 1].n0eat)
			return (1);
		p--;
	}
	return (0);
}

void	*philo_thread(void *p_phl)
{
	const t_phl	*phl = (t_phl *)p_phl;

	
	return (NULL);
}

void	philo(t_phl *phl)
{
	unsigned int p;

	p = 0;
	while (p != phl->n0phl)
	{
		pthread_create(&phl->thrd[p], NULL, philo_thread, &phl);
		p++;
	}
}