#include <stdio.h>
#include <string.h>


void replace(char *str, char c1, char c2) {
    if (str[0] == '\0') {
        return;
    }

    if (str[0] == c1) {
        str[0] = c2;
    }
    replace(str+1, c1, c2);
}

int is_replacement(char *str1, char *str2) {
    int i;
    int len = (int) strlen(str1);

    if (len != strlen(str2)) {
        return 0;
    }

    for (i=0; i<len; i++) {
        if (str1[i] != str2[i]) {
            replace(str1, str1[i], str2[i]);
            return (strcmp(str2, str1) == 0);
        }
    }
    return 1;
}

int main() {
    char str1[] = "seventeen";
    char str2[] = "seventeen";

    printf("it is%s replacement\n", is_replacement(str1, str2) ? "" : "n't");
    return 0;
}

