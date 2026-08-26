class TimeMap {
private:
    std::unordered_map<
        std::string,
        std::vector<std::pair<int, std::string>>
    > data;

public:
    TimeMap() = default;

    void set(std::string key, std::string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp) {
        auto it = data.find(key);

        if (it == data.end()) {
            return "";
        }

        const auto& values = it->second;

        int left = 0;
        int right = static_cast<int>(values.size()) - 1;

        std::string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};