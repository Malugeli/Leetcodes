#include <forward_list>
#include <ranges>

template <typename Key, typename Value>
class HashTable{
    struct Node{
        Key key;
        Value value;
    };
   
    private:
    std::vector<std::forward_list<Node>> buckets;

    size_t getIndex(const Key& key){
        return std::hash<Key>{}(key) % buckets.size();
    };

    public:
    HashTable(size_t capacity = 16) : buckets(capacity == 0 ? 16 : capacity){};

    void insert(const Key& key, const Value& value){
        auto& bucket = buckets[getIndex(key)];

        auto it = std::ranges::find_if(bucket, [&key](const Node& node){
            return node.key == key;
        });

        if(it != bucket.end()){
            it->value = value;
        }
        else{
            bucket.emplace_front(key, value);
        }
    
    }
    std::optional<Value> find(const Key& key){
        auto& bucket = buckets[getIndex(key)];

        auto it = std::ranges::find_if(bucket, [&key](const Node& node){
            return node.key == key;
        });

        if(it != bucket.end()){
            return it->value;
        }
        return std::nullopt;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        HashTable<int, int> hash;
        for(auto [index, num] : std::views::enumerate(nums)){
            int searched_num = target - num;
            if(auto found = hash.find(searched_num); found.has_value()){
                return {found.value(), static_cast<int>(index)};
            }
            else{
                hash.insert(num, index);
            }
        }
        return {};
    }
};
