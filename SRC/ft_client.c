#include "mini_talk.h"

int correct_input(int ac, char **av)
{
        int	i;

        i = -1;
        if (ac != 3)
            return (0);
        while (av[1][++i])
        {
            if (!ft_isdigit((av[1][i])))
                return (0);
        }
        return (1);
}

void    send_size(int pid, int size)
{
    int i;

    i = -1;
    while (++i < 32)
    {
            if (size & 0x01)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            size = size >> 1;
            usleep(100);
    }
}
void send_char(int pid, unsigned char c)
{
    int i;

    i = -1;
        while (++i < 8)
        {
            if (c & 0x01)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            c = c >> 1;
            usleep(100);
        }
}
int main(int ac, char **av)
{
    int		pid;
    char	*message;
    int		size;
    int i;

    if (!(correct_input(ac, av)))
        return(0);
    i = -1;
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return (-1);
    message = av[2];
    size = ft_strlen(message);
    send_size(pid , size);
    while (message[++i])
        send_char(pid, message[i]);
    send_char(pid, message[i] );
    return (0);
}