#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// t_list *ft_lstnew(void *content)
// {
// 	t_list *new = (t_list *)malloc(sizeof(t_list));
// 	if (new == NULL)
// 			return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }
// // リストの内容を表示する関数
// void print_int(void *content)
// {
// 	int *num = (int *)content;
// 	printf("%d\n", *num);
// }
// int main()
// {
// 	// 整数のリストを作成
// 	t_list *list = ft_lstnew((void *)malloc(sizeof(int)));
// 	int *num1 = (int *)list->content;
// 	*num1 = 42;

// 	t_list *node2 = ft_lstnew((void *)malloc(sizeof(int)));
// 	int *num2 = (int *)node2->content;
// 	*num2 = 99;

// 	list->next = node2;

// 	// リスト内の各要素に関数を適用して表示
// 	ft_lstiter(list, &print_int);

// 	// リストの解放
// 	while (list != NULL)
// 	{
// 			t_list *tmp = list->next;
// 			free(list->content);
// 			free(list);
// 			list = tmp;
// 	}
// 	return 0;
// }

// <PDF>
// Function name ft_lstiter
// Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// Return value None
// External functs. None
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

// ＜PDF解説＞
// ft_lstiter 関数は、指定されたリスト lst をイテレートし、各ノードのコンテンツに対して指定された関数 f を適用するための関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstiter 関数は、2 つの引数を受け取ります。lst はリストへのポインタであり、f はリストの各ノードのコンテンツに適用される関数へのポインタです。
// 関数を呼び出すと、指定されたリスト lst の各ノードが順番にイテレートされます。
// 各ノードのコンテンツに対して、指定された関数 f が適用されます。この関数 f は、ノードのコンテンツを引数として受け取り、必要な操作を実行します。
// リスト内のすべてのノードがイテレートされ、各ノードのコンテンツに対して関数 f が適用された後、関数の実行が終了します。
// この関数を使用することで、リスト内の各ノードに対して特定の操作や処理を行うことができます。リスト内のすべてのノードに同じ処理を適用したり、異なる処理を各ノードに適用したりする際に便利です。

// ＜メモ＞
// ft_lstiter(list, print_int); と ft_lstiter(list, &print_int); は、C言語において関数へのポインタを渡す方法に関連しています。両者は通常、同じ動作をしますが、ポインタの表現方法が異なります。
// ft_lstiter(list, print_int);
// この形式では、print_int 関数名をそのまま渡しています。C言語では、関数名そのものが関数へのポインタとして解釈されるため、print_int は関数へのポインタとして扱われます。
// ft_lstiter(list, &print_int);
// この形式では、アンド記号（&）を使用して print_int 関数へのポインタを渡しています。これにより、&print_int は print_int 関数へのポインタとして明示的に指定されます。
// どちらの方法も通常は機能しますが、一般的には &print_int のように明示的にポインタを取得することが推奨されます。これにより、コードの読み手に対して関数へのポインタの渡し方が明確になり、誤解を避けるのに役立ちます。また、一部の文法上の制約においては、ポインタを明示的に取得する必要があります。