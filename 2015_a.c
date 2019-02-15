#include <stdio.h>

int* bisearch(int a[], int size, int n) {
    if (size == 0) {
        return NULL;
    }
    if (n > a[size/2]) {
        return bisearch(a+(size/2)+1, size/2-1 + (size%2!=0), n);
    } else if (n < a[size/2]){
        return bisearch(a, size/2, n);
    }
    return a + size/2;
}


int main() {
    int a[] = {2,6,8,11,15,18,24,29,30};

    if (bisearch(a, 9, 15) == NULL) {
        printf("it wasn't found\n");
    } else {
        printf("it was found\n");
    }

    return 0;
}

