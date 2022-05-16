#include <stdio.h>

// A[] tableau
// n taille tableau
// k avancement du for step
int whatDoesItDo(int A[], int n, int k) {
    // initialisation de result en négatif, current est forcement positif d'ou ce choix
    int result = -1000;
    for (int i=1;i<=n;i++) {
        int current = 0;
        // on commence en i de 1 a 6 oar pas de k donc maxi en 2 boucles on a terminé
        // on cheche a additionner 1 nombre sur k au sein du tableau * n (la taille du tableau)
        // a chaque fois result correspond au max des differents currents
        // in fine le premier iteration est prise normalement
        for (int j=i;j<=n;j+=k) {
            current = current + A[j];
        } // A[1], A[4], 3 * 2 = 6
        if (current > result) {
            result = current;
        }
    }
    // 12 est retourne
    return result;
}


int main() {
    int A[] = {1,3,5,4,2,6,8 };
    int k = 3;
    whatDoesItDo(A, 6, k);
    printf("Hello, World!\n");
    return 0;
}
