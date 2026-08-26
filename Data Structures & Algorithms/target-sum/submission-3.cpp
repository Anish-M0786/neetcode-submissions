class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int>dp;
        dp[0] = 1;
        for(int num : nums){
            unordered_map<int,int>newb;
            int sum =0;

            for(auto &[sum,ways]:dp){
                newb[sum+num] +=ways;
                newb[sum-num] +=ways;
            }
            dp = newb;
        }
        return dp[target];
    }
};
