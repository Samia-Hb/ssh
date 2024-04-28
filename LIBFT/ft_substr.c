/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:14:29 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/18 20:48:43 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty(void)
{
	char	*substring;

	substring = (char *)malloc(1);
	if (!substring)
		return (NULL);
	substring[0] = '\0';
	return (substring);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*substring;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (empty());
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = (char *)(malloc((len + 1) * sizeof(char)));
	if (!substring)
		return (NULL);
	while (i < len && s[start] && start < ft_strlen(s))
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
