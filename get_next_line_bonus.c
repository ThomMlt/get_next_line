/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:59 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/14 17:06:17 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*str;
	int			read_byte;

	str = NULL;
	read_byte = 1;
	if (is_new_line(buffer[fd]) == 1)
	{
		delete_old_line(buffer[fd]);
		str = ft_strjoin_gnl(str, buffer[fd]);
	}
	while (read_byte > 0 && is_new_line(buffer[fd]) == 0)
	{
		read_byte = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_byte <= 0 || valid_input(fd) == 0)
		{
			if (str && str[0] != '\0' && read_byte == 0)
				return (str);
			return (free(str), NULL);
		}
		buffer[fd][read_byte] = '\0';
		str = ft_strjoin_gnl(str, buffer[fd]);
	}
	return (str);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }