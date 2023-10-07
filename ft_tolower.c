#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

// <メモ>
// ('a' - 'A')=32だが、他のasciiコード表にも対応させたunicode？にしてみた