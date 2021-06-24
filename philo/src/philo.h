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
/*   philo.h                                  cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/25 00:53:08  /  2021/06/25 00:53:08 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

/*
	Program name		philo
	Turn in files		philo/
	Makefile			Yes
	Arguments			number_of_philosophers time_to_die time_to_eat
						time_to_sleep [number_of_times_each_philo_must_eat]
	External functs. 	memset, printf, malloc, free, write,
						usleep, gettimeofday, pthread_create,
						pthread_detach, pthread_join, pthread_mutex_init,
						pthread_mutex_destroy, pthread_mutex_lock,
						pthread_mutex_unlock
	Description			philosopher with threads and mutex
*/

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <pthread.h>