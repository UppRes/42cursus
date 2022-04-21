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

static int	ft_str_up_to_next_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static char	*ft_join_up_to_next(char *rescuedbuff, char *buff)
{
	char			*new;
	unsigned int	top_len;

	if (!rescuedbuff || !buff)
		return (NULL);
	top_len = ft_strlen(rescuedbuff) + ft_strlen(buff) + 1;
	new = malloc(top_len);
	if (!new)
		return (NULL);
	while (*rescuedbuff && *rescuedbuff != '\n')
		*(new++) = *(rescuedbuff);
	while (*buff && *buff != '\n')
		*(new++) = *(buff++);
	if (*buff || *buff == '\n')
		*new = *(buff);
	return (new - top_len);
}

// char	*ft_rescue(char *rescuedbuff,char *buff, int c)
// {
// 	unsigned int	top_len;
// 	char			*new;

// 	if (!rescuedbuff || !buff)
// 		return (NULL);
// 	top_len = ft_strlen(rescuedbuff) + ft_strlen(buff);
// 	new = malloc(top_len);
// 	if (!new)
// 		return (NULL);
// 	while (*rescuedbuff)
// 		*(new++) = *(rescuedbuff++);
// 	while (*buff && *buff != c)
// 		buff++;
// 	while ()
// 	{
// 		/* code */
// 	}

// 	return (new - top_len);
// 	while (*buff)
// 	{
// 		if(*buff == '\n' && *(buff + 1))
// 			return (buff + 1);
// 		buff++;
// 	}
// 	return (NULL);
// }

static int	ft_is_the_next_line(char *buff)
{
	int	i;

	i = 0;
	while (*buff && *buff != '\n')
		buff++;
	if (*buff == '\n')
	{

		while (buff[i])
			i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	char		*new;
	static char	*rescuedbuff;

	new = malloc(0);
	new = ft_join_up_to_next(new, rescuedbuff);
	read(fd, buff, BUFFER_SIZE);
	new = ft_join_up_to_next(new, buff);
	while (0 == ft_is_the_next_line(buff))
	{
		read(fd, buff, BUFFER_SIZE);
		new = ft_join_up_to_next(new, buff);
	}
	//rescuedbuff = malloc(ft_is_the_next_line(rescuedbuff));










	// new = malloc(0);
	// rescuedbuff = malloc(ft_is_the_next_line(buff));
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
