/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:00:38 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/18 03:25:59 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void	print_game(char *final_towers)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		j = 0;
		counter = 0 + i;
		while (j < 4)
		{
			write(1, &final_towers[counter], 1);
			counter += 4;
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
