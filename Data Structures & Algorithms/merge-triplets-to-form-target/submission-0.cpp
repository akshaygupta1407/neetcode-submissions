class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int first = 0, second = 0, third = 0;
        for(int i=0; i<n; i++) {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;
            if(triplets[i][0] == target[0]) first++;
            if(triplets[i][1] == target[1]) second++;
            if(triplets[i][2] == target[2]) third++;
        }
        if(first==0 || second==0 || third==0) return false;
        return true;
    }
};