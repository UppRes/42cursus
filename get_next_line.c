#include"get_next_line.h"

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

char	*ft_get_line(char *rescuedbuff)
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
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

// static char	*ft_strjoin(char *rescuedbuff, char *buff)
// {
// 	char			*new;
// 	unsigned int	top_len;

// 	if (!rescuedbuff)
// 	{
// 		rescuedbuff = malloc(1);
// 		*rescuedbuff = '\0';
// 	}
// 	if (!rescuedbuff || !buff)
// 		return (NULL);
// 	top_len = ft_strlen(rescuedbuff) + ft_strlen(buff);
// 	new = malloc(top_len);
// 	if (!new)
// 		return (NULL);
// 	while (*rescuedbuff)
// 		*(new++) = *(rescuedbuff++);
// 	while (*buff)
// 		*(new++) = *(buff++);
// 	*new = '\0';
// 	rescuedbuff = NULL;
// 	return (new - top_len);
// }

char	*ft_strjoin2(char *str, char *dash)
{
	char	*str2;
	int		i;
	int		j;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	str2 = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(dash)) + 1));
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			str2[i] = str[i];
	while (dash[j] != '\0')
		str2[i++] = dash[j++];
	str2[ft_strlen(str) + ft_strlen(dash)] = '\0';
	free (str);
	return (str2);
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

// static char	*ft_rescue(char *rescuedbuff)
// {
// 	int		top_len;
// 	char	*new;

// 	while (*rescuedbuff && *rescuedbuff != '\n')
// 		rescuedbuff++;
// 	if (!(*rescuedbuff))
// 		return (NULL);
// 	top_len = ft_strlen(rescuedbuff + 1);
// 	new = malloc(top_len);
// 	if (!new)
// 		return (NULL);
// 	rescuedbuff++;
// 	while (*rescuedbuff)
// 		*(new++) = *(rescuedbuff++);
// 	*new = '\0';
// 	return (new - top_len);
// }

char	*new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i++])
		new_str[j++] = str[i];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*new;
	static char	*rescuedbuff;
	int			ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ctrl = 1;
	while (!ft_strchr(rescuedbuff, '\n') && ctrl != 0)
	{
		ctrl = read(fd, buff, BUFFER_SIZE);
		if (ctrl == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ctrl] = '\0';
		rescuedbuff = ft_strjoin2(rescuedbuff, buff);
		if (!rescuedbuff)
			return (NULL);
	}
	free(buff);
	new = ft_get_line(rescuedbuff);
	rescuedbuff = new_str(rescuedbuff);
	return (new);
}

//#include <stdio.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("text", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
