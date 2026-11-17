/*
** list.h - header fourni par 42 pour sort_list
** IMPORTANT: data est un INT ici (pas void* comme dans ft_list.h)
** Ne pas confondre avec ft_list.h qui a void* data
*/
#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	int				data;  /* data est un INT, pas void* */
}	t_list;

#endif
