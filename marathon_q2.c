#include <stdio.h>

int highest_digit(int n) {
    if (!n) {
        return 0;
    }
    int temp_highest = highest_digit(n/10);
    return temp_highest > n%10 ? temp_highest : n%10;
}

int main() {
    printf("highest digit: %d\n", highest_digit(76854));
}
