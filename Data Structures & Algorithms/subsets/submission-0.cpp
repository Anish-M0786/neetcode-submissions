class Solution {
public:
vector<vector<int>>ans;
vector<int>cal;
void backtrack(vector<int>&nums,int index){
    ans.push_back(cal);
    if(index==nums.size()) return;
    for(int i=index;i<nums.size();i++){
        cal.push_back(nums[i]);
        backtrack(nums,i+1);
        cal.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
       if(nums.size()==0) return ans;
        backtrack(nums,0);
        return ans;
    }
};
