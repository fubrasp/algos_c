#include <stdlib.h>
#include <stdio.h>

// Quelle valeur s'affiche ?
/*
int main() {
    int *a;
    int *b;
    int c = 5;
    a = &c;
    c++;
    *a = -10;
    b = &c;
    c = 15;
    *b = *a / 2;
    printf("%d -- %d", *a, *b);
    return 0;
}
*/

/*
int main() {
    int a = 1;
    int *b = &a;
    int *c = malloc(sizeof (int));
    *c = 3;
    printf("%d\n", a + *b);
    free(c);
    printf("%d\n", *c);
    free(b); // PLANTE ICI FREE SUR ADDRESS VIA a
    printf("5\n");
    free(&a); // PLANTE ICI FREE SUR ADDRESS
    printf("7\n");
    free(c); //PLANTE ICI DEJA FREE
    printf("9\n");
    return 0;
}
*/