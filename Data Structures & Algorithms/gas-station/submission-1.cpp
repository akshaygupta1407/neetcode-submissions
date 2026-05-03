class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = 0;
        int n = gas.size();
        int curr = 0, ind = -1, total = 0;
        for(int i=0; i<n; i++) {
            total += gas[i] - cost[i];
            if(curr + gas[i] - cost[i] < 0) {
                ind = -1;
                curr = 0;
            } else {
                if(ind == -1) ind = i;
                curr += gas[i] - cost[i];
            }

        }
        return total < 0 ? -1 : ind;
    }
};