#include <stdio.h>

struct train {
    struct waggon* first;
};

struct waggon {
    int id;
    int type;
    struct waggon* next;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
