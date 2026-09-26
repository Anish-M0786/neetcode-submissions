class Solution {
public:
int calsum;
bool caneat(vector<int>&piles ,int mid,int h){
    long long calsum = 0;
    for(int i=0;i<piles.size();i++){
       calsum += (piles[i]+mid-1)/mid;
       if(calsum>h){
        return false;
       }
    }
    return true;
};
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left =1 , right = *max_element(piles.begin(),piles.end());
        while(left<right){
            int mid = left + (right-left)/2;
            if(caneat(piles,mid,h)){
                right = mid;
            }else{
               left = mid +1;
            }
        }
         return left;
    }
    
};
