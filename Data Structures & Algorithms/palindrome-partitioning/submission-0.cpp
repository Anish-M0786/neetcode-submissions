class Solution {
public:
vector<vector<string>>ans;
vector<string>temp;
bool ispalindrome(string &s,int left,int right){
    int n = s.size();
    while(left<right){
        if(s[left]!=s[right]){
            return false;

        }
        left++;
        right--;
    }
    return true;
}
void backtrack(string &s,int curr){
    if(s.size()==0) return;
    if(curr==s.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=curr;i<s.size();i++){
       if(ispalindrome(s,curr,i)){
        temp.push_back(s.substr(curr,i-curr+1));
        backtrack(s,i+1);
        temp.pop_back();
       }
    }
}
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }
};
