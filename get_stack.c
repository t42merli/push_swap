/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:03:19 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/28 05:11:17 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_strdup_space(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = ' ';
	s[i + 1] = '\0';
	return (s);
}

char		**get_arg(int argc, char **argv)
{
	int		i;
	char	**tab;
	char	*tmp;
	char	*tmp2;

	i = 1;
	tmp = "";
	while (i < argc)
	{
		if (!(tmp2 = ft_strdup_space(tmp)))
			return (NULL);
		if (i != 1)
			free(tmp);
		if (!(tmp = ft_strjoin(tmp2, argv[i])))
			return (NULL);
		free(tmp2);
		i++;
	}
	if (!(tab = ft_strsplit(tmp, ' ')))
		return (NULL);
	free(tmp);
	return (tab);
}

t_stack		*fill_stack(char **argv)
{
	int		i;
	t_stack	*tmp;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	if (argv[i])
		stack = new_stack(ft_atoi(argv[i]));
	tmp = stack;
	while (argv[i])
	{
		if (!(check_num(stack->nb, argv[i], tmp)))
		{
			free_stack(tmp);
			ft_putendl("Error");
			return (NULL);
		}
		i++;
		if (argv[i])
			stack->next = new_stack(ft_atoi(argv[i]));
		stack = stack->next;
	}
	return (tmp);
}

t_stack		*get_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**av;

	stack = NULL;
	if (!(av = get_arg(argc, argv)))
		return (NULL);
	if (!(stack = fill_stack(av)))
	{
		ft_free((void**)av);
		return (NULL);
	}
	ft_free((void**)av);
	return (stack);
}
