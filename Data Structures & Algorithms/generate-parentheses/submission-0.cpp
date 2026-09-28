class Solution {
public:
vector<string>ans;
void paren(string curr,int open,int close,int n){
    if(open==n && close==n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        paren(curr+"(",open+1,close,n);
    }
    if(close<open){
        paren(curr+")",open,close+1,n);
    }

    
}
    vector<string> generateParenthesis(int n) {
        paren("",0,0,n);
        return ans;
    }
};
