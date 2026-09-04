class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<Car> cars{};
        cars.reserve(position.size());

        for(size_t i = 0; i < position.size(); ++i){
            cars.push_back({ position[i], speed[i] });
        }
        std::ranges::sort(cars, std::greater{}, &Car::position);
        int fleets{};
        double fleet_time{};

        for(auto car : cars){
            double time = static_cast<double>(target - car.position) / car.speed; 
            if(time > fleet_time){
                fleets++;
                fleet_time = time; 
            }
        }
        return fleets;
    }

private: 
struct Car{
    int position;
    int speed;
};
};