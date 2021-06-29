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
/*   Created/Updated: 2021/06/30 01:15:14  /  2021/06/30 01:15:59 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

suseconds_t	get_time(t_phl *phl)
{
	struct timeval	time;
	unsigned long	dif;
	unsigned int	p;

	gettimeofday(&time, NULL);
	p = 0;
	while (p != phl->n0phl)
	{
		dif = ((time.tv_sec - phl->phls[p].time.tv_sec) * 1000 +
				(time.tv_usec - phl->phls[p].time.tv_usec) / 1000);
		if (dif > phl->t2die)
		{
			pthread_mutex_lock(&phl->mwrt);
			s_die(((time.tv_sec - phl->time.tv_sec) * 1000 +
			(time.tv_usec - phl->time.tv_usec) / 1000), p + 1, phl);
			return (0);
		}
		p++;
	}
	return ((time.tv_sec - phl->time.tv_sec) * 1000 +
			(time.tv_usec - phl->time.tv_usec) / 1000);
}

void	philo_eat(t_elm	*elm, t_phl *p)
{
	pthread_mutex_lock(&p->mfrk[elm->fid[0]]);
	if (p->n0phl >= 2)
		pthread_mutex_lock(&p->mfrk[elm->fid[1]]);
	p->frks[elm->fid[0]] = 0;
	s_frk(get_time(p), elm->id, p);
	if (p->n0phl >= 2)
		p->frks[elm->fid[1]] = 0;
	s_frk(get_time(p), elm->id, p);
	pthread_mutex_unlock(&p->mfrk[elm->fid[0]]);
	pthread_mutex_unlock(&p->mfrk[elm->fid[1]]);
	s_eat(get_time(p), elm->id, elm, p);
	usleep(p->t2eat * 1000);
}

void	philo_sleep(t_elm	*elm, t_phl *p)
{
	pthread_mutex_lock(&p->mfrk[elm->fid[0]]);
	pthread_mutex_lock(&p->mfrk[elm->fid[1]]);
	p->frks[elm->fid[0]] = 1;
	p->frks[elm->fid[1]] = 1;
	pthread_mutex_unlock(&p->mfrk[elm->fid[0]]);
	pthread_mutex_unlock(&p->mfrk[elm->fid[1]]);
	s_slp(get_time(p), elm->id, p);
	usleep(p->t2slp * 1000);
}

void	*philo_thread(void *p_elm)
{
	t_elm	*elm;
	t_phl	*p;

	elm = (t_elm *)p_elm;
	p = elm->p;
	while (p->time.tv_usec == 0 && p->time.tv_sec == 0)
		NULL;
	gettimeofday(&elm->time, NULL);
	elm->time = p->time;
	while (elm->n0eat)
	{
		philo_eat(elm, p);
		philo_sleep(elm, p);
		if (!p->frks[elm->fid[0]] || !p->frks[elm->fid[1]])
			s_thk(get_time(p), elm->id, p);
		if (elm->n0eat != 0xffffffff)
			elm->n0eat--;
	}
	return (NULL);
}

int	all_n0eat(t_phl *phl)
{
	unsigned int p;

	p = 0;
	while (p != phl->n0phl)
	{
		if (phl->phls[p].n0eat)
			return (1);
		p++;
	}
	return (0);
}

void	philo(t_phl *phl)
{
	unsigned int p;

	p = 0;
	while (p != phl->n0phl)
	{
		gettimeofday(&phl->phls[p].time, NULL);
		pthread_create(&phl->thrd[p], NULL, philo_thread, &phl->phls[p]);
		p++;
	}
	gettimeofday(&phl->time, NULL);
	usleep(phl->t2die * 1000);
	while (phl->t2die && all_n0eat(phl))
		get_time(phl);
	p = 0;
	while (p != phl->n0phl)
	{
		phl->phls[p].n0eat = 0;
		pthread_detach(phl->thrd[p]);
		p++;
	}
}