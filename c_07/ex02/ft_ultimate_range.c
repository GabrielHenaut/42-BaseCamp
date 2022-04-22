/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:06 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/20 23:47:49 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	counter;
	int	*buffer;

	size = max - min;
	counter = 0;
	buffer = malloc(size * sizeof(int));
	if (!(buffer))
	{
		*range = 0;
		return (-1);
	}
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = buffer;
	while (min < max)
	{
		buffer[counter] = min;
		counter++;
		min++;
	}
	return (size);
}
