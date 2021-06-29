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
/*   Created/Updated: 2021/06/29 17:54:53  /  2021/06/29 17:55:26 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	s_frk(unsigned int time, unsigned int phl)
{
	ft_putuint(time);
	write(1, " ", 1);
	ft_putuint(phl);
	write(1, "has taken a fork\n", 17);
}
void	s_eat(unsigned int time, unsigned int phl)
{
	ft_putuint(time);
	write(1, " ", 1);
	ft_putuint(phl);
	write(1, "is eating\n", 10);
}
void	s_slp(unsigned int time, unsigned int phl)
{
	ft_putuint(time);
	write(1, " ", 1);
	ft_putuint(phl);
	write(1, "is sleeping\n", 12);
}
void	s_thk(unsigned int time, unsigned int phl)
{
	ft_putuint(time);
	write(1, " ", 1);
	ft_putuint(phl);
	write(1, "is thinking\n", 12);
}
void	s_die(unsigned int time, unsigned int phl)
{
	ft_putuint(time);
	write(1, " ", 1);
	ft_putuint(phl);
	write(1, "died\n", 5);
}
