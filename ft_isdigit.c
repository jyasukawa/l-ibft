#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_isdigit(0));
// 	printf("%d\n", isdigit(0));
// }