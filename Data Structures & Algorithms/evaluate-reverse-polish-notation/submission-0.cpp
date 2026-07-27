class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans = 0;
        for(auto x : tokens) {
            if(x=="+" || x=="-" || x=="*" || x=="/") {
                if(x=="+") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans=b+a;
                    st.push(ans);
                }
                if(x=="-") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans=b-a;
                    st.push(ans);
                }
                if(x=="*") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans=b*a;
                    st.push(ans);
                }
                if(x=="/") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans=b/a;
                    st.push(ans);
                }
            }
            else {
                int num = stoi(x);
                st.push(num);
            }
        }
        if(!st.empty()) {
            return st.top();
        }
        return ans;
    }
};