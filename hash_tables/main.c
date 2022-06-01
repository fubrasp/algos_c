#include <stdio.h>

int HTDelete(int k){
    int i=0;
    int probe = hash(k,i);
    int actualHashIdx= probe;
    while(i<m && HT[probe].status == 0 && HT[probe].key!=k){
        i++;
        probe = hash(k,i);
    }
    if(i>=m || HT[probe].status==-1) return -1;
        HT[probe].status = -1;
        HT[probe].key = -1;
        int j=(probe+1)%m;
        while(j!=actualHashIdx && HT[j].status!=-1){
            if(hash(HT[j].key,0)!=j) {
                int tmpKey = HT[j].key;
                HT[j].key = -1;
                HT[j].status = -1;
                HTInsert(tmpKey);
            }
            j = (j+1)%m;
        }
    22 return probe;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
