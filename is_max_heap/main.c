#include <stdio.h>

int lchild(int i) { return 2 * i + 1; }

int rchild(int i) { return 2 * i + 2; }

int isMaxHeapRecursive(int A[], int i, int n) {
    if (i >= n) // A NIL node is a max􀀀heap
        return 1;
    else if (lchild(i) >= n && rchild(i) >= n) // A leaf node is a max􀀀heap
        return 1;
    if ((lchild(i) < n && A[i] < A[lchild(i)])
        || (rchild(i) < n && A[i] < A[rchild(i)]))
        return 0;
    return isMaxHeapRecursive(A, lchild(i), n)
           & isMaxHeapRecursive(A, rchild(i), n);
}

int isMaxHeapIterative(int A[], int n) {
    int i;
    for (i = 0; i < n / 2; i++) {
        if (lchild(i) < n && A[lchild(i)] > A[i])
            return 0;
        if (rchild(i) < n && A[rchild(i)] > A[i])
            return 0;
    }
    return 1;
}


int findKthLargest(int A[], int n, int k) {
    int s, i;
    int H[n];
    for (i = 0; i < n; i++)
        H[i] = A[i];
    s = n;
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(H, i, s);
    for (i = 0; i < n-k; i++) {
        H[0] = H[s - 1];
        s--;
        minHeapify(H, 0, s);
    }
    return H[0];
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
