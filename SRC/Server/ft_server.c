#include "../mini_talk.h"

int	main(void)
{
    int	id;

    id = (int)(getpid());
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
    while (1)
       usleep(100);
}
