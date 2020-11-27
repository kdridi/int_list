/*
** EPITECH PROJECT, 2020
** int_list
** File description:
** int_list unit tests
*/

#include "int_list.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

static int random_between(int start, int stop) {
    static bool initialized = false;

    if (start > stop)
        return random_between(stop, start);

    if (!initialized) {
        initialized = true;
        srand(time(NULL));
    }

    return start + (rand() % (stop - start));
}

static int *unique_values(int count, int start, int stop) {
    int *values = malloc(sizeof(*values) * count);
    assert(values != NULL);

    for (int i = 0; i < count; i++) {
        bool unique = true;
        int value;
        do {
            value = random_between(start, stop);
            for (int j = 0; unique == true && j < i; j++)
                unique = value != values[j];
        } while (unique == false);
        values[i] = value;
    }

    return (values);
}

void cr_assert_int_list_eq_iterator(void *data, size_t index, int *value) {
    int *values = data;
    cr_assert_eq(values[index], *value);
}

void cr_assert_int_list_eq(t_int_list *list, size_t size, int *values) {
    cr_assert_eq(int_list_size(list), size);
    int_list_iterate(list, values, cr_assert_int_list_eq_iterator);
}

Test(int_list_destroy, should_work_when_empty) {
    t_int_list *list = NULL;

    int_list_destroy(&list);
    cr_assert_null(list);
}

Test(int_list_destroy, should_work_when_not_empty) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, random_between(0, 10000));

    int_list_destroy(&list);
    cr_assert_null(list);
}

Test(int_list_size, should_work_when_empty) {
    t_int_list *list = NULL;

    cr_assert_eq(int_list_size(list), 0);

    int_list_destroy(&list);
}

Test(int_list_size, should_work_when_not_empty) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, random_between(0, 10000));
    cr_assert_eq(int_list_size(list), count);

    int_list_destroy(&list);
}

Test(int_list_value, should_work) {
    t_int_list *list = NULL;
    int value = random_between(0, 10000);

    int_list_push_front(&list, value);
    cr_assert_eq(int_list_value(list), value);

    int_list_destroy(&list);
}

Test(int_list_get, should_return_null_when_empty) {
    t_int_list *list = NULL;

    cr_assert_eq(int_list_get(list, 0), NULL);

    int_list_destroy(&list);
}

Test(int_list_get, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, random_between(0, 10000));

    for (size_t i = 0; i < count; i++)
        cr_assert_eq(int_list_size(int_list_get(list, i)), count - i);
    cr_assert_eq(int_list_get(list, count), NULL);

    int_list_destroy(&list);
}

Test(int_list_push_front, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[count - (i + 1)]);
        cr_assert_not_null(list);
    }

    cr_assert_int_list_eq(list, count, values);

    int_list_destroy(&list);

    free(values);
}

Test(int_list_push_back, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++) {
        int_list_push_back(&list, values[i]);
        cr_assert_not_null(list);
    }

    cr_assert_int_list_eq(list, count, values);

    int_list_destroy(&list);

    free(values);
}

Test(int_list_pop_front, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[count - (i + 1)]);
    }

    for (size_t i = 0; i < count; i++) {
        cr_assert_eq(int_list_pop_front(&list), values[i]);
    }
    cr_assert_null(list);

    free(values);
}

Test(int_list_pop_back, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[count - (i + 1)]);
    }

    for (size_t i = 0; i < count; i++) {
        cr_assert_eq(int_list_pop_back(&list), values[count - (i + 1)]);
    }
    cr_assert_null(list);

    free(values);
}

Test(int_list_find_first, should_work_when_empty) {
    t_int_list *list = NULL;
    cr_assert_null(int_list_find_first(list, 0));
}

Test(int_list_find_first, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count + 1, 0, 10000);

    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    for (size_t i = 0; i < count; i++) {
        t_int_list *node = int_list_find_first(list, values[i]);
        cr_assert_not_null(node);
        cr_assert_eq(int_list_value(node), values[i]);
        cr_assert_eq(int_list_size(node), 2 * count - i);
    }

    cr_assert_null(int_list_find_first(list, values[count]));

    int_list_destroy(&list);

    free(values);
}

Test(int_list_find_last, should_work_when_empty) {
    t_int_list *list = NULL;
    cr_assert_null(int_list_find_last(list, 0));
}

Test(int_list_find_last, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count + 1, 0, 10000);

    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    for (size_t i = 0; i < count; i++) {
        t_int_list *node = int_list_find_last(list, values[i]);
        cr_assert_not_null(node);
        cr_assert_eq(int_list_value(node), values[i]);
        cr_assert_eq(int_list_size(node), count - i);
    }

    cr_assert_null(int_list_find_last(list, values[count]));

    int_list_destroy(&list);

    free(values);
}

Test(int_list_rotate_left, should_work_with_0_element) {
    t_int_list *list = NULL;

    int_list_rotate_left(&list);
    cr_assert_null(list);
}

Test(int_list_rotate_left, should_work_with_1_element) {
    t_int_list *list = NULL;
    int value = random_between(0, 10000);

    int_list_push_front(&list, value);
    int_list_rotate_left(&list);
    cr_assert_eq(int_list_value(list), value);
    
    int_list_destroy(&list);
}

Test(int_list_rotate_left, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    int_list_rotate_left(&list);
    
    int value = values[0];
    memmove(values + 0, values + 1, sizeof(*values) * (count - 1));
    values[count - 1] = value;

    cr_assert_int_list_eq(list, count, values);

    int_list_destroy(&list);

    free(values);
}

Test(int_list_rotate_right, should_work_with_0_element) {
    t_int_list *list = NULL;

    int_list_rotate_right(&list);
    cr_assert_null(list);
}

Test(int_list_rotate_right, should_work_with_1_element) {
    t_int_list *list = NULL;
    int value = random_between(0, 10000);

    int_list_push_front(&list, value);
    int_list_rotate_right(&list);
    cr_assert_eq(int_list_value(list), value);
    
    int_list_destroy(&list);
}

Test(int_list_rotate_right, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    int_list_rotate_right(&list);

    int value = values[count - 1];
    memmove(values + 1, values + 0, sizeof(*values) * (count - 1));
    values[0] = value;

    cr_assert_int_list_eq(list, count, values);

    int_list_destroy(&list);

    free(values);
}

Test(int_list_print, should_work) {
    t_int_list *list = NULL;
    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    const char *name = "list";
    char output[4096];
    memset(output, 0, sizeof(output));

    for (size_t i = 0; i < count; i++) {
        char message[256];
        sprintf(message, "%s[%zu]: %d\n", name, i, values[i]);
        strcat(output, message);
        int_list_push_back(&list, values[i]);
    }

    cr_redirect_stdout();
    int_list_print(list, name);
    cr_assert_stdout_eq_str(output);

    int_list_destroy(&list);
    cr_assert_null(list);

    free(values);
}

static int int_list_apply_func(void *data, size_t index, int value) {
    int *offset = data;
    return value * index + *offset;
}

Test(int_list_apply, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[count - (i + 1)]);
        cr_assert_not_null(list);
    }

    int offset = random_between(500, 10000);
    for (size_t i = 0; i < count; i++)
        values[i] = int_list_apply_func(&offset, i, values[i]);

    int_list_apply(list, &offset, int_list_apply_func);

    cr_assert_int_list_eq(list, count, values);

    int_list_destroy(&list);

    free(values);
}

Test(int_list_clone, should_work_when_empty) {
    t_int_list *list = NULL;
    t_int_list *clone = NULL;

    clone = int_list_clone(list);
    cr_assert_null(clone);
}

Test(int_list_clone, should_work) {
    t_int_list *list = NULL;
    t_int_list *clone = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);

    clone = int_list_clone(list);
    cr_assert_not_null(clone);

    cr_assert_int_list_eq(clone, count, values);

    int_list_destroy(&clone);
    int_list_destroy(&list);

    free(values);
}

Test(int_list_filter, should_work_when_empty) {
    t_int_list *list = NULL;
    t_int_list *filter = NULL;

    filter = int_list_filter(list, NULL, NULL);
    cr_assert_null(filter);
}

static bool int_list_filter_func(void *data, size_t index, int value) {
    int *offset = data;
    return (((value + index) % (*offset)) == 0);
}

Test(int_list_filter, should_work) {
    t_int_list *list = NULL;
    t_int_list *filter = NULL;

    size_t count = random_between(10, 30);
    int *values = unique_values(count, 0, 100000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[count - (i + 1)]);
    
    size_t offset = random_between(1, 4);

    size_t filter_count = 0;
    int *filter_values = malloc(sizeof(*filter_values) * count);
    for (size_t i = 0; i < count; i++) {
        if (int_list_filter_func(&offset, i, values[i])) {
            filter_values[filter_count] = values[i];
            filter_count += 1;
        }
    }

    filter = int_list_filter(list, &offset, int_list_filter_func);
    cr_assert_int_list_eq(filter, filter_count, filter_values);

    int_list_destroy(&filter);
    int_list_destroy(&list);

    free(filter_values);
    free(values);
}

Test(int_list_concatenate, should_work) {
    t_int_list *list = NULL;
    size_t list_count = random_between(5, 10);
    int *list_values = unique_values(list_count, 0, 10000);
    for (size_t i = 0; i < list_count; i++)
        int_list_push_front(&list, list_values[list_count - (i + 1)]);

    t_int_list *other = NULL;
    size_t other_count = random_between(5, 10);
    int *other_values = unique_values(other_count, 0, 10000);
    for (size_t i = 0; i < other_count; i++)
        int_list_push_front(&other, other_values[other_count - (i + 1)]);

    int *values = malloc(sizeof(*values) * (list_count + other_count));
    memcpy(values, list_values, list_count * sizeof(*values));
    memcpy(values + list_count, other_values, other_count * sizeof(*values));

    int_list_concatenate(&list, other);
    cr_assert_int_list_eq(list, list_count + other_count, values);

    int_list_destroy(&other);
    int_list_destroy(&list);

    free(values);
    free(other_values);
    free(list_values);
}

Test(int_list_reverse, should_work_when_empty) {
    t_int_list *list = NULL;

    int_list_reverse(&list);
    cr_assert_null(list);
}

Test(int_list_reverse, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[i]);

    int_list_reverse(&list);
    cr_assert_int_list_eq(list, count, values);
    
    int_list_destroy(&list);

    free(values);
}

Test(int_list_sum, should_work_when_empty) {
    t_int_list *list = NULL;

    cr_assert_eq(int_list_sum(list), 0);
}

Test(int_list_sum, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[i]);
        sum += values[i];
    }

    cr_assert_eq(int_list_sum(list), sum);
    
    int_list_destroy(&list);

    free(values);
}

Test(int_list_max, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    int max = values[0];
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[i]);
        if (i > 0 && max < values[i])
            max = values[i];
    }

    cr_assert_eq(int_list_max(list), max);
    
    int_list_destroy(&list);

    free(values);
}

Test(int_list_min, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    int min = values[0];
    for (size_t i = 0; i < count; i++) {
        int_list_push_front(&list, values[i]);
        if (i > 0 && min > values[i])
            min = values[i];
    }

    cr_assert_eq(int_list_min(list), min);
    
    int_list_destroy(&list);

    free(values);
}

static int int_list_sort_comparator(const void *a, const void *b) {
    const int *ai = a;
    const int *bi = b;

    return (*ai) - (*bi);
}

Test(int_list_sort, should_work) {
    t_int_list *list = NULL;

    size_t count = random_between(5, 10);
    int *values = unique_values(count, 0, 10000);
    for (size_t i = 0; i < count; i++)
        int_list_push_front(&list, values[i]);

    qsort(values, count, sizeof(*values), int_list_sort_comparator);

    int_list_sort(&list);
    int_list_iterate(list, values, cr_assert_int_list_eq_iterator);
    
    int_list_destroy(&list);

    free(values);
}
