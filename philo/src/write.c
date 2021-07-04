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
/*   Created/Updated: 2021/07/04 01:37:09  /  2021/07/04 01:37:41 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	s_frk(suseconds_t time, unsigned int id, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
	printf("%-10u %u has taken a fork\n", time, id);
	pthread_mutex_unlock(&phl->mwrt);
}
void	s_eat(suseconds_t time, unsigned int id, t_phl *phl)
{
	pthread_mutex_lock(&phl->mwrt);
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
void	print_debug(t_phl *phl, struct timeval time)
{
	unsigned int p;

	p = 0;
	printf("Debug");
	printf("DTme: %-2ld:%-10d\n", time.tv_sec % 100, time.tv_usec);
	while (p != phl->n0phl)
	{
		printf("--------\n");
		printf("Id:   %-10u\n", phl->phls[p].id);
		printf("Time: %-2ld:%-10d\n", phl->phls[p].time.tv_sec % 100, phl->phls[p].time.tv_usec);
		printf("Fork: %-10u %-10d\n", phl->frks[phl->phls[p].fid[0]], phl->frks[phl->phls[p].fid[1]]);
		printf("FrkI: %-10u %-10d\n", phl->phls[p].fid[0], phl->phls[p].fid[1]);
		p++;
	}
	printf("--------\n");
	printf("phl->n0phl: %-10u\n", phl->n0phl);
	printf("phl->t2die: %-10u\n", phl->t2die);
	printf("phl->t2eat: %-10u\n", phl->t2eat);
	printf("phl->t2slp: %-10u\n", phl->t2slp);
	printf("phl->n0eat: %-10u\n", phl->n0eat);
	printf("phl->time : %-2ld:%-10d\n", phl->time.tv_sec % 100, phl->time.tv_usec);

}
void	s_die(struct timeval time, unsigned int id, t_phl *phl)
{
	printf("%-10lu %u died\n", ((time.tv_sec - phl->time.tv_sec) * 1000 +
			(time.tv_usec - phl->time.tv_usec) / 1000), id);
	print_debug(phl, time);
	phl->t2die = 0;
}
