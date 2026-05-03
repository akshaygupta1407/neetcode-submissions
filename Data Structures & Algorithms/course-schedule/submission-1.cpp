class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>h;
        vector<int>indegrees(numCourses, 0);
        for(auto x : prerequisites) {
            h[x[1]].push_back(x[0]);
            indegrees[x[0]]++;
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(indegrees[i]==0) q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for(auto neigh : h[course]) {
                indegrees[neigh]--;
                if(indegrees[neigh]==0) q.push(neigh);
            }
        }
        return count == numCourses;
    }
};