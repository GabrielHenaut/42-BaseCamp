/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:36:58 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/18 14:06:57 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_possible_col(const char **g_combination, char *possible, int col)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (g_combination[i] != NULL)
	{
		k = 0;
		while (k < 4)
		{
			if (possible[k] == g_combination[i][col])
			{
				break ;
			}
			k++;
		}
		if (k == 4)
		{
			possible[j] = g_combination[i][col];
			j++;
		}
		i++;
	}
}

void	remove_not_possible(char *possible, char *tower)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * 5);
	str = "1234\0";
	while (str[i] != '\0')
	{
		if (in_possible(str[i], possible))
		{
			i++;
			continue ;
		}
		else
		{
			remove_possibillity(tower, str[i]);
		}
		i++;
	}
}

void	merge_possible(char *a, char *b, char *final)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i] == b[j] && a[i] != '0')
			{
				final[count] = a[i];
				count++;
			}
			j++;
		}
		i++;
	}
}

void	eval_tower(char *tower, t_Game *game, int row, int col)
{
	char	possible_col[4];
	char	possible_row[4];
	char	final[4];

	init_array(possible_row, 4);
	init_array(possible_col, 4);
	init_array(final, 4);
	//preencher o array para nao ter problema de memoria
	ft_possible_col(g_combination[game->pairs[col]], possible_col, row);
	ft_possible_col(g_combination[game->pairs[row + 4]], possible_row, col);
	merge_possible(possible_col, possible_row, final);
	remove_not_possible(final, tower);
}

void	eval_towers(t_Game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			eval_tower(game->towers[col][row], game, row, col);
			col++;
		}
		row++;
	}
}
