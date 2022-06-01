#include <stdio.h>

struct Person {
    char* name;
    int birthDateYear;
    float size;
};

int foo1(int a) {
    a = a % 3 + 5;
    return a;
}

int foo2(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = a[i] % 3 + 5;
        sum += a[i];
    }
    return sum;
}

void wrong_swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
 struct Person myOnlyFriend = {"Hans", 1996, 1.76};
    struct Person* personPtr = &myOnlyFriend;
    printf((*personPtr).name);
    printf("\n");

    printf(personPtr->name);
    printf("\n");

    int* a;
    int* b;
    int c = 5;
    a = &c;
    c++;
    *a = -10;
    b = &c;
    c = 15;
    *b = *a / 2;
    printf("%d -- %d", *a, *b);

    int x = 32;
    int y = foo1(x);
    printf("x = %d\n", x);
    printf("y = %d", y);

    int x2[] = {32, 33, 34};
    int y2 = foo2(x2, 3);
    printf("x = %d, %d, %d\n", x2[0], x2[1], x2[2]);
    printf("y = %d", y2);

    int a2 = 19;
    int b2 = 91;
    //wrong_swap(a2, b2);
    printf("\nfail swap\n%d", a2);

    int *ptrMince = 1;
    ++*ptrMince;
    //printf("\n++ptrMince\n%d", ptrMince);
    return 0;
 * */

int main() {
    /*
    int a = 42;
    int* b = &a;
    int** c = &b;
    *(*c) = *(*c) * 2;
    int*** d = &c;
    int x = ***&*d;
    printf("%d", x);
    return 0;
    */

    double x[10];
    double* pt;
    double* qt;
    pt = x;
    *pt = 0;
    *(pt + 2) = 1.61803;
    pt[5] = 2.5;
    pt = x + 2;
    qt = pt;
    *qt = 0.57721;
    qt[4] = 3.5;
    *(x + 8) = 6.7;
    pt = x;
    qt = x + 10;
    printf("%d\n", qt - pt);
    return 0;
}
