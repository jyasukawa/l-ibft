#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_isalpha(0));
// 	printf("%d\n", isalpha(0));
// }