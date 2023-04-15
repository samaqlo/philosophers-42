/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:57:46 by astalha           #+#    #+#             */
/*   Updated: 2023/04/15 01:21:58 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_destroy(t_philo *lst_philo)
{
	sem_unlink("/print");
	sem_unlink("/forks");
	sem_close(lst_philo->infos->print);
	sem_close(lst_philo->infos->forks);
}

void	ft_lstclear(t_philo **lst_philo)
{
	t_philo	*philo;
	t_philo	*tmp;

	ft_sem_destroy(*lst_philo);
	mssleep(300);
	if (!lst_philo)
		return ;
	philo = *lst_philo;
	while (1)
	{
		if (philo->id == philo->infos->n_philos)
		{
			free(philo);
			break ;
		}
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	*lst_philo = NULL;
}
