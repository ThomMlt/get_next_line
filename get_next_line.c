/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:59 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/06 19:03:00 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] ;
	char		*str;
	int			len;
	
	str = NULL;
	len = 1;
	while (len > 0 && is_new_line(buffer) == 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (NULL);
		if (len == 0)
			return (NULL);
		buffer[len] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (str);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}