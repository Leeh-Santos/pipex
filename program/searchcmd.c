/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:16:45 by learodri          #+#    #+#             */
/*   Updated: 2022/10/06 18:48:28 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**grab_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*final_path;
	char	*add_bar;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = grab_paths(envp);
	i = -1;
	while (paths[++i])
	{
		add_bar = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(add_bar, cmd);
		free(add_bar);
		if (!access(final_path, F_OK))
		{
			free_split(paths);
			return (final_path);
		}
		free(final_path);
	}
	free_split(paths);
	return (0);
}
