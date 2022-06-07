/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:53:17 by ykuru             #+#    #+#             */
/*   Updated: 2022/05/25 12:53:18 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
