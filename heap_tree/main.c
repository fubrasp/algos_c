#include <stdio.h>

/*
    Consider an array a[0:::n􀀀1]. Write a function int isMaxHeap(int a[], int
    i, int n) that returns true if array[i:::n􀀀1] represents max-heap, otherwise
    it returns false. You can write your implementation using C or pseudocode.
 */
int isMaxHeap(int a[], int i, int n) {
    if (i > ((n-2)/2)) {
        return i;
    }
    int leftCheck = 0;
    int rightCheck = 0;
    if (a[i] >= a[2*i+1]) {
        leftCheck = isMaxHeap(a, 2*i+1, n);
    }
    if (2*i + 2 < n) {
        if (a[i] >= a[2*i+2]) {
            rightCheck = isMaxHeap(a, 2*i+2, n);
        }
    }
    return leftCheck && rightCheck;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}