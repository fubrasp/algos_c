#include <stdio.h>
#include <stdlib.h>

//le radix tree, le noeud ne contient pas la valeur
struct node {
    int hasVal;
    struct node* left;
    struct node* right;
};

void display(char str[], int N){
    int i;
    for(i= 0;i<=N;i++){
        printf("%c",str[i]);
    }
    printf("\n");
}

void preOrder(struct node* root, int i, int level) {
    if (root == NULL) return;
    if (root->hasVal == 1) printf("%0*d\\n", level, i);
    preOrder(root->left, 10*i, level+1);
    preOrder(root->right, 10*i+1, level+1);
}

struct node* insert(struct node* p, char s [], int i, int n) {
    if (p == NULL) {
        p = malloc(sizeof(struct node));
        p->hasVal = 0;
        p->left = NULL;
        p->right = NULL;
    }

    if (i == n) p->hasVal = 1;
    else if (s[i] == 'O') {
        p->left = insert(p->left, s, i+1, n);
    }
    else p->right = insert(p->right, s, i+1, n);
    return p;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
