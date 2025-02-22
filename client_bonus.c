#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	size_t	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	received;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		received = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		received = 0;
		if ((c >> i & 1 ) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!received);
			pause();
	}
}
int main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3)
		return(ft_printf("Please enter valid arguments.\n"), 1);
	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, signal_handler);
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
		if (av[2][i] == '\0')
			ft_printf("Message received!\n");
	}
}