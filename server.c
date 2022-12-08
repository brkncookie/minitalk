/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:26:39 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/06 16:49:18 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_c = 0;

void	bindeco(int sig)
{
	if (sig == SIGUSR1)
		g_c = (g_c << 1) + 1;
	else
		g_c = (g_c << 1);
}

int	main(void)
{
	struct sigaction	sa;
	int					count;

	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = 0;
	sa.sa_handler = bindeco;
	count = sigaction(SIGUSR1, &sa, NULL) + sigaction(SIGUSR2, &sa, NULL);
	if (count != 0)
		return (ft_printf("sigaction() error'd\n"), 1);
	while (1)
	{
		count = 0;
		while (count++ < 8)
			pause();
		ft_printf("%c", g_c);
		g_c = 0;
	}
	return (0);
}
