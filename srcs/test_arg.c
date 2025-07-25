/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:03 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/23 15:31:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_test_arg(int ac, char **av)
{
	if (ac != 5)
	{
		ft_printf("Error\nWrong number argument\n");
		exit(1);
	}
	int	i;

	i = 0;
	while(av[i])
	{
		if(av[i][0] == '\0')
		{
			ft_printf("Error\nEmpty arguement\n");
			exit(1);
		}
		i++;
	}
}