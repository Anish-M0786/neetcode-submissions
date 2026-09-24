class Solution {
public:
vector<vector<int>>ans;
vector<int>logic;
void backtrack(vector<int>&nums,int index,vector<bool>&used){
    if(logic.size()==nums.size()){
    ans.push_back(logic);
    return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue;
        used[i] = true;
        logic.push_back(nums[i]);
        backtrack(nums,i+1,used);
        logic.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        backtrack(nums,0,used);
        return ans;
    }
};
