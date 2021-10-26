#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_args	args;
	int		pipes[2];

	if (ac != 5)
		ft_exit(1, "Error: argument\n");
	pipe(pipes);
	args = init_args(av);
	ctrl_proc(args, pipes, envp);
	ft_exit(0, NULL);
}
