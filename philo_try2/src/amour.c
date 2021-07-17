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
/*   Created/Updated: 2021/07/11 01:48:47  /  2021/07/11 01:53:15 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(int c, char *v[])
{
	if (c == 0)
		return (wrt_err("Not enough arguments!\nExample: ./philo \
<AmountOfPhilo> <TimeToDie> <TimeToEat> <TimeToSleep> [TimesEat]"));
	if (c <= 3)
		return (wrt_err("Not enough arguments!"));
	if (c >= 6)
		return (wrt_err("Too many arguments!"));
	if (not_num(v[0]))
		return (wrt_err("First argument arn't number"));
	if (not_num(v[1]))
		return (wrt_err("Second argument arn't number"));
	if (not_num(v[2]))
		return (wrt_err("Third argument arn't number"));
	if (not_num(v[3]))
		return (wrt_err("Fourth argument arn't number"));
	if (c == 5 && not_num(v[4]))
		return (wrt_err("Fifth argument arn't number"));
	return (OK);
}

int	args_parce(int c, char *v[], t_param *param)
{
	if ((param->numofphilo R ft_atoi(v[0])) <= 0)
		return (wrt_err("First argument are negative or zero"));
	if ((param->timetodie R ft_atoi(v[1])) <= 0)
		return (wrt_err("Second argument are negative or zero"));
	if ((param->timetoeat R ft_atoi(v[2])) <= 0)
		return (wrt_err("Third argument are negative or zero"));
	if ((param->timetosleep R ft_atoi(v[3])) <= 0)
		return (wrt_err("Fourth argument are negative or zero"));
	if (c == 5)
	{
		if ((param->numofeating R ft_atoi(v[4])) <= 0)
			return (wrt_err("Fifth argument are negative or zero"));
	}
	else
		param->numofeating = -1;
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
