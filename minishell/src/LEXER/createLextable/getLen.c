/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetLen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:13 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 22:00:13 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	c karakterine komutun ilk indisi atanir ve hangi tirnak
	tipi oldugu anlasilir(" ya da ').
	komut nulla gelene kadar(pdf tirnagin kapatilmis olup olmadıgini
	 kontrol etmemizi istemiyor)
	ya da baslangic karakterini gorene kadar count degiskeni artilir.
	ve bu degisken return edilir.
*/
size_t	get_quotelen(char *cmd_line)
{
	char	c;
	size_t	count;

	c = *cmd_line;
	count = 1;
	while (*(++cmd_line))
	{
		count++;
		if (*cmd_line == c)
			break ;
	}
	return (count);
}

/*
	Bu fonksiyon her cagirildiginda kelime uzunlugunu alir.
	Ve uzunlugu dondürür.
	Eger komutun indisi metakarakter ise metakarakterin
	genisligi count'a eklenir ve dongu sonlandirilir.
	Eger komutun indisinde tirnak isareti var ise get_quotelen
	fonksiyonundan tirnagin ve icinin ne kadar uzunkukta oldugu alinir
	ve ardindan counta eklenir.
	Eger komutun indisi metakarakter ya da tirnak degilse count arttirlir.
	orn:
	cat a.txt -> cat'in uzunlugu olan 3'u dondürür
	<< "eof" cat -> <<'un uzunlugu olan 2'yi dondürür
	"Ahmet$HOME"ls echo -> "Ahmet$HOME"ls'in uzunlugu olan 14'u dondürür
	gelen komut null'a gelene ya da bosluga gelene kadr dondürülür.
*/
size_t	get_cmdlen(char *cmd_line)
{
	size_t	count;
	size_t	quotelen;
	char	*is_meta;

	count = 0;
	while (cmd_line && *cmd_line && *cmd_line != ' ')
	{
		is_meta = compare_metachars(cmd_line);
		if (is_meta)
		{
			if (!count)
				count += ft_strlen(is_meta);
			break ;
		}
		if ((*cmd_line == *SINGLE_QUOTE || *cmd_line == *DOUBLE_QUOTE))
		{
			quotelen = get_quotelen(cmd_line);
			count += quotelen;
			cmd_line += quotelen;
			continue ;
		}
		count++;
		cmd_line++;
	}
	return (count);
}
