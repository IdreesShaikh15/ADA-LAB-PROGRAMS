#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    int weights[20], values[20];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int maxValue = 0;
    int bestSubset = 0;
    int totalSubsets = 1 << n;  

    for (int subset = 0; subset < totalSubsets; subset++) {
        int weightSum = 0, valueSum = 0;

        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                weightSum += weights[i];
                valueSum += values[i];
            }
        }

        if (weightSum <= W && valueSum > maxValue) {
            maxValue = valueSum;
            bestSubset = subset;
        }
    }

    printf("Maximum value: %d\n", maxValue);
    printf("Items included (0-based index): ");
    for (int i = 0; i < n; i++) {
        if (bestSubset & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
