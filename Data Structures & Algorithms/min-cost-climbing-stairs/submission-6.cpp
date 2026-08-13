#include <vector>
using namespace std;
class Solution {
public:

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, 0);

    // Base case for starting at floor 0 or floor 1
    dp[0] = cost[0];
    if (n >= 2)
        dp[1] = cost[1];

    // Fill the DP table
    for(int i=2; i<n; ++i) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }

    // The minimum of the last two steps will be our answer
    return min(dp[n-1], dp[n-2]);
}
};