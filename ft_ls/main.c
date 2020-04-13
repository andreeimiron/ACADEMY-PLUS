/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:30:40 by anmiron           #+#    #+#             */
/*   Updated: 2017/06/12 16:43:12 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			to_print(t_node *list, t_opt *opt)
{
	t_node			*tmp;

	tmp = list;
	if (opt->l)
		return (print_long(list, opt));
	else
	{
		while (tmp)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}

t_node		*list_reg(t_node *list, t_opt *opt)
{
	t_node	*tmp;
	t_node	*prec;
	t_node	*reg;
	t_node	*new;

	tmp = list;
	prec = list;
	reg = NULL;
	while (tmp)
	{
		if (S_ISREG(tmp->info->st_mode))
		{
			new = new_node(tmp->name, tmp->path);
			reg = insert_node(reg, new, opt);
		}
		prec = prec->next;
		tmp = tmp->next;
	}
	if (reg)
	{
		to_print(reg, opt);
		ft_putchar(EOL);
	}
	return (list);
}

void	readall(t_node *list, t_opt *opt)
{
	t_node	*tmp;
	int		ok;

	tmp = list;
	ok = 0;
	while (tmp)
	{
		ok = (tmp->next) ? 1 : ok;
		if (ok == 1 && !(S_ISREG(tmp->info->st_mode)))
		{
			ft_putstr(tmp->name);
			ft_putendl(":");
		}
		reading(opt, tmp->name);
		if (tmp->next && !S_ISREG(tmp->info->st_mode))
			ft_putchar(EOL);
		tmp = tmp->next;
	}
}

void	get_read(int ac, char **av)
{
	int		i;
	t_opt	*opt;
	t_node	*list;
	t_node	*new;

	i = 1;
	list = NULL;
	opt = manage_opt(av, &i);
	while (i < ac)
	{
		new = new_node(av[i], ".");
		list = insert_node(list, new, opt);
		i++;
	}
	if (list != NULL)
	{
		list = list_reg(list, opt);
		readall(list, opt);
	}
	else
		reading(opt, ".");
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		reading(init_opt(), ".");
	else
		get_read(argc, argv);
	return (0);
}
