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
//#include <stdio.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strjoin(char *rescuedbuff, char *buff)
{
	char			*new;
	unsigned int	top_len;

	if (!rescuedbuff)
	{
		rescuedbuff = malloc(1);
		*rescuedbuff = '\0';
	}
	if (!rescuedbuff || !buff)
		return (NULL);
	top_len = ft_strlen(rescuedbuff) + ft_strlen(buff);
	new = malloc(top_len);
	if (!new)
		return (NULL);
	while (*rescuedbuff)
		*(new++) = *(rescuedbuff++);
	while (*buff)
		*(new++) = *(buff++);
	*new = '\0';
	return (new - top_len);
}

static char	*ft_rescue(char *rescuedbuff)
{
	int		top_len;
	char	*new;

	while (*rescuedbuff && *rescuedbuff != '\n')
		rescuedbuff++;
	if (!(*rescuedbuff))
		return (NULL);
	top_len = ft_strlen(rescuedbuff + 1);
	new = malloc(top_len);
	if (!new)
		return (NULL);
	rescuedbuff++;
	while (*rescuedbuff)
		*(new++) = *(rescuedbuff++);
	*new = '\0';
	return (new - top_len);
}

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*new;
	static char	*rescuedbuff;
	int			i;

	new = malloc(0);
	if (!new)
		return (NULL);
	i = 1;
	while (!ft_strchr(rescuedbuff, '\n') && i != 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buff[i] = '\0';
		rescuedbuff = ft_strjoin(rescuedbuff, buff);
	}
	new = ft_get_line(rescuedbuff);
	rescuedbuff = ft_rescue(buff);
	return (new);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("text", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
