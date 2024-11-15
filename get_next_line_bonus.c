/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:59 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/15 12:03:25 by toto             ###   ########.fr       */
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
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	str = process_buffer(buffer[fd], str);
	while (read_byte > 0 && is_new_line(buffer[fd]) == 0)
	{
		read_byte = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_byte < 0)
			return (free(str), NULL);
		if (read_byte == 0)
		{
			if (str != NULL && str[0] != '\0')
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
// 	int fd2 = open("test5.txt", O_RDONLY);
// 	int fd3 = open("test3.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	printf("fd = fd :%s", str);
// 	str = get_next_line(fd2);
// 	printf("fd = fd2 :%s", str);
// 	str = get_next_line(fd3);
// 	printf("fd = fd3 :%s", str);
// 	str = get_next_line(fd);
// 	printf("fd = fd :%s", str);
// 	str = get_next_line(fd2);
// 	printf("fd = fd2 :%s", str);
// 	str = get_next_line(fd3);
// 	printf("fd = fd3 :%s", str);
// 	str = get_next_line(fd);
// 	printf("fd = fd :%s", str);
// 	str = get_next_line(fd2);
// 	printf("fd = fd2 :%s", str);
// 	str = get_next_line(fd3);
// 	printf("fd = fd3 :%s", str);
// 	str = get_next_line(fd);
// 	printf("fd = fd :%s", str);
// 	str = get_next_line(fd2);
// 	printf("fd = fd2 :%s", str);
// 	str = get_next_line(fd3);
// 	printf("fd = fd3 :%s", str);
// 	str = get_next_line(fd);
// 	printf("fd = fd :%s", str);
// 	str = get_next_line(fd2);
// 	printf("fd = fd2 :%s", str);
// 	str = get_next_line(fd3);
// 	printf("fd = fd3 :%s", str);
// 	free(str);
// 	close(fd);
// 	close(fd2);
// 	close(fd3);
// }