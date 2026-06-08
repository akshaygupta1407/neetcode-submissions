class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0, e = n-1;
        int mx = 0;
        while(s < e) {
            int water = min(height[s], height[e]) * (e - s);
            mx = max(mx, water);
            if(height[s] < height[e]) {
                s++;
            } else {
                e --;
            }
        }

        return mx;
    }
};