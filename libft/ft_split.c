/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:11:43 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/01 12:21:43 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (s[y] != '\0')
	{
		if (s[y] != c)
		{
			i++;
			while (s[y] != c && s[y] != '\0')
				y++;
		}
		else
			y++;
	}
	return (i);
}

static int	count_letter(const char *s, char c)
{
	int	y;

	y = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		y++;
	}
	return (y);
}

static void	copy_string(char **matrix, const char *s, char c)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (*s != '\0')
	{
		y = 0;
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				matrix[x][y] = *s;
				s++;
				y++;
			}
			matrix[x][y] = 0;
			x++;
		}
		else
			s++;
	}
}

static int	alloc_string(char const *s, char **matrix, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[y] != '\0')
	{
		if (s[y] != c)
		{
			matrix[i] = malloc(sizeof(char) * count_letter(&s[y], c) + 1);
			if (!matrix)
				return (0);
			i++;
			y = y + count_letter(&s[y], c);
		}
		else
			y++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**matrix;

	if (!s)
		return (NULL);
	i = count_words(s, c);
	matrix = malloc(sizeof(char *) * (i + 1));
	if (!matrix)
		return (NULL);
	matrix[i] = 0;
	if (!alloc_string(s, matrix, c))
		return (NULL);
	copy_string(matrix, s, c);
	return (matrix);
}
