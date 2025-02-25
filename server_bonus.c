#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	c = c << 1;
	if (signal == SIGUSR1)
    	c = c | 1;
	else if (signal == SIGUSR2)
    	c = c | 0;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}