/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:45:47 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/19 15:29:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len > ((unsigned int)ft_strlen(s)) - start)
		len = ((unsigned int)ft_strlen(s) - start);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i < len && *(s + i) != '\0')
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

// int main ()
// {
//     char const *s = "mondongo";
//     unsigned int start = 3;
//     size_t len = 3;
//     printf("%s\n", ft_substr(s, start, len));
// }
