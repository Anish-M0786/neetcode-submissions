class Solution {
public:
vector<string>ans;
string letters;
void backtrack(string digits,vector<string>&mp,int curr){
    if(digits.size()==0) return;
    if(curr==digits.size()){
        ans.push_back(letters);
        return;
    }
    string letter = mp[digits[curr] -'0'];
    for(char ch : letter){
        letters.push_back(ch);
        backtrack(digits,mp,curr+1);
        letters.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
       vector<string>mp={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
       };
        backtrack(digits,mp,0);
        return ans;


    }
};
