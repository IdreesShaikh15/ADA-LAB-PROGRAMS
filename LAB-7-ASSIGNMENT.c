#include <stdio.h>
#define N 3

int costMatrix[N][N] = {
    {6, 4, 8},
    {5, 1, 2},
    {5, 7, 9}
};

void solveAssignment() {
    int assigned[N] = {0}, totalCost = 0;

    for (int i = 0; i < N; i++) {
        int min = costMatrix[i][0], col = 0;
        for (int j = 1; j < N; j++) {
            if (costMatrix[i][j] < min) {
                min = costMatrix[i][j];
                col = j;
            }
        }
        assigned[col] = 1;
        totalCost += min;
        printf("Assign row %d to column %d with cost %d\n", i, col, min);
    }
    printf("Total minimum cost: %d\n", totalCost);
}

int main() {
    solveAssignment();
    return 0;
}
