#include "../mini_talk.h"

int correct_message(int ac, char **av)
{
        int	i;

        if (ac != 3)
            return (1);
        i = -1;
        while (av[1][++i])
        {
            if (!ft_isdigit((av[1][i])))
                return (1);
        }
        return (0);
}

void    send_len_in_bits(int pid, int size)
{
    int i;

    i = 0;
    while (i < 32)
    {
        if(size >> i++ & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
    }
}
void send_char(int pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if(c >> i++ & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
    }

}
int main(int ac, char **av)
{
    int		pid;
    char	*message;
    int		size;
    int i;

    i =-1;
    if (pid <= 0)
        return (-1);
    if (correct_message(ac, av))
        return (-1);
    pid = ft_atoi(av[1]);
    message = av[2];
    size = ft_strlen(message);
    send_len_in_bits(pid , size);
    while (++i < size)
        send_char(pid, av[2][i]);
}