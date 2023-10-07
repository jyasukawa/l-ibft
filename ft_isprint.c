#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_isprint(0));
// 	printf("%d\n", isprint(0));
// }