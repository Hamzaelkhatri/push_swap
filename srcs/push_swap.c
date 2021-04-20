#include "push_swap.h"

void save(t_stacka *a)
{
    int fd;

    fd = open("result.ps",O_CREAT|O_RDWR| O_TRUNC,0666);
    a->fd = fd;
    ft_putendl_fd("######## PUSH SWAP LOG ##########",a->fd);
    print_2(a->arg,a->fd);
}

void	p_help(void)
{
	ft_putendl_fd("welcome to push swap help", 1);
	ft_putendl_fd("-c coloraze inscruction with different color", 1);
	ft_putendl_fd("-v debug in checker programme", 1);
	ft_putendl_fd("-s save inscruction in push_swap.log", 1);
	ft_putendl_fd("-show print lists after every inscruction NB: delay 1s", 1);
	ft_putendl_fd("-h help", 1);
	exit(0);
}

void	check_param(t_stacka *a, char **ag)
{
	if (!ft_strcmp(ag[1], "-c"))
		a->colors = 1;
	else if (!ft_strcmp(ag[1], "-h"))
		p_help();
	else if (!ft_strcmp(ag[1], "-show"))
		a->show = 1;
    else if (!ft_strcmp(ag[1], "-s"))
		save(a);
}

int	main(int ac, char **ag)
{
	t_stacka	*a;
	t_stackb	*b;
	    char	**split;
	     int	i;

	i = 1;
	a = NULL;
	b = NULL;
	split = NULL;
	if (ac > 1)
	{
		if (!ft_strcmp(ag[1], "-c") || !ft_strcmp(ag[1], "-h")
			|| !ft_strcmp(ag[1], "-show") || !ft_strcmp(ag[1], "-s"))
			i = 2;
		if (ac == 1 + i)
			split = ft_split(ag[i], ' ');
		else
			split = (&ag[i]);
		if (i > 1 && ac == 2)
			p_help();
		check_digit(split);
		check_double(split);
		add_new(&a, split);
		check_param(a, ag);
		if (size_arg(split) < 20)
			algo_under50(a, b);
		else if (size_arg(split) < 100)
			i = quick_sort(a, b, 3);
		else if (size_arg(split) >= 100 && size_arg(split) < 500)
			i = quick_sort(a, b, 4);
		else if (size_arg(split) >= 500)
			i = quick_sort(a, b, 8);
		free(a->arg);
		free(a);
		if (ac == 2)
			free_2d(split);
        if(a->fd)
            close(a->fd);
	}
	return (0);
}
