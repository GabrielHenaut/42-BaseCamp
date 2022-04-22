/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 06:29:45 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/21 20:30:23 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*tab;
	int	counter;

	range = max - min;
	counter = 0;
	tab = 0x0000;
	if (range <= 0)
		return (tab);
	tab = malloc(range * sizeof(int));
	while (min < max)
	{
		tab[counter] = min;
		counter++;
		min++;
	}
	return (tab);
}


#include <stdio.h>

int		main(void)
{
	int	min = 0x2;
	int	max = 0x1;

	printf("%x, ", ft_range(min, max));
}