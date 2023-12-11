#include <stdio.h>
#include <stdlib.h>

#define N (int) 10e4 + 5

int main() {
    int q, n;
    int ps[N];
    scanf ("%d %d", &q, &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &ps[i]);
    }

    int total = 1, aux = 1;
    int pages[N]; // queue

    for (int i = 0; i < q; i++) {
        pages[i] = -100;
    }

    pages[0] = ps[0];
    for (int i = 1; i < n; i++) {
        int in_q = 0;
        for (int j = 0; j < q; j++) {
            if (ps[i] == pages[j]) {
                // printf ("HERE: %d q: %d j: %d\n", ps[i], pages[j], j);
                in_q = 1;
                break;
            }
        }
        if (!in_q) {
            pages[aux] = ps[i];
            ++aux;
            ++total;
        }
        if (aux == q) {
            aux = 0;
        }
        // printf ("p: %d t: %d\n", ps[i], total);
    }

    printf ("%d\n", total);
    return 0;
}