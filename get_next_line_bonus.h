/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:39 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/14 17:06:14 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define MAX_FD 1024

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	delete_old_line(char *buffer);
int		is_new_line(char *str);
int		valid_input(int fd);

#endif