/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:08:12 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/09 02:20:53 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word_started;

	i = 0;
	word_started = 1;
	ft_strlowcase (str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (word_started == 1)
			{
				str[i] -= 32;
				word_started = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			word_started = 0;
		else
			word_started = 1;
		i++;
	}
	return (str);
}
