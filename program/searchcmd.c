/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:16:45 by learodri          #+#    #+#             */
/*   Updated: 2022/10/10 22:35:01 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**grab_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4)) // runs env till find PATH
		i++;
	paths = ft_split(envp[i] + 5, ':'); // arrays of strings starts after "PATH="
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
	paths = grab_paths(envp); //arrays of strings from env
	i = -1;
	while (paths[++i])
	{
		add_bar = ft_strjoin(paths[i], "/"); // add bar at the end of each possible path
		final_path = ft_strjoin(add_bar, cmd); // add (ex. "ls") after the end of each path
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
