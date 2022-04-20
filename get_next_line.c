/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:18:32 by ykuru             #+#    #+#             */
/*   Updated: 2022/04/03 20:18:33 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <stdio.h>

static char	*rescuedbuff;
char	*new;
char	buff[BUFFER_SIZE];

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_join_up_to_chr(char *old, char *buff, int c)
{
	unsigned int	top_len;
	char			*new;

	if (!old || !buff)
		return (NULL);
	top_len = ft_strlen(old) + ft_strlen(buff);
	new = malloc(top_len);
	if (!new)
		return (NULL);
	while (*old)
		*(new++) = *(old++);
	while (*buff && *buff != c)
		*(new++) = *(buff++);
	return (new - top_len);
}

char	*ft_rescue(char *rescuedbuff,char *buff, int c)
{
	unsigned int	top_len;
	char			*new;

	if (!old || !buff)
		return (NULL);
	top_len = ft_strlen(old) + ft_strlen(buff);
	new = malloc(top_len);
	if (!new)
		return (NULL);
	while (*old)
		*(new++) = *(old++);
	while (*buff && *buff != c)
		*(new++) = *(buff++);
	return (new - top_len);
	while (*buff)
	{
		if(*buff == '\n' && *(buff + 1))
			return (buff + 1);
		buff++;
	}
	return (NULL);
}

//static int	ft_is_the_next_line(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		while (buff[i] == '\n' && i < BUFFER_SIZE)
		{
			rescuedbuff
		}
		else
		{
		}
	}
	return (new);
}

char	*get_next_line(int fd)
{

	new = malloc(0);
	new = ft_join_up_to_chr(new, rescuedbuff, '\0');
	read(fd, buff, BUFFER_SIZE);
	while (ft_is_the_next_line(buff))
	{
		new = ft_join_up_to_chr(new, buff, '\0');
		read(fd, buff, BUFFER_SIZE);
	}
	new = ft_join_up_to_chr(new, buff, '\n');
	rescuedbuff = ft_rescue(rescuedbuff, buff, '\0');
	return (new);
}

int	main(void)
{
	int	fd;
	
	fd = open("text", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
