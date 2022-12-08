/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:28:35 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/06 15:56:43 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

struct sigaction	g_sa;

void	msgrcvd(int sig)
{
	if (sig)
		ft_printf("Message Recieved.\n");
}

int	main(int argc, char **argv)
{
	unsigned char		c;
	size_t				inx;

	if (argc != 3 || argv[2][0] == 0 || (!ft_atoi(argv[1]) && argv[1][0] != 48))
		return (ft_printf("Invalid Arguments.\n"), 1);
	g_sa.sa_handler = msgrcvd;
	if (sigaction(SIGUSR1, &g_sa, NULL) < 0)
		return (ft_printf("sigaction() error'd\n"), 1);
	inx = 0;
	while (argv[2][inx])
	{
		c = 128;
		while (c)
		{
			if (!(((argv[2][inx] & c) && !kill(ft_atoi(argv[1]), SIGUSR1)) || \
					(!(argv[2][inx] & c) && !kill(ft_atoi(argv[1]), SIGUSR2))))
				return (ft_printf("kill() error'd\n"), 1);
			c = (c >> 1) + usleep(500);
		}
		inx++;
	}
	inx = 0;
	while (inx++ < 8 && !kill(ft_atoi(argv[1]), SIGUSR2))
		usleep(500);
	return (0);
}
