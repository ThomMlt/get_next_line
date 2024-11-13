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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			read_byte;

	str = NULL;
	read_byte = 1;
	if (is_new_line(buffer) == 1)
	{
		delete_old_line(buffer);
		str = ft_strjoin_gnl(str, buffer);
	}
	while (read_byte > 0 && is_new_line(buffer) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte <= 0)
		{
			if (str && str[0] != '\0' && read_byte == 0)
				return (str);
			return (free(str), NULL);
		}
		buffer[read_byte] = '\0';
		str = ft_strjoin_gnl(str, buffer);
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