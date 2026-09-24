class Solution {
public:
vector<vector<int>>ans;
vector<int>logic;
void backtrack(vector<int>&nums,int index,vector<bool>&used){
    ans.push_back(logic);
    if(index==nums.size()) return;
    for(int i=index;i<nums.size();i++){
        if(used[i]) continue;
        if(i>index && nums[i]==nums[i-1]) continue;
        used[i]=true;
        logic.push_back(nums[i]);
        backtrack(nums,i+1,used);
        logic.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      vector<bool>used(nums.size(),false);
      backtrack(nums,0,used);
      return ans;
    }
};
