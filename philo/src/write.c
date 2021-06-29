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
/*   write.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/30 00:49:45  /  2021/06/30 01:06:15 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	s_frk(suseconds_t time, unsigned int id, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
	printf("%-10u %u has taken a fork\n", time, id);
	pthread_mutex_unlock(&phl->mwrt);
}
void	s_eat(suseconds_t time, unsigned int id, t_elm *elm, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
	gettimeofday(&elm->time, NULL);
	printf("%-10u %u is eating\n", time, id);
	pthread_mutex_unlock(&phl->mwrt);
}
void	s_slp(suseconds_t time, unsigned int id, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
	printf("%-10u %u is sleeping\n", time, id);
	pthread_mutex_unlock(&phl->mwrt);
}
void	s_thk(suseconds_t time, unsigned int id, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
	printf("%-10u %u is thinking\n", time, id);
	pthread_mutex_unlock(&phl->mwrt);
}
void	s_die(suseconds_t time, unsigned int id, t_phl *phl)
{
	printf("%-10u %u died\n", time, id);
	phl->t2die = 0;
}
