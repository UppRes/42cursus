/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:52:49 by ykuru             #+#    #+#             */
/*   Updated: 2022/05/25 12:52:51 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *rescuedbuff, char *buff);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
