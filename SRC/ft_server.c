#include "mini_talk.h"
int	ft_recursive_power(int power)
{
    if (power == 0)
        return (1);
    else
        return (2 * ft_recursive_power(power - 1));
}
static void getsize(int *flag, int *bit, char **str, int signal)
{
    static int size = 0;
    if (signal == SIGUSR2)
        size += ft_recursive_power(*bit);
    if(*bit == 31)
    {
        if(size < 0)
            return ;
        *flag = 1;
        *str = ft_calloc(size + 1, sizeof(char));
        *bit = 0;
        size = 0;
        return ;
    }
    (*bit)++;

}

static void end_message(int *flag, char **str, int *i)
{
    *flag = 0;
    if (str)
    {
        ft_putendl_fd(*str, 1);
        free(*str);
        *str = 0;
    }
    *i = 0;
}

static void signalHandler(int signal){

    static int flag = 0;
    static int i = 0;
    static int bit = 0;
    static char *str = 0;
    static int c = 0;

    if(!flag)
        getsize(&flag, &bit, &str, signal);

    else
    {
        if (signal == SIGUSR2)
            c += ft_recursive_power(bit);;

        if (bit == 7)
        {
            str[i++] = c;
            bit = 0;
            if (c == 0)
                return (end_message(&flag, &str, &i));
            c = 0;
            return ;
        }
        bit++;
    }

}

int	main(void)
{
    int	id;

    id = (int)(getpid());
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, signalHandler);
    signal(SIGUSR2, signalHandler);

    while (1) {
        usleep(100);
    }
}