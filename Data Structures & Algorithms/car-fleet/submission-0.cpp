class Solution{
    public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>&  speed){
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());
        for(size_t i = 0; i < position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){return a.first > b.first;});
        int fleets{};
        int fleet_distance = -1;
        int fleet_speed = 1;

        for(const auto& [pos, spd] : cars){
            int distance = target - pos;

            if(distance * fleet_speed > fleet_distance * spd){
                ++fleets;
                fleet_distance = distance;
                fleet_speed = spd;
            }
        }
    return fleets;
    }
};