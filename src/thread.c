/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:04:56 by rolevy            #+#    #+#             */
/*   Updated: 2017/12/14 16:57:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			*thread1_func(void *arg1)
{
	printf(MAG"THREAD1 CONNECTION" BLUE" [" GREEN"SUCSSESS" BLUE"]\n");
	(*((int*)arg1))++;
	printf (MAG"INPUT VAlUE CHANGED" BLUE" [" GREEN"SUCSSESS" BLUE"]\n");
	pthread_exit(NULL);
}

void			*thread2_func(void *arg1)
{
	printf(MAG"THREAD2 CONNECTION" BLUE" [" GREEN"SUCSSESS" BLUE"]\n");
	while (42)
	{
		(*((int*)arg1))--;
		if (*(int*)arg1 <= -10)
		{
			pthread_mutex_lock(arg1);
		}
	}
	printf (MAG"INPUT VAlUE CHANGED" BLUE" [" GREEN"SUCSSESS" BLUE"]\n");
	pthread_exit(NULL);
}

int				main(int ac, char **av)
{
/*-------------------------- INIT VALUES -------------------------------------*/

	t_thread		thread1;
	t_thread		thread2;
	pthread_mutex_t mutex		= PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t	condtion	= PTHREAD_COND_INITIALIZER; 
	int				input;
/*----------------------------------------------------------------------------*/

/*-------------------------- ASSIGN VALUES -----------------------------------*/

	input				= atoi(av[1]);
	thread1.function	= thread1_func;
	thread2.function	= thread2_func;
/*----------------------------------------------------------------------------*/

	printf(MAG"INIT" BLUE"    [" GREEN"OK" BLUE"]\n");
	printf(MAG "Input value = " BLUE"%d\n", input);
	
	if (pthread_create(&(thread1.thread), NULL, thread1.function, &input) == -1)
	{
		perror (MAG"THREAD1 " BLUE" [" RED"FAIL" BLUE"]\n");
		return (EXIT_FAILURE);
	}
	if (pthread_create(&(thread2.thread), NULL, thread2.function, &input) == -1)
	{
		perror (MAG"THREAD2 " BLUE" [" RED"FAIL" BLUE"]\n");
		return (EXIT_FAILURE);
	}

	if (pthread_join(thread1.thread, NULL))
	{
		perror (MAG"THREAD1 " BLUE" [" RED"NOT ACTIVE" BLUE"]\n");
		return (EXIT_FAILURE);
	}
	if (pthread_join(thread2.thread, NULL))
	{
		perror (MAG"THREAD2 " BLUE" [" RED"NOT ACTIVE" BLUE"]\n");
		return (EXIT_FAILURE);
	}

	printf(MAG"THREAD " BLUE" [" GREEN"SUCSSESS" BLUE"]\n");
	printf (MAG "New input value = " BLUE"%d\n", input);
	return (EXIT_SUCCESS);
}