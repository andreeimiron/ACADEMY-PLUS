/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:18:47 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/02 18:51:48 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_buff(int const fd, char **str)
{
	char	*buff;
	char	*new;
	int		rez;

	buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1));
	if (!(buff))
		return (-1);
	rez = read(fd, buff, BUFF_SIZE);
	if (rez > 0)
	{
		buff[rez] = '\0';
		new = ft_strjoin(*str, buff);
		free(*str);
		*str = new;
	}
	free(buff);
	return (rez);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str = NULL;
	char		*poz;
	int			rez;

	if ((!(str) && (str = (char*)malloc(sizeof(*str) + 1)) == NULL)
			|| BUFF_SIZE < 0 || !(line) || fd < 0)
		return (-1);
	poz = ft_strchr(str, '\n');
	while (poz == NULL)
	{
		rez = read_buff(fd, &str);
		if (rez == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (rez == -1)
			return (-1);
		else
			poz = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(poz));
	str = ft_strdup(poz + 1);
	return (1);
}
