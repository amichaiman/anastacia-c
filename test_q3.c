#include <stdio.h>

/* function returns 1 if starting at a, there are length nums*/
int sequence(int *a, int length, int num) {
    int i;
    for (i=0; i<length; i++) {
        if (a[i] != num) {
            return 0;
        }
    }
    return 1;
}


int *find_sequence(int *start, int *end, int length, int num) {
    while (start <= end-length) {
        if (sequence(start, length, num)) {
            return start;
        }
        start+=1;
    }
}
int main() {
    int a[] = {1, 2, 1, 1, 1, 4, 1, 1, 2, 1};
    printf("address of sequence %p\n", find_sequence(a, a+10, 3, 1));
}