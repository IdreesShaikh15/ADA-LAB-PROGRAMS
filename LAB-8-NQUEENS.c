#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 20

int x[MAX_N + 1]; 
int count = 1;

void queens(int k, int n);
int place(int k, int j);

int main() {
    int n;
    printf("Enter the number of queens to be placed: ", MAX_N);
    scanf("%d", &n);

    if (n < 1 || n > MAX_N) {
        printf("Invalid number of queens. Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }

    queens(1, n);

    if (count == 1) {
        printf("No solutions found.\n");
    } else {
        printf("Total solutions found: %d\n", count - 1);
    }

    return 0;
}

void queens(int k, int n) {
    int j, i;

    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;

            if (k == n) {
                
                printf("\nSolution %d:\n", count);
                for (i = 1; i <= n; i++)
                    printf("Row %d ---> Column %d\n", i, x[i]);
                printf("\n");
                count++;
            } else {
                queens(k + 1, n); 
            }

        
            x[k] = 0;
        }
    }
}

int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}
