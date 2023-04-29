/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:54:47 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/02 20:55:48 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str2 || !str1)
		return ;
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s1) - 4;
	while (s1[l])
	{
		if (s1[l] == s2[i])
		{
			l++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
