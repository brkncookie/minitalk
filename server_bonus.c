/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:26:39 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/06 16:07:53 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_cp	g_cp = {0, 0};

void	bindeco(int sig, siginfo_t *siginfo, void *uc)
{
	(void) uc;
	if (sig == SIGUSR1)
		g_cp.c = (g_cp.c << 1) + 1;
	else
		g_cp.c = (g_cp.c << 1);
	g_cp.pid = siginfo->si_pid;
}

int	main(void)
{
	struct sigaction	sa;
	int					count;

	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bindeco;
	count = sigaction(SIGUSR1, &sa, NULL) + sigaction(SIGUSR2, &sa, NULL);
	if (count != 0)
		return (ft_printf("sigaction() error'd\n"), 1);
	while (1)
	{
		count = 0;
		while (count++ < 8)
			pause();
		if (!g_cp.c)
		{
			if (kill(g_cp.pid, SIGUSR1) < 0)
				return (ft_printf("kill() error'd\n"), 1);
			else
				continue ;
		}
		ft_printf("%c", g_cp.c);
		g_cp.c = 0;
	}
	return (0);
}
