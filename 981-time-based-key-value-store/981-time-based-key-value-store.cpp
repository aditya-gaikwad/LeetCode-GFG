class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
     string searchVal(vector<pair<string, int>> &vec, const int &timestamp) {
        int low = 0;
        int high = vec.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (vec[mid].second > timestamp) {
                high = mid - 1;
            } else if (vec[mid].second < timestamp) {
                low = mid + 1;
            } else {
                return vec[mid].first;
            }
        }
        
        return high >= 0 ? vec[high].first : "";
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        return searchVal(map[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */