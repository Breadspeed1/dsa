#include "linkedlist.h"
#include <stdlib.h>

#define TRUE (1);
#define FALSE (0);

typedef struct node node;

struct singlylinkedlist {
    node *head;
    node *tail;
    int size;
};

struct node {
    node *next;
    int value;
};

void add(singlylinkedlist *list, int value) {
    node* new = create_node(value);

    if (!list->head) {
        list->head = new;
        list->tail = new;
    }
    else {
        list->tail->next = new;
        list->tail = new;
    }

    list->size++;
}

int contains(singlylinkedlist *list, int value) {
    node* cur = list->head;

    while (cur) {
        if (cur->value == value) {
            return TRUE;
        }

        cur = cur->next;
    }

    return FALSE;
}

void remove(singlylinkedlist *list, int value) {
    if (list->head && list->head->value == value) {
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            node* del = list->head;
            list->head = list->head->next;


        }
    }
}

node* create_node(int value) {
    node* n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;

    return n;
}