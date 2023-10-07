#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst ==NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

// #include <stdio.h>
// t_list *ft_lstnew(void *content)
// {
//     t_list *new = (t_list *)malloc(sizeof(t_list));
//     if (new == NULL)
//         return NULL;
//     new->content = content;
//     new->next = NULL;
//     return new;
// }
// t_list *ft_lstlast(t_list *lst)
// {
//     if (lst == NULL)
//         return NULL;
//     while (lst->next != NULL)
//         lst = lst->next;
//     return lst;
// }
// void ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list *tmp;

//     if (lst == NULL || new == NULL)
//         return;
//     if (*lst != NULL)
//     {
//         tmp = ft_lstlast(*lst);
//         tmp->next = new;
//     }
//     else
//         *lst = new;
// }
// void ft_lstdelone(t_list *lst, void (*del)(void *))
// {
//     if (lst == NULL || del == NULL)
//         return;
//     del(lst->content);
//     free(lst);
// }
// // リストノードの内容を表示する関数
// void printNodeContent(t_list *node)
// {
//     if (node != NULL)
//     {
//         int *nodeData = (int *)(node->content);
//         printf("Node Content: %d\n", *nodeData);
//     }
// }
// int main()
// {
// 	// リストの先頭ポインタ
// 	t_list *myList = NULL;

// 	// 新しいリストノードを作成
// 	int data1 = 42;
// 	t_list *node1 = ft_lstnew(&data1);

// 	int data2 = 99;
// 	t_list *node2 = ft_lstnew(&data2);

// 	// リストの最後にノードを追加
// 	ft_lstadd_back(&myList, node1);
// 	ft_lstadd_back(&myList, node2);

// 	// リストの内容を表示
// 	printf("Before Clearing:\n");
// 	printNodeContent(myList);
// 	printNodeContent(myList->next);

// 	// リストを全て解放
// 	ft_lstclear(&myList, free);

// 	// リストの内容を表示（解放後）
// 	printf("\nAfter Clearing:\n");
// 	printNodeContent(myList); // myListは解放されたので NULL になる
// 	return 0;
// }

// <PDF>
// Function name ft_lstclear
// Prototype void ft_lstclear(t_list **lst, void (*del)(void
// *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.
// Return value None
// External functs. free
// Description Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

// ＜PDF解説＞
// ft_lstclear 関数は、指定されたリストのノードをすべて削除し、そのノードのコンテンツを削除してメモリを解放し、最終的にリストへのポインタを NULL に設定するための関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstclear 関数は、2 つの引数を受け取ります。lst はリストへのポインタへのポインタであり、del はノードのコンテンツを削除するための関数へのポインタです。
// 関数を呼び出すと、指定されたリスト *lst から最初のノードを削除し、del 関数を使用してそのノードのコンテンツを削除し、メモリを解放します。この操作は、リストの各ノードに対して順番に繰り返され、リスト内のすべてのノードが削除されます。
// リスト内のノードがすべて削除された後、*lst ポインタ（リストへのポインタへのポインタ）は NULL に設定されます。これにより、削除されたリストが空であることを示します。
// ノードのコンテンツは del 関数によって削除されるため、del 関数の実装によってノードのコンテンツがどのように解放されるかが決まります。
// この関数を使用することで、リスト内のすべてのノードを削除し、メモリリークを防ぐことができます。また、リストへのポインタも NULL に設定され、安全にリストを破棄できます。

// ＜挙動解説＞
// swap関数に近い
// tmp という一時的なポインタ変数を宣言します。この変数は、現在のリストのノードを一時的に保持するために使用されます。
// t_list *tmp;
// tmp に現在のリストの次のノードへのポインタを格納します。つまり、現在のリストノードの次のノードを指すポインタです。
// tmp = (*lst)->next;
// ft_lstdelone 関数を使用して、現在のリストノードを解放します。この関数は、リストノードの内容を解放し、そのノード自体も解放します。del 関数は、ノードの内容を解放するために使用されます。
// ft_lstdelone(*lst, del);
// 現在のリストのポインタ *lst を、次のノードを指す tmp ポインタに設定します。これにより、現在のノードが解放され、次のノードが新しいリストの先頭になります。
// *lst = tmp;
// このコードブロックを繰り返すことで、リスト内のすべてのノードが順番に解放され、最終的に *lst が NULL に設定されます。これにより、リスト全体が解放されます。