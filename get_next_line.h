/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:39 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/06 19:23:48 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif 

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif