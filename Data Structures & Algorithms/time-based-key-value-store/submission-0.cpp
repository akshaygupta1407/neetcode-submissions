class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>h;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        h[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &v = h[key];
        int l = 0, e = v.size() - 1;
        string s = "";
        while(l <= e) {
            int mid = (l + e) / 2;
            if(v[mid].first <= timestamp) {
                s = v[mid].second;
                l = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */