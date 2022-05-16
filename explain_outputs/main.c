#include <stdio.h>
typedef struct my_struct {
    int *a;
    char b;
    double c[4];
    struct my_struct* d;
} my_struct;

int main() {
    int pos1 = 24;
    int pos2 = pos1;

    my_struct x = {
            NULL,
            '0',
            {1.1, 2.2, 3.3, 4.4},
            NULL
    };

    x.a = &pos1;
    x.b = 'X';

    my_struct *y;
    y->a = &pos2;
    *(y->a) = (*(x.a))++;
    y->b = 'Y';
    y->d = &x;

    my_struct z[15];
    z[7] = x;
    z[9] = *y;

    my_struct* w[15];
    w[7] = &x;
    w[9] = y;

    printf("%c\n", z[9].d->b);
    printf("%c\n", w[9]->d->b);
    return 0;
}
