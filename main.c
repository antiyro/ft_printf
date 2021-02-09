#include "src/libft/libft.h"
#include "include/ft_printf.h"

int main(int argc, char **argv)
{
    ft_printf("-->|%-4.*d|<--\n", 3, -12);
    printf("\n");
    printf("-->|%-4.*d|<--\n", 3, -12);
}