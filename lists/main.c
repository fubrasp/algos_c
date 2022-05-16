#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node* head;
    struct node* tail;
};

struct node {
    int val;
    struct node* next;
};

void reverseList(struct list* l) {
    struct node* curr = l->head, *tmp = NULL;
    l->tail = l->head;
    l->head = NULL;

    while(curr != NULL) {
        tmp = curr->next; // je lis mon suivant par rapport a mon courant dans le parcours croissant de gauche a droite
        curr->next = l->head; // laisse moi faire un tour de passe pas avec que mon suivant pointe sur ma future tete
        l->head = curr; // laisse moi inverser ma lecture de la liste en reaffecttant a chaque fois ma tete de en prenant l'element actuel
        curr= tmp; // laisser moi passer a l'item suivant dans le parcours croissant de gauche a droite
    }
}

int main() {
    struct node * node3 = malloc(sizeof(struct node *));
    node3->val = 3;
    node3->next = NULL;

    struct node * node6 = malloc(sizeof(struct node *));
    node6->val = 6;
    node6->next = node3;

    struct node * node2 = malloc(sizeof(struct node *));
    node2->val = 2;
    node2->next = node6;

    struct node * node8 = malloc(sizeof(struct node *));
    node8->val = 8;
    node8->next = node2;

    struct node * node7 = malloc(sizeof(struct node *));
    node7->val = 7;
    node7->next = node8;

    struct list* l = malloc(sizeof(struct list *));
    l->head = node7;
    l->tail = node3;

    reverseList(l);

    free(l);
    free(node3);
    free(node6);
    free(node2);
    free(node8);
    free(node7);
}
