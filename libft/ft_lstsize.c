/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:15:13 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/18 11:06:11 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
