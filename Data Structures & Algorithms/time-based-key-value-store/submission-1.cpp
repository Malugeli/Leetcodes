class TimeMap {
public:
    TimeMap() {
    }
    
    void set(std::string key, std::string value, int timestamp) {
        bucket[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
       auto it = bucket.find(key);
       if(it == bucket.end()){
        return "";
       }

       const std::vector<std::pair<int, std::string>>& vec = it->second;
       std::string result = "";

       int left = 0;
       int right = static_cast<int>( vec.size() ) - 1;

       while(left <= right){
        int mid = left + (right - left) /2;
        if(vec[mid].first <= timestamp){
            result = vec[mid].second;
            left = mid +1;
        }
        else{
            right = mid -1;
        }
       }

       return result;
    }

private:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      bucket;
};