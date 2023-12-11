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
    int pages_ps[N]; // queue
    int pages_lru[N];

    for (int i = 0; i < q; i++) {
        pages_ps[i] = -100;
        pages_lru[i] = -100;
    }

    pages_ps[0] = ps[0];
    pages_lru[0] = 0;
    int lru;
    for (int i = 1; i < n; i++) {
        int in_q = -1;
        for (int j = 0; j < q; j++) {
            if (ps[i] == pages_ps[j]) {
                // printf ("HERE: %d q: %d j: %d aux: %d\n", ps[i], pages_ps[j], j, aux);
                in_q = j;
                lru = pages_lru[j];
                pages_lru[j] = 0;
                // printf ("lru: %d\n", lru);
                break;
            } // think this whole pages_lru is broken, as it has to be updated each time some p is added or it is reused
        }
        if (in_q < 0) {
            // printf ("AQUI: aux: %d\n", aux);
            pages_ps[aux] = ps[i];
            pages_lru[aux] = 0;
            ++total;
            int aux2 = aux;
            ++aux;
            for (int j = 0; j < q; j++) {
                if (j == aux2) continue; // first of all, 0 can be a valid lru but will never be updated here
                if (pages_lru[j] >= 0) {
                    ++pages_lru[j];
                }
                if (pages_lru[j] == q - 1) {
                    aux = j;
                }
            }
        } else {
            int max_value = -1;
            for (int j = 0; j < q; j++) {
                if (j == in_q) continue; // first of all, 0 can be a valid lru but will never be updated here
                if (pages_lru[j] >= 0 && pages_lru[j] < lru) {
                    ++pages_lru[j];
                }
                if (pages_lru[j] == q - 1) {
                    aux = j;
                } // maybe change to a max value in this array and change aux outside the loop
            }
            for (int j = 0; j < q; j++) {
                if (pages_lru[j] > max_value) {
                    max_value = pages_lru[j];
                    aux = j;
                }
            }
            // printf ("ICI: in_q: %d aux: %d\n", in_q, aux);
        }
        if (aux == q) {
            aux = 0;
        }
        // printf ("p: %d t: %d\nLRUs: ", ps[i], total);
        // for (int j = 0; j < q; j++) {
        //     printf ("%d ", pages_lru[j]);
        // }
        // printf ("\n");
    }

    printf ("%d\n", total);
    return 0;
}