/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:31:31 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/19 15:34:47 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>
#include <unistd.h>

int	check_args(char argv[], int *arg)
{
	int	i;
	int	counter;
	int	space_counter;

	i = 0;
	counter = 0;
	space_counter = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			arg[counter] = argv[i] - 48;
			//preenche o array
			counter++;
		}
		if (argv[i] == ' ')
			space_counter++;
		i++;
	}
	//checa se o input foi exatamente da maneira como era esperado
	if (counter != 16 || i != 31 || space_counter != 15)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	argc_error(int argc)
{
	//checa se o numero de argumentos esta correto
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	
	t_Game	game;
	char	final_towers[16]; // array com o resultado correto
	int		*arg;

	arg = malloc(sizeof(int) * 16); // array que vai receber o input
	init_array(final_towers, 16);// adiciona 0 em todo o array
	if (argc_error(argc))
		return (1);
	if (check_args(argv[1], arg))
		return (1);
	//checa os argumentos
	init_game(&game, arg); //inicializa o tabuleiro
	print_game_verb(game);
	eval_towers(&game); 
	print_game_verb(game);
	// avalia quais as possiveis alturas para cada torre
	if (assign_towers(&game, final_towers))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_game(final_towers);
	return (0);
}
