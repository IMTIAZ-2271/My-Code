#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    // declare head, tail, cur and other variables you need
    node *head;
    node *tail;
    node *cur;
    int size;
    int curInd;
} linkedList;

void init(linkedList *list)
{
    // implement initialization
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
    list->curInd = -1;
}

void free_list(linkedList *list)
{
    // implement destruction of list
    node *current = list->head;
    node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void print(linkedList *list)
{
    // implement list printing
    if (list->head == NULL)
    {
        printf("[ . ]\n");
        return;
    }
    else
    {
        printf("[ ");
        node *temp = list->head;

        while (temp != NULL)
        {
            if (temp == list->cur)
            {
                printf("%d| ", temp->element);
            }
            else
            {
                printf("%d ", temp->element);
            }
            temp = temp->next;
        }
        printf("]\n");
    }
}

void insert(int item, linkedList *list)
{
    // implement insert function
    node *newNode = (node *)malloc(sizeof(node));
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        list->cur = newNode;
        list->curInd = 0;
    }
    else if (list->cur == list->tail)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
        list->cur = newNode;
        list->curInd++;
    }
    else
    {
        newNode->next = list->cur->next;
        newNode->prev = list->cur;
        list->cur->next->prev = newNode;
        list->cur->next = newNode;
        list->cur = newNode;
        list->curInd++;
    }
    list->size++;
}

int delete_cur(linkedList *list)
{
    // implement deletion of current index function
    if (list->head == NULL || list->cur == NULL)
    {
        return -1;
    }
    else
    {
        int deletedValue = list->cur->element;
        node *toDelete = list->cur;

        if (list->cur == list->head && list->cur == list->tail)
        {
            list->head = NULL;
            list->tail = NULL;
            list->cur = NULL;
            list->curInd = -1;
        }
        else if (list->cur == list->head)
        {
            list->head = list->head->next;
            list->head->prev = NULL;
            list->cur = list->head;
        }
        else if (list->cur == list->tail)
        {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
            list->cur = list->tail;
            list->curInd--;
        }
        else
        {
            list->cur->prev->next = list->cur->next;
            list->cur->next->prev = list->cur->prev;
            list->cur = list->cur->next;
        }
        free(toDelete);
        list->size--;
        return deletedValue;
    }
}

void append(int item, linkedList *list)
{
    // implement append function
    node *newNode = (node *)malloc(sizeof(node));
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        list->cur = newNode;
        list->curInd = 0;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

int size(linkedList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, linkedList *list)
{
    // implement prev function
    while (n-- > 0 && list->cur != NULL && list->cur->prev != NULL)
    {
        list->cur = list->cur->prev;
        list->curInd--;
    }
}

void next(int n, linkedList *list)
{
    // implement next function
    while (n-- > 0 && list->cur != NULL && list->cur->next != NULL)
    {
        list->cur = list->cur->next;
        list->curInd++;
    }
}

int is_present(int n, linkedList *list)
{
    // implement presence checking function
    node *current = list->head;
    while (current != NULL)
    {
        if (current->element == n)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void clear(linkedList *list)
{
    // implement list clearing function
    free_list(list);
    init(list);
    list->curInd = -1;
}

int delete_item(int item, linkedList *list)
{
    // implement item deletion function
    if (!is_present(item, list))
    {
        return 0;
    }
    else
    {
        node *current = list->head;
        int itemindex = 0;
        while (current != NULL)
        {
            if (current->element == item)
            {
                if (current == list->cur)
                {
                    delete_cur(list);
                    return 1;
                }
                else if (current == list->head)
                {
                    list->head = list->head->next;
                    if (list->head != NULL)
                    {
                        list->head->prev = NULL;
                    }
                    list->cur = list->head;
                    free(current);
                    list->size--;
                    list->curInd = 0;
                    return 1;
                }
                else if (current == list->tail)
                {
                    list->tail = list->tail->prev;
                    if (list->tail != NULL)
                    {
                        list->tail->next = NULL;
                    }
                    list->cur = list->tail;
                    free(current);
                    list->size--;
                    if (list->curInd > (list->size))
                        list->curInd = list->size - 1;
                    return 1;
                }
                else
                {
                    list->cur = current->next;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    free(current);
                    list->size--;
                    list->curInd = itemindex;
                    return 1;
                }
            }
            current = current->next;
            itemindex++;
        }
    }
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    // implement swap function
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->size || ind2 >= list->size || ind1 == ind2)
    {
        return;
    }
    node *node1 = list->head;
    node *node2 = list->head;
    for (int i = 0; i < ind1; i++)
    {
        node1 = node1->next;
    }
    for (int i = 0; i < ind2; i++)
    {
        node2 = node2->next;
    }
    int temp = node1->element;
    node1->element = node2->element;
    node2->element = temp;
}

int search(int item, linkedList *list)
{
    // implement search function
    node *current = list->head;
    list->curInd = 0;
    while (current != NULL)
    {
        if (current->element == item)
        {
            list->cur = current;
            return list->curInd;
        }
        current = current->next;
        list->curInd++;
    }
    return -1;
}

int find(int ind, linkedList *list)
{
    // implement find function
    if (ind < 0 || ind >= list->size)
    {
        return -1;
    }
    node *current = list->head;
    int i;
    for (i = 0; i < ind; i++)
    {
        current = current->next;
    }
    list->curInd = i;
    list->cur = current;
    return current->element;
}

int update(int ind, int value, linkedList *list)
{
    // implement update function at metioned index position
    if (ind < 0 || ind >= list->size)
    {
        return -1;
    }
    node *current = list->head;
    for (int i = 0; i < ind; i++)
    {
        current = current->next;
    }
    int previous_value = current->element;
    current->element = value;
    list->cur = current;
    list->curInd = ind;
    return previous_value;
}

int trim(linkedList *list)
{
    // implement trim function
    if (list->tail == NULL)
    {
        return -1;
    }
    node *trimmed = list->tail;
    int trimmed_value = trimmed->element;
    if (list->head == list->tail)
    {
        free(trimmed);
        list->head = list->tail = list->cur = NULL;
        list->size = 0;
        list->curInd = -1;
        return trimmed_value;
    }
    list->tail = trimmed->prev;
    list->tail->next = NULL;
    if (list->cur == trimmed)
    {
        list->cur = list->tail;
    }
    list->size--;
    if (list->cur == list->tail)
    {
        list->curInd = list->size - 1;
    }
    free(trimmed);
    return trimmed_value;
}

void reverse(linkedList *list)
{
    // implement reverse function
    if (list->head == NULL || list->head == list->tail)
    {
        return;
    }
    node *current = list->head;
    node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        list->tail = list->head;
        list->head = temp->prev;
    }
    list->cur = list->head;
    for (int i = 0; i < list->curInd; i++)
    {
        list->cur = list->cur->next;
    }
}
// you can define helper functions you need