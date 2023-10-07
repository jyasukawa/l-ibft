#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <ctype.h>
// #include <stdio.h>
// int	ft_isalpha(int c)
// {
// 	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
// }
// int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }
// int main(){
// 	printf("%d\n", ft_alnum(0));
// 	printf("%d\n", isalnum(0));
// }