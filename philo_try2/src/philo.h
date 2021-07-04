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
/*   Created/Updated: 2021/07/04 04:18:15  /  2021/07/04 04:18:19 @cclarice   */
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

# define E_NEA "Error: Not enough arguments\n"
# define E_TMA "Error: Too much arguments\n"
# define E_ANN "Error: One of arguments is not unsigned number\n"
# define E_MAE "Error: Memory allocate error\n"
# define TRUE 1
# define FALSE 0
# define ERROR 1
# define OK 0

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthrd;
typedef	s_philo			t_philo;
typedef	s_param			t_param;
typedef struct timeval	t_time;

struct t_param
{
	int		timetodie;
	int		numofphilo;
	int		timetoeat;
	int		timetosleep;
	int		numofeating;
	int		allalive;
	int		flagnumeat;
	t_time	timestamp;
	t_mutex	mut_numofeating;
	t_mutex	mut_canwritealive;
	t_pthrd	deadcheck;
}

struct s_philo
{
	int		id;
	t_time	eat;
	t_mutex	right;
	t_mutex	left;
	int		count;
	t_philo	next;
	t_param	param;
}

// args.c
int args()

// utils_args.c
int	not_num(const char *str);
int	ft_atoi(const char *str);

// time_utils.c
int	gettime(t_time timestamp);
int sleepto(t_time timestamp, int sleeptime);

#endif