/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:45:54 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 02:29:10 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_free_mallocs(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		res[j] = NULL;
		j--;
	}
	free(res);
	res = NULL;
	return (NULL);
}

int	ft_count_tabs(char const *s, char c)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (s[i])
	{
		if ((!i && s[i] != c) || (s[i] != c && s[i - 1] == c))
			tabs++;
		i++;
	}
	return (tabs);
}

static void	ft_fill_tab(char *res, const char *s, char c, int w)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (z < w)
	{
		if (s[i] == c)
			i++;
		res[z] = s[i++];
		z++;
	}
	res[z] = '\0';
	z = 0;
}

static char	**ft_part2(char **res, const char *s, char c, int tabs)
{
	int		i;
	int		j;
	int		z;
	int		a;

	i = 0;
	j = 0;
	a = 0;
	while (j < tabs)
	{
		z = 0;
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i++] != '\0')
			z++;
		if (z > 0)
		{
			res[j] = (char *)malloc(sizeof(char) * z + 1);
			ft_fill_tab(res[j], &s[a], c, z);
			if (!res[j++])
				return (ft_free_mallocs(res, j));
		}
		a = i + 1;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		tabs;
	char	**res;

	if (!s)
		return (NULL);
	tabs = ft_count_tabs(s, c);
	res = (char **)ft_calloc(sizeof (char *), tabs + 1);
	if (!res)
		return (NULL);
	res = ft_part2(res, s, c, tabs);
	return (res);
}
