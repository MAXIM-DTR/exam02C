/*
** sort_list
**
** Trie une liste chainee en utilisant la fonction cmp.
** cmp retourne un entier positif si le 1er arg doit
** venir apres le 2nd, 0 si egal, negatif sinon.
**
** Struct:
**   typedef struct s_list {
**     struct s_list *next;
**     void          *data;
**   } t_list;
**
** Prototype:
**   t_list *sort_list(t_list *begin_list, int (*cmp)(int, int))
*/
