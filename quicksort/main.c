#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int i, int j) {
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

int Partition(int A [], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j=p;j<r;j++) {
        if (A[j] <= x) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i+1, r);
    return i+1;
}

struct Tuple {
    int q;
    int t;
};

struct Tuple* Partition2(int A [], int p, int r) {
    int x = A[p];
    int h;
    int i = h = p;
    for (int j=p+1; j<r; j++) {
        if (A[j] < x) {
            int y = A[j];
            A[j] = A[h+1];
            A[h+1] = A[i];
            A[i] = y;
            i++;
            h++;
        } else if (A[j] == x) {
            int y = A[j];
            A[j] = A[h+1];
            A[h+1] = y;
            h++;
        }
    }
    struct Tuple* res = malloc(sizeof(struct Tuple));
    res->q = i;
    res->t = h;
    return res;
}

void quicksort(int A [], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, p, q+1);
    }
}

void quicksort2(int A [], int p, int r) {
    if (p < r) {
        struct Tuple* res = Partition2(A, p, r);
        quicksort(A, p, res->q - 1);
        quicksort(A, p, res->t + 1);
    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
