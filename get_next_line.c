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

int	is_new_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	delete_old_line(char *buffer)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + j] != '\0')
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

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
		if (read_byte < 0)
			return (NULL);
		if (read_byte == 0)
			return (str);
		buffer[read_byte] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (str);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }