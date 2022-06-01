#include <stdio.h>

int main() {
    printf("Values of A separated by spaces (non-number to stop): ");
    int timestamps[MAX_LENGTH];
    int pos = 0;
    while (scanf("%d", &timestamps[pos]) == 1) { pos++; }
    insertion_sort(timestamps, pos);
    int longest_gap = 0;
    for (int i = 1; i < pos; i++) {
        int gap = timestamps[i] - timestamps[i - 1];
        if (gap > 1 && gap > longest_gap) { longest_gap = gap; }
    }
    printf("Longest gap: %d\n", longest_gap);
    printf("Oldest timestamp: %d\n", timestamps[0]);
    printf("Most recent timestamp: %d\n", timestamps[pos - 1]);
    return 0;
}