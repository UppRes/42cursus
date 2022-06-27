#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>

void	ft_putchar(int x)
{
	write(1, &x, 1);
}

int	ft_strlen(const	char *new)
{
	int	i;

	i = 0;
	while (new[i])
		i++;
	return (i);
}

int	ft_printf(const char *new, ...)
{
	int		i;
	va_list	va;
	va_start(va, new);

	i = 0;
	while (new[i])
	{
		if (new[i] == '%' && new[i + 1] == 'c')
		{
			ft_putchar(va_arg(va, int));
			i++;
		}
		else
			ft_putchar(new[i]);
		i++;
	}
	va_end(va);
}

//int	main()
//{
//	int	x;

//	x = 0;
//	x = ft_printf("asd%casd%s", 'x', "yusuf");
//}

int	main()
{
	int	x;

	x = 0;
	x = printf("asd%casd%s", 'x');
	printf("%d", x);
}