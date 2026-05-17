class TimeMap {
    unordered_map<string, set<pair<int, string>>*> datastore;
public:
    TimeMap() {
        datastore.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if(datastore.find(key) == datastore.end())
        {
            datastore[key] = new std::set<pair<int,string>>();
        }
        datastore[key]->insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(datastore.find(key) != datastore.end() && datastore[key] != nullptr && !datastore[key]->empty())
        {
            auto it = datastore[key]->upper_bound({timestamp, "~"}); // using "~" this so that we can get lexicographically largest element
            if(it == datastore[key]->begin())
            {
                return "";
            }
            --it;
            return it->second;
        }
        return "";
    }
};
