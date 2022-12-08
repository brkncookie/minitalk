/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:16:38 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/06 13:57:24 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* in ascii 'A' is 65, 'Z' is 90 and 'a' is 97, 'z' is 122 */
int	ft_isalpha(int c)
{
	return ((c > 96 && c < 123) || (c > 64 && c < 91));
}