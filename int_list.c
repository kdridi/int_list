/*
** EPITECH PROJECT, 2020
** int_list
** File description:
** int_list function definitions
*/

#include "int_list.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct int_list
{
    int value;
    struct int_list *next;
};

void int_list_destroy(t_int_list **list)
{
    ((void) list);
}

size_t int_list_size(t_int_list *list)
{
    ((void) list);
    return (0);
}

int int_list_value(t_int_list *list)
{
    ((void) list);
    return (0);
}

void int_list_push_front(t_int_list **list, int value)
{
    ((void) list);
    ((void) value);
}

void int_list_push_back(t_int_list **list, int value)
{
    ((void) list);
    ((void) value);
}

int int_list_pop_front(t_int_list **list)
{
    ((void) list);
    return (0);
}

int int_list_pop_back(t_int_list **list)
{
    ((void) list);
    return (0);
}

t_int_list *int_list_get(t_int_list *list, size_t index)
{
    ((void) list);
    ((void) index);
    return (NULL);
}

t_int_list *int_list_find_first(t_int_list *list, int value)
{
    ((void) list);
    ((void) value);
    return (NULL);
}

t_int_list *int_list_find_last(t_int_list *list, int value)
{
    ((void) list);
    ((void) value);
    return (NULL);
}

void int_list_rotate_left(t_int_list **list)
{
    ((void) list);
}

void int_list_rotate_right(t_int_list **list)
{
    ((void) list);
}

void int_list_iterate(t_int_list *list, void *data, void (*iterator)(void *data, size_t index, int *value))
{
    size_t index = 0;
    t_int_list *node = list;
    while (node != NULL) {
        iterator(data, index, &(node->value));
        node = node->next;
        index += 1;
    }
}

void int_list_print(t_int_list *list, const char *message) {
    ((void) list);
    ((void) message);
}

void int_list_apply(t_int_list *list, void *data, int (*func)(void *data, size_t index, int value)) {
    ((void) list);
    ((void) data);
    ((void) func);
}

t_int_list *int_list_clone(t_int_list *list) {
    ((void) list);
    return (NULL);
}

t_int_list *int_list_filter(t_int_list *list, void *data, bool (*filter)(void *data, size_t index, int value)) {
    ((void) list);
    ((void) data);
    ((void) filter);
    return (NULL);
}

void int_list_concatenate(t_int_list **list, t_int_list *other) {
    ((void) list);
    ((void) other);
}

void int_list_reverse(t_int_list **list)
{
    ((void) list);
}

int int_list_sum(t_int_list *list) {
    ((void) list);
    return (0);
}

int int_list_max(t_int_list *list) {
    ((void) list);
    return (0);
}

int int_list_min(t_int_list *list) {
    ((void) list);
    return (0);
}

void int_list_sort(t_int_list **list) {
    ((void) list);
}