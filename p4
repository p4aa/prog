//Implement multithreading for Matrix Multiplication using pthreads.

#include<stdio.h>
#include<pthread.h>
#define size 10

int a[size][size], b[size][size], c[size][size];
int rowa, rowb, cola, colb;

void *mul_thread(void *args) {
    int *rcargs = (int *)args;
    int i = rcargs[0], j = rcargs[1], k = rcargs[2];
    c[i][j] += a[i][k] * b[k][j];
    pthread_exit(NULL);
}

void accept(int m[size][size], int row, int col) {
    printf("Enter values for matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &m[i][j]);
}

void display(int m[size][size], int row, int col) {
    printf("\nMatrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }
}

int main() {
    int rcargs[3];
    pthread_t p[size][size][size];

    printf("Enter dimensions of matrix A (rows columns): ");
    scanf("%d %d", &rowa, &cola);
    accept(a, rowa, cola);

    printf("Enter dimensions of matrix B (rows columns): ");
    scanf("%d %d", &rowb, &colb);
    accept(b, rowb, colb);

    if (cola != rowb) {
        printf("\nMultiplication not possible!\n");
        return 0;
    }

    for (int i = 0; i < rowa; i++) {
        for (int j = 0; j < colb; j++) {
            for (int k = 0; k < cola; k++) {
                rcargs[0] = i;
                rcargs[1] = j;
                rcargs[2] = k;
                pthread_create(&p[i][j][k], NULL, mul_thread, (void *)rcargs);
                pthread_join(p[i][j][k], NULL);
            }
        }
    }

    display(a, rowa, cola);
    display(b, rowb, colb);
    display(c, rowa, colb);

    return 0;
}
