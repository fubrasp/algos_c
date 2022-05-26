#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insert(struct TreeNode *root, int val) {
    struct TreeNode *newTreeNode = NULL;
    struct TreeNode *current = root;
    if (root == NULL) {
        newTreeNode = malloc(sizeof(struct TreeNode));
        newTreeNode->val = val;
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        return newTreeNode;
    }
    if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

struct TreeNode *search(struct TreeNode *root, int val) {
    struct TreeNode *current = root;
    while (current != NULL && current->val != val) {
        if (val < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

struct TreeNode *delete(struct TreeNode *root, int val) {
    // cherchons la valeur val soit x
    struct TreeNode *x = search(root, val);
    //si x == NULL on pourrait retourner NULL mais bon
    if (x == NULL) {
        return root;
    }
    // initions le noeud courant
    struct TreeNode *u = root;
    // initions le parent du noeud courant
    struct TreeNode *parent = NULL; // parent of tree node with value = val
    // avancons dans l'arbre pour trouver l element courant et au final initier le parent
    while (u != x) {
        parent = u;
        //on avance au final en suivant la valeur du noeud recherche : rappel arbre binaire de recherche
        if (x->val < u->val) {
            u = u->left;
        } else {
            u = u->right;
        }
    }
// Leaf and root case also handled in the no right or left branch. Since if
// it’s leaf, its null anyway.
    //pas de branche a droite
    if (u->right == NULL) { // there is no right branch
        //suppression du parent par ecrasement de pointeur
        if (parent == NULL) { // delete root
            root = u->left;
        } else if (parent->left == u) { // if it’s a left child, make left the new child
            parent->left = u->left;
        } else {
            parent->right = u->left;
        }
        //pas de branche a gauche
    } else if (u->left == NULL) { // there is no left branch
        //suppression du parent par ecrasement de pointeur
        if (parent == NULL) { // delete root
            root = u->right;
        } else if (parent->left == u) { // if it’s a left child, make right the new child
            parent->left = u->right;
        } else {
            parent->right = u->right;
        }
        //on a des enfants
    } else {
        struct TreeNode *p = x->left;
        struct TreeNode *q = p;
        while (p->right != NULL) { // whilst right is null
            q = p;
            p = p->right;
        }
        //suppression du parent par ecrasement de pointeur
        if (parent == NULL) { // if we are at root
            root = p;
        } else if (parent->left == u) { // if its a left child
            parent->left = p;
        } else { // if its a right child
            parent->right = p;
        }
        p->right = u->right;
        if (q != p) {
            q->right = p->left;
            p->left = u->left;
        }
    }
    free(u);
    return root;
}

void printTreeRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        printf(" %d −− %d\n", root->val, root->left->val);
        printTreeRecursive(root->left);
    }
    if (root->right != NULL) {
        printf(" %d −− %d\n", root->val, root->right->val);
        printTreeRecursive(root->right);
    }
}

void printTree(struct TreeNode* root) {
    printf("graph g {\n");
    printTreeRecursive(root);
    printf("}\n");
}