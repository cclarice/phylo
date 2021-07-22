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
/*   utils_time.c                             cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/17 23:38:07  /  2021/07/17 23:39:24 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettime(t_time timestamp)
{
	int		time_ms;
	t_time	time;

	gettimeofday(&time, NULL);
	time_ms = ((time.tv_sec - timestamp.tv_sec) * 1000)
		+ ((time.tv_usec - timestamp.tv_usec) / 1000);
	return (time_ms);
}

int	sleepto(t_time timestamp, int sleeptime)
{
	int	until;

	until = gettime(timestamp) + sleeptime;
	while (until > gettime(timestamp))
		usleep(275);
	return (OK);
}
