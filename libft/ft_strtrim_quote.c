/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:38:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:47:38 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_quote(char *s)
{
	int		i;
	char	*str;
	int		len;
	int		e;
	int		b;

	if (s == NULL)
		return (NULL);
	b = 0;
	e = 0;
	i = 0;
	len = ft_strlen(s) - 1;
	while (i < len && (b != 1 || e != 1))
	{
		if (s[i] != '"' && s[i] != '\'')
			b = 1;
		if (s[len] != '"' && s[len] != '\'')
			e = 1;
		if ((s[i] == '"' || s[i] == '\'') && b != 1)
			i++;
		if ((s[len] == '"' || s[len] == '\'') && e != 1)
			len--;
	}
	str = ft_strsub(s, i, len - i + 1);
	return (str);
}
