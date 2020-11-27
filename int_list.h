/*
** EPITECH PROJECT, 2020
** int_list
** File description:
** int_list function declarations
*/

#ifndef __INT_LIST_H__
#define __INT_LIST_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct int_list t_int_list;

// int_list_destroy : libère toutes les ressources allouées
void int_list_destroy(t_int_list **list);

// int_list_size : calcule la taille de la liste
size_t int_list_size(t_int_list *list);
// int_list_value : renvoie la valeur du noeud donné en paramètre
int int_list_value(t_int_list *list);

// int_list_push_front : ajoute un élément en tête de liste avec l'entier passé en paramètre
void int_list_push_front(t_int_list **list, int value);
// int_list_push_back : ajoute un élément en fin de liste avec l'entier passé en paramètre
void int_list_push_back(t_int_list **list, int value);

// int_list_pop_front : retire un élément en tête de liste en renvoie l'entier associé
int int_list_pop_front(t_int_list **list);
// int_list_pop_back : retire un élément en fin de liste en renvoie l'entier associé
int int_list_pop_back(t_int_list **list);

// int_list_get : récupère le nieme noeud de la liste
t_int_list *int_list_get(t_int_list *list, size_t index);

// int_list_find_first : renvoie le premier noeud contenant la valeur passée en paramètre
t_int_list *int_list_find_first(t_int_list *list, int value);
// int_list_find_last : renvoie le dernier noeud contenant la valeur passée en paramètre
t_int_list *int_list_find_last(t_int_list *list, int value);

// int_list_rotate_left : applique une rotation sur la gauche de la liste
void int_list_rotate_left(t_int_list **list);
// int_list_rotate_right : applique une rotation sur la gauche de la liste
void int_list_rotate_right(t_int_list **list);

// int_list_iterate : applique la fonction passée en paramètre sur l'ensemble des noeuds de la liste
void int_list_iterate(t_int_list *list, void *data, void (*iterator)(void *data, size_t index, int *value));

// int_list_print : affiche les valeurs de la liste en utilisant int_list_iterate
void int_list_print(t_int_list *list, const char *message);

// int_list_apply : applique la fonction donnée en paramètre aux éléments de la liste
void int_list_apply(t_int_list *list, void *data, int (*func)(void *data, size_t index, int value));

// int_list_clone : clone la liste donnée en paramètre
t_int_list *int_list_clone(t_int_list *list);

// int_list_filter : clone la liste donnée en paramètre en la filtrant grâce à la fonction passée en paramètre
t_int_list *int_list_filter(t_int_list *list, void *data, bool (*filter)(void *data, size_t index, int value));

// int_list_concatenate : ajouter la seconde liste à la première
void int_list_concatenate(t_int_list **list, t_int_list *other);

// int_list_reverse : renverse la liste passée en paramètre
void int_list_reverse(t_int_list **list);

// int_list_sum : calcule la somme de tous les entiers présents dans la liste
int int_list_sum(t_int_list *list);
// int_list_max : renvoie le plus grand entier présent dans la liste (non NULL)
int int_list_max(t_int_list *list);
// int_list_max : renvoie le plus petit entier présent dans la liste (non NULL)
int int_list_min(t_int_list *list);

// int_list_sort : trie la liste du plus petit au plus grand
void int_list_sort(t_int_list **list);

#endif /* __INT_LIST_H__ */