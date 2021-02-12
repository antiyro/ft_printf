#include "src/libft/libft.h"
#include "include/ft_printf.h"

int main(int argc, char **argv)
{
    int	i;
	int *p;

	i = atoi(argv[1]);
	p = &i;
	p = 0;
	Print("-->|%-16.p|<--\n", p);
	return (0);
}