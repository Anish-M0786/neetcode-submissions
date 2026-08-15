class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(string w : wordDict){
                if(i>=w.size() && dp[i-w.size()] && s.substr(i-w.size(),w.size())==w){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};
