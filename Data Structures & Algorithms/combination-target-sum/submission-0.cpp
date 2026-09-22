class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
void backtrack(vector<int>&nums,int target,int index){
    if(index==nums.size()) return;
    if(target==0){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<nums.size();i++){
        if(nums[i]<=target){
            temp.push_back(nums[i]);
        }else if(nums[i]>target){
            continue;
        }
        backtrack(nums,target-nums[i],i);
        temp.pop_back();

    }


}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,0);
        return ans;
    }
};
