#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0-1背包问题的动态规划实现
int knapsack(int* values, int* weights, int n, int W) {
    int i, w;
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; ++i) {
        dp[i] = (int*)malloc((W + 1) * sizeof(int));
    }
    
    for (i = 0; i <= n; ++i) {
        for (w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    int result = dp[n][W];
    
    for (i = 0; i <= n; ++i) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);
    printf("Maximum value in Knapsack = %d\n", knapsack(values, weights, n, W));
    return 0;
}
