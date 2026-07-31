#include <ranges>

class Solution{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
        std::stack<std::pair<int,int>> check;
        std::vector<int> result(temperatures.size(), 0);
        int highest_temp{};
        int highest_day{};
        for(auto [day, temperature] : std::views::enumerate( temperatures )){

            highest_temp = temperature;
            highest_day = day;

            if(!check.empty())
{ 
            while(!check.empty() && check.top().second < highest_temp){
                result[check.top().first] = highest_day - check.top().first;
                check.pop();
            }
 }
            check.push({day, temperature});
        }
       return result;
    };
};
