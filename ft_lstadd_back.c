#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
  t_list	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
	{
		tmp = ft_lstlast(*lst);
    tmp->next = new;
	}
	else
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
// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
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

// 	// リストをたどって内容を表示
// 	t_list *current = myList;
// 	while (current != NULL)
// 	{
// 		int *nodeData = (int *)(current->content);
// 		printf("Node Content: %d\n", *nodeData);
// 		current = current->next;
// 	}

// 	// リストを解放
// 	while (myList != NULL)
// 	{
// 		t_list *temp = myList;
// 		myList = myList->next;
// 		free(temp);
// 	}
// 	return 0;
// }

// <PDF>
// Function name ft_lstadd_back
// Prototype void ft_lstadd_back(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the end of the list.

// ＜PDF解説＞
// ft_lstadd_back 関数は、与えられたリストの末尾に新しいノードを追加するための関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstadd_back 関数は、2 つの引数を受け取ります。lst はリストの最初のノードへのポインタへのポインタであり、new は追加する新しいノードへのポインタです。
// 関数を呼び出すと、新しいノード new を既存のリストの末尾に追加します。
// リストが空であれば、新しいノード new はリストの最初のノードになります。
// リストが空でない場合、リストの最後のノードを見つけて、そのノードの next ポインタを新しいノード new に設定します。これにより、新しいノードがリストの末尾に追加されます。
// リスト内のノードがリンクリストの最後に配置され、新しいノードが追加されたら、関数は終了します。
// この関数を使用すると、リンクリストの末尾に新しいノードを簡単に追加できます