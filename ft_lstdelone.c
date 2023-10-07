#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
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
//     // リストの先頭ポインタ
//     t_list *myList = NULL;

//     // 新しいリストノードを作成
//     int data1 = 42;
//     t_list *node1 = ft_lstnew(&data1);

//     int data2 = 99;
//     t_list *node2 = ft_lstnew(&data2);

//     // リストの最後にノードを追加
//     ft_lstadd_back(&myList, node1);
//     ft_lstadd_back(&myList, node2);

//     // リストの内容を表示
//     printf("Before Deletion:\n");
//     printNodeContent(myList);
//     printNodeContent(myList->next);

//     // リストの先頭ノードを削除
//     ft_lstdelone(myList, free);

//     // リストの内容を表示（削除後）
//     printf("\nAfter Deletion:\n");
//     printNodeContent(myList); // myListは削除されたので NULL になる

//     // リストの残りのノードを解放
//     while (myList != NULL)
//     {
//         t_list *temp = myList;
//         myList = myList->next;
//         free(temp);
//     }
//     return 0;
// }

// <PDF>
// Function name ft_lstdelone
// Prototype void ft_lstdelone(t_list *lst, void (*del)(void
// *));
// Turn in files -
// Parameters lst: The node to free.
// del: The address of the function used to delete
// the content.
// Return value None
// External functs. free
// Description Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

// ＜PDF解説＞
// ft_lstdelone 関数は、リスト内の特定のノードを削除するための関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstdelone 関数は、2 つの引数を受け取ります。lst は削除対象のノードへのポインタであり、del はそのノードのコンテンツを削除するための関数へのポインタです。
// 関数を呼び出すと、指定されたノード lst のコンテンツを削除するために、del 関数が呼び出されます。この際、ノードのコンテンツがどのように削除されるかは、del 関数によって定義されます。
// del 関数によってノードのコンテンツが削除された後、ノード自体は free 関数を使用してメモリから解放されます。
// ノードの next ポインタは解放されません。つまり、削除されたノードの前後のノードは依然としてリンクされています。
// この関数を使用することで、リスト内の特定のノードを削除し、そのノードのメモリを解放することができます。