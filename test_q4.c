#include <stdio.h>

#define ROWS_NUM 4
#define ROWS_SEATS 7
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

typedef struct {
    int row;
    int seat;
} movie_seat;


movie_seat find_seat(int theater[][ROWS_SEATS], unsigned int n, unsigned int r, unsigned int d) {
    int i;
    int *address_of_sequence;
    movie_seat seat;

    for (i=r-1; i<ROWS_NUM; i++) {
        address_of_sequence = find_sequence(theater[i]+d, theater[i]+ROWS_SEATS-d, n, 0);
        if (address_of_sequence != NULL) {
            seat.row = i+1;
            seat.seat = (int) (address_of_sequence - theater[i]) +1;
            return seat;
        }
    }
    seat.row = 0;
    seat.seat = 0;
    return seat;
}

int main() {
    movie_seat seat;
    //call function seat = find_seat(....);
    printf("seat found at %d %d", seat.row, seat.seat);


}