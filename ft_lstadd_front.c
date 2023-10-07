#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
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

// 	// リストにノードを追加
// 	ft_lstadd_front(&myList, node1);
// 	ft_lstadd_front(&myList, node2);

// 	// リストの内容を表示
// 	t_list *current = myList;
// 	while (current != NULL)
// 	{
// 			int *content = (int *)(current->content);
// 			printf("Content: %d\n", *content);
// 			current = current->next;
// 	}
// 	// リストを解放
// 	while (myList != NULL)
// 	{
// 			t_list *temp = myList;
// 			myList = myList->next;
// 			free(temp);
// 	}
// 	// 最後にlstaddを使用した99が先に出力される
// }

// <PDF>
// Function name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the beginning of the list.

// ＜PDF解説＞
// ft_lstadd_front 関数は、指定されたリストの先頭に新しいノードを追加する関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstadd_front 関数は、2 つの引数を受け取ります。1 つ目の引数 lst は、リストへのポインタへのポインタです。2 つ目の引数 new は、新しいノードへのポインタです。
// 関数を呼び出すと、新しいノード new は既存のリストの先頭に追加されます。
// new ノードの next メンバは、元々のリストの先頭ノード（*lst が指すノード）を指すように設定されます。
// 最後に、lst ポインタを新しい先頭ノードを指すように更新します。つまり、*lst の値が new ノードを指すようになります。
// この関数を使用すると、リストの先頭に新しいノードを効率的に追加できます