/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:29:51 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/18 16:55:23 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_receiver = 0;

void	handle_confirm(int sig)
{
	if (sig == SIGUSR1)
		g_receiver = 1;
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_receiver = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_receiver == 0)
			usleep(10);
		bit--;
	}
}

int	is_valid_pid(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	if (argc != 3 || !is_valid_pid(argv[1]))
	{
		ft_printf("Erro: Use ./client <PID> <MESSAGE>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Erro: PID inexistente.\n");
		return (1);
	}
	signal(SIGUSR1, handle_confirm);
	str = argv[2];
	i = 0;
	while (str[i])
		send_bits(pid, str[i++]);
	send_bits(pid, '\n');
	return (0);
}
