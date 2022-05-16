#include <stdio.h>

// precond : array [1..k..n], k intergers, i=1, j=i..n
//postcond : SIGMA of k largest elements in A, ca correspond a notre return
int algo1(int A[], int n, int k) {
    int sum = 0; // 1 un acces
    for (int i=1;i<=k;i++) { //k+1
        int maxi = i;

        for (int j=i;i<n;j++) {
            if (A[j] > A[maxi]) {
                maxi = j;
            }
        }

        sum = sum + A[maxi];
        int swp = A[i];
        A[i] = A[maxi];
        A[maxi] = swp;
    }

    return sum;
}



int main() {
    printf("Hello, World!\n");
    return 0;
}
