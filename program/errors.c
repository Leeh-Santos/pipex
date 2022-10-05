/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:38:28 by learodri          #+#    #+#             */
/*   Updated: 2022/10/05 21:13:54 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	boom(char	*str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	not_found(char	*str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
