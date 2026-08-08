class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans = 0;
        int n = heights.size();
        for(int i=0; i<=n; i++) {
            int currHeight = i == n ? 0 : heights[i];
            while(!st.empty() && currHeight <= heights[st.top()]) {
                int tp = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int h = width * heights[tp];
                ans = max(ans, h);
            }
            st.push(i);
        }
        return ans;
    }
};