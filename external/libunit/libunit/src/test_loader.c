/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:41:33 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/17 13:18:11 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "colors.h"

int	g_max_len_size = 0;

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

static t_test	*create_node(char *test_name, t_test_func f, uint8_t flags)
{
	t_test	*new;
	int		len;

	new = malloc(sizeof(t_test));
	if (new == NULL)
		return (NULL);
	bzero(new, sizeof(t_test));
	if (ft_strlcpy(new->name, test_name, NAME_MAX_LENGHT - 1) > NAME_MAX_LENGHT)
		printf(YELLOW_L""ITALIC"WARNING: name too long -> truncated (%s)\n"END, new->name);
	len = strlen(new->name);
	if (len > g_max_len_size)
		g_max_len_size = len;
	new->id = 1;
	new->flags = flags;
	new->function = f;
	return (new);
}

static void	append_node(t_test **head, t_test *node)
{
	t_test	*current;

	if (*head == NULL)
		*head = node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		node->id = current->id + 1;
		current->next = node;
	}
}

void	test_loader(t_test **test_list, char *test_name, t_test_func function, uint8_t flags)
{
	t_test	*new;

	if (test_list == NULL)
		return ;
	new = create_node(test_name, function, flags);

	if (new == NULL)
	{
		printf(BOLD""RED"FATAL: malloc failed\n"END);
		return ;
	}
	append_node(test_list, new);
}
