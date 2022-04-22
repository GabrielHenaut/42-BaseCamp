/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:31:04 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/13 04:45:02 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_put_digit(char digit)
{
	write(1, &digit, 1);
}

void	ft_print_separator(void)
{
	write(1, ", ", 2);
}

void	printer(int *cur_number, int n)
{
	int		i;
	bool	is_prior_smaller;

	i = 1;
	is_prior_smaller = true;
	while (i < n)
	{
		if (cur_number[i - 1] >= cur_number[i])
			is_prior_smaller = false;
		i++;
	}
	if (is_prior_smaller)
	{
		i = 0;
		while (i < n)
			ft_put_digit(cur_number[i++] + 48);
		if (cur_number[0] < (10 - n))
		{
			ft_print_separator();
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		cur_number[9];

	i = 0;
	while (i < n)
		cur_number[i++] = 0;
	while (cur_number[0] <= (10 - n) && n >= 1 && n < 10)
	{
		printer(cur_number, n);
		cur_number[n - 1]++;
		i = n - 1;
		while (i && n > 1)
		{
			if (cur_number[i] > 9)
			{
				cur_number[i - 1]++;
				cur_number[i] = 0;
			}
			i--;
		}
	}
}

int main(void)
{
	ft_print_combn(5);
}
