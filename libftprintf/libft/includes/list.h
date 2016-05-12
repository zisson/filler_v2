/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 13:30:33 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 14:00:18 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <string.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	void				*data;
}						t_list_node;

typedef struct			s_list_db
{
	struct s_list_node	*first;
	struct s_list_node	*last;
}						t_list_db;

/*
** FUNCTION LIST DOUBLE
*/
t_list_db				*ft_listdb_create(void);
void					ft_listdb_destroy(t_list_db *list);
void					ft_listdb_destroy_free(t_list_db *list);
t_list_node				*ft_listdb_create_node(void *elm);
void					ft_listdb_destroy_node(t_list_node *n);
void					ft_listdb_destroy_node_free(t_list_node *n);
t_list_node				*ft_listdb_put(t_list_db *list, void *elm);
t_list_node				*ft_listdb_put_head(t_list_db *list, void *elm);
t_list_node				*ft_listdb_put_tail(t_list_db *list, void *elm);
t_list_node				*ft_listdb_pop_head(t_list_db *list);
t_list_node				*ft_listdb_pop_tail(t_list_db *list);
t_list_node				*ft_listdb_tail(t_list_db *list);
t_list_node				*ft_listdb_head(t_list_db *list);
void					ft_listdb_rm(t_list_db *list, t_list_node *node);
void					ft_listdb_rm_free(t_list_db *list, t_list_node *node);
void					ft_listdb_sort(t_list_db *list, int (*cmp)(const void *,
			const void *));
void					ft_listdb_reverse(t_list_db *list);
void					ft_listdb_prepend(t_list_db *list, t_list_node *node);
void					ft_listdb_append(t_list_db *list, t_list_node *node);
int						ft_listdb_apply(t_list_db *list,
		int (*fct)(void *, void *), void *arg);
/*
** FUNCTION LIST SIMPLE
*/
void					ft_lstadd(t_list **alst, t_list *varnew);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *,
			size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lst_push_back(t_list **tmp, t_list *tmp2);

#endif
