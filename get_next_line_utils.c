/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:59 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/06 19:04:01 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

int	ft_strlen_gnl(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
	{
		len++;
	}
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	free(s1);
	j = 0;
	while (s2[j] != '\n' && s2[j] != '\0')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}
