/*
** ft_list_remove_if
**
** Supprime de la liste tous les noeuds pour lesquels
** cmp(node->data, data_ref) == 0.
** Libere les noeuds supprimes avec free.
**
** Struct:
**   typedef struct s_list {
**     struct s_list *next;
**     void          *data;
**   } t_list;
**
** Prototype:
**   void ft_list_remove_if(t_list **begin_list, void *data_ref,
**                          int (*cmp)(), void (*free_fct)(void *))
*/
