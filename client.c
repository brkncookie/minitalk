/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:28:35 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/06 16:46:00 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	c;
	size_t			inx;

	if (argc != 3 || argv[2][0] == 0 || (!ft_atoi(argv[1]) && argv[1][0] != 48))
		return (ft_printf("Invalid Arguments.\n"), 1);
	pid = ft_atoi(argv[1]);
	inx = 0;
	while (argv[2][inx])
	{
		c = 128;
		while (c)
		{
			if (!(((argv[2][inx] & c) && !kill(pid, SIGUSR1)) || \
					(!(argv[2][inx] & c) && !kill(pid, SIGUSR2))))
				return (ft_printf("kill() error'd\n"), 1);
			c = (c >> 1) + usleep(500);
		}
		inx++;
	}
	return (0);
}
