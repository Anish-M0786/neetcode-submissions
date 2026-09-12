class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int task:tasks){
            freq[task-'A']++;
        }
        int maxfreq =0 ;
        for(int f:freq){
            maxfreq = max(maxfreq,f);
        }
        int countmax =0;
        for(int f:freq){
            if(maxfreq==f){
                countmax++;
            }
        }
        int result = (maxfreq-1) * (n+1) +countmax;

        return max((int)tasks.size(),result);
    }
};
