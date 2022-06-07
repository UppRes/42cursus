/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:53:29 by ykuru             #+#    #+#             */
/*   Updated: 2022/05/25 12:53:31 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char *rescuedbuff, char *buff)
{
	int		i;
	int		j;
	char	*new;

	if (!rescuedbuff)
	{
		rescuedbuff = (char *)malloc(1 * sizeof(char));
		rescuedbuff[0] = '\0';
	}
	if (!rescuedbuff || !buff)
		return (NULL);
	new = (char *)malloc(ft_strlen(rescuedbuff) + ft_strlen(buff) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (rescuedbuff[++i])
		new[i] = rescuedbuff[i];
	j = -1;
	while (buff[++j])
		new[i + j] = buff[j];
	new[i + j] = 0;
	free (rescuedbuff);
	return (new);
}
