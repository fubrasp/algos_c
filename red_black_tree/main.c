#define black 0
#define red 1

#include <stdio.h>

struct rb_node {
    int key, color;
    struct rb_node *left, *right, *parent;
}

int same_number_of_black_nodes(struct rb_node* node) {
    if (node == NULL) return 0;

    int left
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
