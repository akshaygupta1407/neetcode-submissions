class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        for (string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }

            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    break; 
                }
            }
        }

        unordered_map<char, unordered_set<char>> graph;
        for (auto& [u, neighbors] : adj) {
            for (char v : neighbors) {
                graph[u].insert(v);
            }
        }

        for (auto& [u, neighbors] : graph) {
            for (char v : neighbors) {
                indegree[v]++;
            }
        }

        queue<char> q;
        for (auto& [c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }

        string result;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char nei : graph[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (result.size() != indegree.size()) {
            return "";
        }

        return result;
    }
};
