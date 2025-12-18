/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:17:48 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/18 16:55:07 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# include "./ft_printf/ft_printf.h"

void	send_bits(int pid, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
