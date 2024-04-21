/*
 * Yihan Lu
 * https://leetcode.com/problems/perfect-squares/description/
 */
#include <limits.h>
#include <math.h>

int findMin(int a, int b) {
	return a < b ? a : b;
}

int numSquares(int n) {
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = INT_MAX;
		for(int x = sqrt(i); x > 0; x--) {
			dp[i] = findMin(dp[i], dp[i - x * x] + 1);
		}
	}
	return dp[n];
}
