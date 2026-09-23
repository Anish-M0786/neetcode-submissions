class Solution {
public:
vector<vector<int>>ans;
vector<int>logic;
void backtrack(vector<int>&nums,int index){
    ans.push_back(logic);
    if(index==nums.size()) return;
    for(int i=index;i<nums.size();i++){
        logic.push_back(nums[i]);
        backtrack(nums,i+1);
        logic.pop_back();
    }

}
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return ans;
    }
};
