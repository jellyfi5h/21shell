/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrlen_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfetoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 05:44:12 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 12:55:24 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrlen_quote(const char *str, int c)
{
	int		i;
	int		len;
	char	quote;

	len = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			while (str[++i] != quote && str[i] != '\0')
				;
			if (str[i] == quote)
				i++;
		}
		if (str[i] == c)
			len++;
	}
	return (len);
}
