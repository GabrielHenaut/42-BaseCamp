/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:40:18 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/18 00:59:15 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rush.h"

void print_game_verb(t_Game game)
{
    printf("    ");
    for(int i = 0; i < 4; i++)
        printf("  %d  ", game.col_up[i]);
    printf("\n");
        
    for(int i = 0; i < 4; i++){
        printf("%d | ", game.row_left[i]);
        for(int j = 0; j<4; j++){
            printf("%s ", game.towers[j][i]);
        }
        printf("| %d", game.row_right[i]);
        printf("\n");
    }
    
    printf("    ");
    for(int i = 0; i < 4; i++)
        printf("  %d  ", game.col_down[i]);
    printf("\n");
}
