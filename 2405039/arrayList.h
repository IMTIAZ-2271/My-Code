#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    // declare variables you need
    int *array;
    int size;
    int capacity;
    int curInd;
} arrayList;

void init(arrayList *list)
{
    // implement initialization
    list->capacity = 2;
    list->array = (int *)malloc(list->capacity * sizeof(int));
    list->size = 0;
    list->curInd = -1;
}

void free_list(arrayList *list)
{
    // implement destruction of list
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->curInd = -1;
    list->capacity = 0;
}

void increase_capacity(arrayList *list)
{
    // implement capacity increase
    if (list->size >= list->capacity / 2)
    {
        int newCap = list->capacity * 2;
        int *tmp = (int *)realloc(list->array, newCap * sizeof(int));
        if (tmp != NULL)
        {
            list->array = tmp;
            list->capacity = newCap;
        }
    }
}

void decrease_capacity(arrayList *list)
{
    // implement capacity decrease
    if (list->size <= list->capacity / 4 && list->size > 0 && list->capacity > 2)
    {
        int newCap = (int)(list->capacity / 2);
        if (newCap < 2)
            newCap = 2;
        int *temp = (int *)realloc(list->array, newCap * sizeof(int));
        if (temp != NULL)
        {
            list->array = temp;
            list->capacity = newCap;
        }
    }
}

void print(arrayList *list)
{
    // implement list printing
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    else
    {
        printf("[ ");
        for (int i = 0; i < list->size; i++)
        {
            if (i == list->curInd)
            {
                printf("%d| ", list->array[i]);
            }
            else
            {
                printf("%d ", list->array[i]);
            }
        }
        printf("]\n");
    }
}

void insert(int item, arrayList *list)
{
    // implement insert function
    if (list->size == 0)
    {
        list->array[0] = item;
        list->size++;
        list->curInd = 0;
        return;
    }
    for (int i = list->size - 1; i > list->curInd; i--)
    {
        list->array[i + 1] = list->array[i];
    }
    list->array[list->curInd + 1] = item;
    list->size++;
    list->curInd = list->curInd + 1;
    increase_capacity(list);
}

int delete_cur(arrayList *list)
{
    // implement deletion of element at current index position
    if (list->size == 0 || list->curInd < 0 || list->curInd >= list->size)
    {
        return -1;
    }
    int i, deleted_item = list->array[list->curInd];
    for (int i = list->curInd; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->curInd >= list->size)
    {
        list->curInd = list->size - 1;
    }
    decrease_capacity(list);
    return deleted_item;
}

void append(int item, arrayList *list)
{
    // implement append function
    list->array[list->size] = item;
    if (list->size == 0)
    {
        list->curInd = 0;
    }
    list->size++;
    increase_capacity(list);
}

int size(arrayList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList *list)
{
    // implement prev function
    if (list->curInd - n < 0)
    {
        list->curInd = 0;
        return;
    }
    list->curInd -= n;
}

void next(int n, arrayList *list)
{
    // implement next function
    if (list->curInd + n >= list->size)
    {
        list->curInd = list->size - 1;
        return;
    }
    list->curInd += n;
}

int is_present(int n, arrayList *list)
{
    // implement presence checking function
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

void clear(arrayList *list)
{
    // implement list clearing function
    free_list(list);
    list->array = (int *)realloc(list->array, 2 * sizeof(int));
    list->capacity = 2;
}

int delete_item(int item, arrayList *list)
{
    // implement item deletion function
    if (!is_present(item, list))
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < list->size; i++)
        {
            if (list->array[i] == item)
            {
                for (int j = i; j < list->size - 1; j++)
                {
                    list->array[j] = list->array[j + 1];
                }
                list->size--;
                list->curInd = i;
                decrease_capacity(list);
                return 1;
            }
        }
    }
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    // implement swap function at metioned index position
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size || ind1 == ind2)
    {
        return;
    }
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
}

int search(int item, arrayList *list)
{
    // implement search function
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            list->curInd = i;
            return i;
        }
    }
    list->curInd = list->size - 1;
    return -1;
}

int find(int ind, arrayList *list)
{
    // implement find function
    if (ind < 0 || ind >= list->size)
    {
        return -1;
    }
    list->curInd = ind;
    return list->array[ind];
}

int update(int ind, int value, arrayList *list)
{
    // implement update function at metioned index position
    if (ind < 0 || ind >= list->size)
    {
        return -1;
    }
    int previous_value = list->array[ind];
    list->array[ind] = value;
    list->curInd = ind;
    return previous_value;
}

int trim(arrayList *list)
{
    // implement trim function
    if (list->size == 0)
    {
        return -1;
    }
    int trimmed_value = list->array[list->size - 1];

    if (list->curInd == list->size - 1 && list->curInd >= 0)
    {
        list->curInd--;
    }
    list->size--;
    decrease_capacity(list);
    return trimmed_value;
}

void reverse(arrayList *list)
{
    // implement reverse function
    int left_index = 0;
    int right_index = list->size - 1;
    while (left_index < right_index)
    {
        int temp = list->array[left_index];
        list->array[left_index] = list->array[right_index];
        list->array[right_index] = temp;
        left_index++;
        right_index--;
    }
}

// you can define helper functions you need