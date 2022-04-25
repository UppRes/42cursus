#include "get_next_line.h"

char	*yenibaslangic(char *yenibas)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (yenibas[i] != '\0' && yenibas[i] != '\n')
		i++;
	if (!yenibas[i])
	{
		free(yenibas);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(yenibas) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (yenibas[i + j] != '\0')
	{
		str[j] = yenibas[j + i];
		j++;
	}
	str[j] = '\0';
	free(yenibas);
	return (str);
}

char	*anametinbulucu(char *yenibas)
{
	int		i;
	char	*str;

	i = 0;
	if (!yenibas[i])
		return (NULL);
	while (yenibas[i] != '\0' && yenibas[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (yenibas[i] != '\0' && yenibas[i] != '\n')
	{
		str[i] = yenibas[i];
		i++;
	}
	if (yenibas[i] == '\n')
	{
		str[i] = yenibas[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*okuma(int fd, char *yenibas)
{
	char	*metin;
	int		uzunluk;

	metin = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!metin)
		return (0);
	uzunluk = 1;
	while (!ft_strchr(yenibas, '\n') && uzunluk != 0)
	{
		uzunluk = read(fd, metin, BUFFER_SIZE);
		if (uzunluk == -1)
		{
			free(metin);
			return (NULL);
		}			
		metin[uzunluk] = '\0';
		yenibas = ft_strjoin(yenibas, metin);
	}
	free(metin);
	return (yenibas);
}

char	*get_next_line(int fd)
{
	char		*anametin;
	static char	*yenibas;

	printf("%zu",ft_strlen(anametin));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	yenibas = okuma(fd, yenibas);
	if (!yenibas)
		return (NULL);
	anametin = anametinbulucu(yenibas);
	yenibas = yenibaslangic(yenibas);
	return (anametin);
}

int	main(void)
{
	int	fd;

	fd = open("text", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}