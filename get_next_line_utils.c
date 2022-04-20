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
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!old || !buff)
		return (NULL);
	new = malloc(ft_strlen(old) + ft_strlen(buff));
	if (!new)
		return (NULL);
	i = 0;
	while (old[i] != 0)
	{
		new[i] = old[i];
		i++;
	}
	j = 0;
	while (buff[j] != 0 && buff[j] != c)
	{
		new[i + j] = buff[j];
		j++;
	}
	return (new);
}