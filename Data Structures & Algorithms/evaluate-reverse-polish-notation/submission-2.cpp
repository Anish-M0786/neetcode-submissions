class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s : tokens){
            if(s=="/"){
                int sectop = st.top();st.pop();
                int top = st.top();st.pop();
                st.push(top/sectop);
            }else if(s=="*"){
                int sectop = st.top(); st.pop();
                int top = st.top();st.pop();
                st.push(top*sectop);
            }else if(s=="+"){
                int sectop = st.top(); st.pop();
                int top = st.top(); st.pop();
                st.push(top+sectop);
            }else if(s=="-"){
                int sectop = st.top();st.pop();
                int top = st.top();st.pop();
                st.push(top-sectop);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();

    }
};
