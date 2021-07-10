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
/*   Created/Updated: 2021/07/10 14:57:23  /  2021/07/10 16:22:01 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	temp(t_param *param)
{
	printf("numofphilo:  %-5d\n", param->numofphilo);
	printf("timetodie:   %-5d\n", param->timetodie);
	printf("timetoeat:   %-5d\n", param->timetoeat);
	printf("timetosleep: %-5d\n", param->timetosleep);
	printf("numofeating: %-5d\n", param->numofeating);
	return (OK);
}

int	main(int c, char *v[])
{
	t_param			param;

	if (amour(--c, ++v, &param))
		return (ERROR);
	temp(&param);
	if (birth(&param))
		return (ERROR);
	if (exist(&param))
		return (ERROR);
	if (grave(&param))
		return (ERROR);
	return (OK);
}
