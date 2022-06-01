#include <stdio.h>

struct TreeNode {
    int key;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
};
struct TreeNode *root;

void printRange(struct TreeNode *p,
                int rangeMin,
                int rangeMax
) {
    if (NULL == p)
        return;
    if (rangeMin <= p->data)
        printRange(p
                           ->left, rangeMin, rangeMax);
    if (rangeMin <= p->data && rangeMax >= p->data)
        printf("%d ", p->data);
    if (p->data <= rangeMax)
        printRange(p
                           ->right, rangeMin, rangeMax);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
