#include <stdio.h>

#define FALSE 0
#define TRUE 1

int is_prime(int n) {
    int i;
    if(n == 2)
        return TRUE;
    if(n%2 == 0 || n<2)
        return FALSE;
    for(i=3; i<n/2; i+=2){
        if(n%i == 0)
            return FALSE;
    }
    return TRUE;
}
int main() {
    if (is_prime(-3)) {
        printf("it's prime\n");
    }
    return 0;
}