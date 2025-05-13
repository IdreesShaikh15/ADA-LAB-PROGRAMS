#include <stdio.h>

#define V 4
#define INF 99999

int tsp(int mask, int pos, int dist[V][V], int dp[V][1 << V]) {
    if (mask == (1 << V) - 1)
        return dist[pos][0]; 

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;
    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            if (newAns < ans)
                ans = newAns;
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    int dist[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[V][1 << V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < (1 << V); j++)
            dp[i][j] = -1;

    int result = tsp(1, 0, dist, dp);
    printf("The minimum cost is %d\n", result);

    return 0;
}
