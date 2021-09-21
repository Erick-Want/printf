/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:12:14 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/16 15:16:15 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_beg;
	size_t	i_end;

	if (!s1 || !set)
		return (NULL);
	i_beg = 0;
	i_end = ft_strlen(s1);
	if (i_end == 0)
		return (ft_calloc(1, sizeof(char)));
	while (s1[i_beg] && ft_strchr(set, s1[i_beg]))
		i_beg++;
	while (i_end && ft_strchr(set, s1[i_end]))
		i_end--;
	return (ft_substr(s1, i_beg, (i_end - i_beg + 1)));
}

// int main()
// {
// 	char	*s;
// 	char	*set;

// 	s = "-a-aErick-Matheus-a-";// 16 - 4 = 12
// 	set = "-a";
// 	s = ft_strtrim(s, set);
// 	printf("%s", s);
// }
