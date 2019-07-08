/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfetoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:47:37 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 12:53:42 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_quote(const char *s, int c)
{
	int		i;
	char	quote;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char*)s + i);
		else if (s[i] == '\"' || s[i] == '\'')
		{
			quote = s[i];
			while (s[++i] != quote && s[i] != '\0')
				;
			if (s[i] == quote)
				i++;
		}
		else
			i++;
	}
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
