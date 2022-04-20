#define BUFFER_SIZE 2
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtochrjoin(char *s1, char *s2, int c)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0 && s2[j] != c)
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = 0;
	return (new);
}

int	get_next_line_utils(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
		{
			printf("alt satir buldum :) Yerim Seni :******* \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main()
{
	char	buff[BUFFER_SIZE];
	char	*new;
	int	fd;

	fd = open("text", O_RDONLY);
	read(fd, buff, BUFFER_SIZE);
	while (get_next_line_utils(buff))
	{
		printf("%s", buff);
		new = ft_strtochrjoin(new, buff, '\0');
		read(fd, buff, BUFFER_SIZE);
	}
}