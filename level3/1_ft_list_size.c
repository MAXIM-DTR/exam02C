/*
** ft_list_size
**
** Retourne le nombre d elements dans une liste chainee.
**
** Struct:
**   typedef struct s_list {
**     struct s_list *next;
**     void          *data;
**   } t_list;
**
** Prototype: int    ft_list_size(t_list *begin_list)
*/
 #include <stdlib.h>

 typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int    ft_list_size(t_list *begin_list)
{
    int len;

    len = 0;

    while (begin_list != NULL)
    {
        len++;
        begin_list = begin_list->next;
        return (0);
    }
}