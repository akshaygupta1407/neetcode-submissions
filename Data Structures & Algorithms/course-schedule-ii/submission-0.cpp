class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>h;
        vector<int>indegrees(numCourses, 0);
        for(auto x : prerequisites) {
            h[x[1]].push_back(x[0]);
            indegrees[x[0]]++;
        }

        queue<int>q;
        vector<int>res;
        int count = 0;

        for(int i=0; i<numCourses; i++) {
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto tp = q.front();
            q.pop();
            res.push_back(tp);
            count++;
            for(auto neigh : h[tp]) {
                indegrees[neigh]--;
                if(indegrees[neigh]==0) {
                    q.push(neigh);
                }
            }
        }

        if(count == numCourses) return res;

        return {};
    }
};