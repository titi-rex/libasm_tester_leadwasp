#include "_list_push_front.h"

int	list_push_front_09(void)
{
	char	*data1 = "hello beautiful garden";
	char	*data2 = "awfawf!!!";
	char	*data3 = "what a nice night!!!";
	char	*data4 = "fgzxsegzsegsnight!!!";
	char	*data5 = "5z634fesz5fs";
	char	*data6 = "si;efjp938yrf;owa!";
	t_list	*list = NULL;

	ft_list_push_front(&list, (void*)data6);
	ft_list_push_front(&list, (void*)data5);
	ft_list_push_front(&list, (void*)data4);
	ft_list_push_front(&list, (void*)data3);
	ft_list_push_front(&list, (void*)data2);
	ft_list_push_front(&list, (void*)data1);
	int res = strcmp(data5, list->next->next->next->next->data);
	_listclear(&list);

	if (res == 0)
		return (0);
	else
		return (-1);
}
