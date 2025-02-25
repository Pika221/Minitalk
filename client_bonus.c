#include "minitalk_bonus.h"

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
int	digit(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int	received;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		received = 1;
}

void	send_string(int pid, char *str)
{
	int	i;

	i = 8;
	while (*str)
	{
		while (i--)
		{
			received = 0;
			if ((*str) >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (!received)
				pause();
		}
		str++;
		i = 8;
	}
}

int main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
		return(ft_printf("Invalid number of arguments.\n"), 1);
	if (!digit(av[1]))
		return(ft_printf("Wrong PID format.\n"), 1);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, signal_handler);
	send_string(pid, av[2]);
	ft_printf("Message received!\n");
	return (0);
}