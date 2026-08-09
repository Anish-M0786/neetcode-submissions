class Solution {
public:
 unordered_map<int,int>memory;
int mylogic(int amount , vector<int>&coins){
      if(amount==0) return 0;
      if(memory.find(amount)!=memory.end()){
        return memory[amount];
      }
      int res = INT_MAX;
      for(int coin:coins){
        if(amount-coin>=0){
            int result = mylogic(amount-coin,coins);
            if(result!=INT_MAX){
            res = min(res,1+result);
            }
        }
      }
      memory[amount] = res;
      return res;
       
}
    int coinChange(vector<int>& coins, int amount) {
      int myanswer = mylogic(amount,coins);

      return myanswer == INT_MAX ? -1 : myanswer;
       
    }
};
