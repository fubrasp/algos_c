#include <stdio.h>

struct Point2D {
    int x;
    int y;
};
struct Point2D* initNewPoint() {
    struct Point2D p;
    p.x = 4;
    p.y = 2;
    return &p;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
