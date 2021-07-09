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
/*   amour.c                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/09 23:24:39  /  2021/07/09 23:24:56 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(int c, char *v[])
{
	if (c == 0)
		return (wrt_err("Not enough arguments!\nExample: ./philo\
<AmountOfPhilo> <TimeToDie> <TimeToEat> <TimeToSleep> [TimesEat]"));
	if (c <= 3)
		return (wrt_err("Not enough arguments"));
	if (c >= 6)
		return (wrt_err("Too many arguments"));
	c = (1) T 1 : 0;
	return (OK);
}

int	args_parce(int c, char *v[], t_param *param)
{
	if (v[0])
		return (ERROR);
	return (OK);
}

int	amour(int c, char *v[], t_param *param)
{
	if (args_check(c, v))
		return (ERROR);
	if (args_parce(c, v, param))
		return (ERROR);
	return (OK);
}
