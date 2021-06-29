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
/*   Created/Updated: 2021/06/29 18:29:03  /  2021/06/29 18:29:09 @cclarice   */
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

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_elm
{
	unsigned int	t2die;
	unsigned int	n0eat;
	unsigned int	id;
	struct s_phl	*phl;
}				t_elm;

/*
	Struct Philo

	n0phl - number_of_philosophers
	t2die - time_to_die
	t2eat - time_to_eat
	t2slp - time_to_sleep
	n0eat - [number_of_times_each_philosopher_must_eat] 
*/

typedef struct s_phl
{
	unsigned int	n0phl;
	unsigned int	t2die;
	unsigned int	t2eat;
	unsigned int	t2slp;
	unsigned int	n0eat;
	unsigned int	*frks;
	t_elm			*phls;
}				t_phl;

// Philo
void	philo(t_phl *phl);


// Write
void	s_frk(unsigned int time, unsigned int phl);
void	s_eat(unsigned int time, unsigned int phl);
void	s_slp(unsigned int time, unsigned int phl);
void	s_thk(unsigned int time, unsigned int phl);
void	s_die(unsigned int time, unsigned int phl);

// Utils
void	ft_putuint(int i);
int 	ft_strlen(const char *str);
int		not_num(const char *str);
int		ft_atoi(const char *str);

#endif
