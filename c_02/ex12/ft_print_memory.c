/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:42:45 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/12 02:00:33 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ADDR_LEN 14

void	full_addr_writer(int number, int *base, int *full_addr, int i)
{
	if (number > *base - 1)
		full_addr_writer(number / *base, base, full_addr, i + 1);
	full_addr[i] = number % *base;
}

void	write_hex(int number, int char_count)
{
	int	full_addr[ADDR_LEN + 1];
	int	i;
	int	base;

	i = 0;
	base = 16;
	while (i < ADDR_LEN)
	{
		full_addr[i] = 0;
		i++;
	}
	full_addr_writer(number, &base, full_addr, 0);
	i = -1;
	while (i++ < char_count)
		write(1, &"0123456789abcdefgh"[full_addr[char_count - i]], 1);
}

void	write_printable(char *c)
{
	if (*c > 31 && *c != 127)
		write(1, c, 1);
	else
		write(1, &".", 1);
}

void	ft_print_memory_at(void *start_addr, int size, char *curr_addr)
{
	int	i;

	write_hex((int)*curr_addr, ADDR_LEN);
	write(1, &": ", 2);
	i = 0;
	while (i++ < 16)
	{
		if (start_addr + size <= (void *)(curr_addr + i - 1))
			write(1, &"  ", 2);
		else
			write_hex((char)*(curr_addr + i - 1), 1);
		if (i % 2 == 0)
			write(1, &" ", 1);
	}
	i = 0;
	while (i++ < 16)
		if (start_addr + size > (void *)(curr_addr + i - 1))
			write_printable((char *)curr_addr + i - 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*curr_addr;

	curr_addr = (char *)addr;
	while ((void *)curr_addr < (addr + size))
	{
		ft_print_memory_at(addr, size, curr_addr);
		write(1, &"\n", 1);
		curr_addr += 16;
	}
	return (addr);
}
