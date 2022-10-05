/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:29:15 by learodri          #+#    #+#             */
/*   Updated: 2022/10/05 22:11:30 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid1(int *pipefd, int *filefd, char **av, char **envp)
{
	char	**cmd1;
	pid_t	id;

	id = fork();
	if (id < 0)
		boom("not able to fork, try a spoon");
	if (id == 0)
	{
		filefd[0] = open(av[1], O_RDONLY);
		if (filefd[0] < 0)
			not_found("file1 error");
		cmd1 = ft_split(av[2], ' ');
		if (dup2(filefd[0], STDIN_FILENO) < 0
			|| dup2(pipefd[1], STDOUT_FILENO) < 0)
			boom("dup2 problem dude, Im sorry");
		//parsing for execve
	}
	
}

void	kid2(int pipefd, int filefd, char **av, char **envp)
{
	char	**cmd2;
	pid_t	id;
}
int	main(int ac, char **av, char **envp)
{
	int	filefd[2];
	int	pipefd[2];

	if (ac != 5)
	{
		write(2, "goes like this: ./pipex file1 cmd1 cmd2 file2", 46);
		exit(EXIT_FAILURE);
	}
	
	if (pipe(pipefd) < 0)
		boom("pipe failed bro");
		
	
		//kid1(pipefd,filefd,av,envp)
		//kid2
		//close pipefd0
		//close pipefd1
		//waitpid 
		//waitpid 
		
	return (0);
}
