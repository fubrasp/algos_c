#include <stdio.h>

void even_odd_selection_sort(int A[], int n) {
    int even_array[n], odd_array[n];
    int odd_count = 0, even_count = 0;
    selection_sort(A, n);
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) {
            even_array[even_count] = A[i];
            even_count++;
        }
        else {
            odd_array[odd_count] = A[i];
            odd_count++;
        }
    }
    printf("Sorted even numbers: ");
    for (int i = 0; i < even_count; i++) { printf("%d ", even_array[i]); }
    printf("\nSorted odd numbers: ");
    for (int i = 0; i < odd_count; i++) { printf("%d ", odd_array[i]); }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
