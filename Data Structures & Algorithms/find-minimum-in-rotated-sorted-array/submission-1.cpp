class Solution {
public:
    int findMin(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0 , right = n-1;
        int mini = INT_MAX;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]<mini){
                mini = nums[mid];
                right = mid-1;
            }else{
                left = mid+1;
            }
            
        }
        return mini;
    }
};
