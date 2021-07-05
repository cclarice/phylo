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
/*   Created/Updated: 2021/07/04 04:17:55  /  2021/07/05 21:31:29 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettime(t_time timestamp)
{
	int		time_ms;
	t_time	time;

	gettimeofday(&time, NULL);
	time_ms = ((time.tv_sec - timestart.tv_sec) * 1000)
			+ ((time.tv_usec - timestart.tv_usec) / 1000);
	return (time_ms);
}

int sleepto(t_time timestamp, int sleeptime)
{
	int	until;

	until = gettime(timestamp); + sleeptime;
	while (until > gettime(timestart))
		usleep(100);
	return (OK);
}
