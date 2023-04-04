/*
** EPITECH PROJECT, 2022
** my_params_to_list.c
** File description:
** place params into list
*/

#include <stdlib.h>
#include <mylist.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    linked_list_t *element;

    list = NULL;

    for (int i = 0; i < ac; i++)  {
        element = malloc(sizeof(linked_list_t *));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}
