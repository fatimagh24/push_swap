/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:33:20 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/09 16:04:45 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *c);

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	if (*s)
		ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}
/*
int main()
{
	char	s[] = "Fatima Ghanem";
	char	*s2 = ft_strdup(s);
	printf("%s",s2);
	free(s2);
	return(0);
}*/
