#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>

void	ft_putchar(int x, int *toplam_byte)
{
	(*toplam_byte)++;
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

void	type_convert()
{
	return ;
}

int	ft_printf(const char *new, ...)
{
	int		index;
	int		toplam_byte;
	va_list	va;
	va_start(va, new);

	index = 0;
	toplam_byte = 0;
	while (new[index])
	{
		if(new[index] == '%')
		{
			index++;
			type_convert();
		}
		else
			ft_putchar(new[index], &toplam_byte);
		index++;
	}
	va_end(va);

	return (toplam_byte);
}

int	main()
{
	int	x;

	x = 48;
	x += ft_printf("asd%casd", 'x');
	write(1, &x, 1);
	return (0);
}

//int	main()
//{
//	int	x;

//	x = 0;
//	x = printf("asd%sasd", "yusuf");
//	printf("%d", x);
//}