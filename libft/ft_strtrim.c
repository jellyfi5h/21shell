/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:09:31 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:48:39 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int bg;
	int end;

	if (s == NULL)
		return (NULL);
	bg = 0;
	end = ft_strlen(s) - 1;
	while (bg <= end)
	{
		if (s[bg] == ' ' || s[bg] == '\t' || s[bg] == '\n')
			bg++;
		if (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		if (s[bg] != ' ' && s[bg] != '\t' && s[bg] != '\n' && s[end] != ' '
				&& s[end] != '\t' && s[end] != '\n')
			break ;
	}
	if (bg > end)
		return (ft_strnew(1));
	else
		return (ft_strsub(s, bg, end + 1));
}
