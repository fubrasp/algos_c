#include <stdio.h>

int get_length(char *a);

int is_vowel(char letter) {
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'a' ||
        letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') { return 1; }
    else { return 0; }
}

int count_vowels(char A[]) {
    int count_vowels = 0;
    int pos = 0;
    while (A[pos] != '\0') {
        if (is_vowel(A[pos])) { count_vowels++; }
        pos++;
    }
    return count_vowels;
}

void BS(char A[]) {
    int count_v = count_vowels(A);
    const int new_len = get_length(A) + 2 * count_v;
    char bsprache[new_len + 1];
    int pos_input = 0;
    int pos_bsprache = 0;
    while (A[pos_input] != '\0') {
        if (is_vowel(A[pos_input])) {
            bsprache[pos_bsprache] = A[pos_input];
            bsprache[pos_bsprache + 1] = 'b';
            bsprache[pos_bsprache + 2] = A[pos_input];
            pos_bsprache = pos_bsprache + 3;
        }
        else {
            bsprache[pos_bsprache] = A[pos_input];
            pos_bsprache = pos_bsprache + 1;
        }
        pos_input++;
    }
    bsprache[new_len] = '\0';
    printf("B-Sprache: %s\n", bsprache);
}

int get_length(char *a) {
    return sizeof (a) / sizeof (char);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
