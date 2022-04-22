/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:32:08 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/09 04:39:38 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{	
	char	pos;
	char	neg;

	pos = 'P';
	neg = 'N';
	if (n < 0)
		write(1, &neg, 1);
	else
		write(1, &pos, 1);
}
