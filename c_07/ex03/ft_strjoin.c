/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:50:34 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/20 23:50:47 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen_final(char **strings, int size, int sep_length)
{
	int	final_length;
	int	i;

	final_length = 0;
	i = 0;
	while (i < size)
	{
		final_length += ft_strlen(strings[i]);
		final_length += sep_length;
		i++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		counter;
	int		full_length;

	full_length = ft_strlen_final(strs, size, ft_strlen(sep));
	string = (char *)malloc((full_length + 1) * sizeof(char));
	if (!string)
		return (0);
	i = 0;
	counter = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			string[counter++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			string[counter++] = sep[j++];
		i++;
	}
	string[counter] = '\0';
	return (string);
}
