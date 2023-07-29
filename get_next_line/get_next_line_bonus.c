/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:53:09 by ykuru             #+#    #+#             */
/*   Updated: 2022/05/25 12:53:10 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rescue(char *rescuedbuff)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (rescuedbuff[i] != '\0' && rescuedbuff[i] != '\n')
		i++;
	if (!rescuedbuff[i])
	{
		free(rescuedbuff);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(rescuedbuff) - i));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (rescuedbuff[i + j] != '\0')
	{
		new[j] = rescuedbuff[j + i];
		j++;
	}
	new[j] = '\0';
	free(rescuedbuff);
	return (new);
}

char	*anametinbulucu(char *rescuedbuff)
{
	int		i;
	char	*new;

	i = 0;
	if (!rescuedbuff[i])
		return (NULL);
	while (rescuedbuff[i] && rescuedbuff[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (rescuedbuff[i] && rescuedbuff[i] != '\n')
	{
		new[i] = rescuedbuff[i];
		i++;
	}
	if (rescuedbuff[i] == '\n')
	{
		new[i] = rescuedbuff[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*rescuedbuff[10000];
	int			ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ctrl = 1;
	while (!ft_strchr(rescuedbuff[fd], '\n') && ctrl != 0)
	{
		ctrl = read(fd, buff, BUFFER_SIZE);
		if (ctrl == -1)
		{
			free(buff);
			return (0);
		}
		buff[ctrl] = '\0';
		rescuedbuff[fd] = ft_strjoin(rescuedbuff[fd], buff);
	}
	free(buff);
	buff = anametinbulucu(rescuedbuff[fd]);
	rescuedbuff[fd] = ft_rescue(rescuedbuff[fd]);
	return (buff);
}
