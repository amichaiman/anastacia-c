#include <stdio.h>
#include <string.h>

int has_c(char str[][4], int size, char c) {
    int i;

    for (i=0; i<size; i++) {
        if (strchr(str[i],c) == NULL) {
            return 0;
        }
    }
    return 1;
}

int is_telescopic(char str[][4], int size) {
    int i, j;

    for (i=size-1; i>=0; i--) {
        for (j=0; j<strlen(str[i]); j++) {
           if (!has_c(str, i, str[i][j])) {
               return 0;
           }
        }
    }
    return 1;
}


int main() {
    char str[4][4] = { "abc", "ac", "aca", "cd" };

    printf("it is%s telescopic\n", is_telescopic(str, 4) ? "" : "n't");
}

