#include "../mini_talk.h"


char	*apend(char *bits, char c)
{
    size_t	i;
    char	*tmp;

    i = -1;
    tmp = malloc(ft_strlen(bits) + 2);
    if (tmp == NULL)
        return (NULL);
    while (bits[++i])
        tmp[i] = bits[i];
    tmp[i] = c;
    tmp[i + 1] = '\0';
    free(bits);
    return (tmp);
}

static void	ft_convert(char *s)
{
    int				pow;
    unsigned char	c;
    size_t			i;

    pow = 1;
    c = 0;
    i = ft_strlen(s) - 1;
    while (i + 1)
    {
        c += pow * (s[i] - '0');
        pow *= 2;
        i--;
    }
    write(1, &c, 1);
}

static void	infoHandler(int sig)
{
    static char	*bits;
    static int	bitcount;

    bitcount++;
    if (!bits)
    {
        bits = ft_strdup("");
        bitcount = 1;
    }
    if (sig == SIGUSR2)
        bits = apend(bits, '0');
    else
        bits = apend(bits, '1');
    if (bitcount == 8)
    {
        ft_convert(bits);
        free(bits);
        bits = NULL;
    }
}
int main(void)
{
    int	id;

    id = (int)(getpid());
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, infoHandler);
    signal(SIGUSR2, infoHandler);
    while (1)
        usleep(100);
}
