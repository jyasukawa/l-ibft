#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_isascii('a'));
// 	printf("%d\n", isascii('a'));
// }