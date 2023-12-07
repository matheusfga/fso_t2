#include <stdio.h>
#include <stdlib.h>

#define N 110 // last N is a buffer for array manipulation
#define M 108 // last M is used to store the total time it took to process the process

int main() {
    int processes[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            processes[i][j] = 0;
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i][1]);
        processes[i][1]++;
        processes[i][0] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= processes[i][1]; j++) {
            scanf("%d", &processes[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        // printf("HERE 0\n");
        for (int j = 2; j <= processes[i][1]; j++) {
            // printf("HERE 1\n%d %d\n", processes[i][0], processes[i][j]);
            if (processes[i][j]) {
                // printf("HERE 2\n%d\n", processes[i][j]);
                for (int k = 0; k <= processes[i][1]; k++) {
                    processes[n][k] = processes[i][k];
                    if (k == j) {
                        // printf("HERE 3\n");
                        processes[n][k] = 0;
                    }
                }
                for (int k = i; k < n; k++) {
                    for (int l = 0; l <= processes[k][1]; l++) {
                        processes[k][l] = processes[k + 1][l];
                    }
                }
                --i;
                break;
            } else {
                // printf("HERE ADD\n");
                processes[i][M - 1] += 10;
                for (int k = 2; k < processes[i][1]; k++) {
                    // printf("HERE ADD LOOP\n");
                    processes[i][k] = processes[i][k + 1];
                }
                processes[i][1]--;
                --j;
            }
        }
    }

    int partial_time = 0;
    for (int i = 0; i < n; i++) {
        printf("%d (%d)\n", processes[i][0], processes[i][M - 1] + partial_time);
        partial_time += processes[i][M - 1];
    }
    return 0;
}