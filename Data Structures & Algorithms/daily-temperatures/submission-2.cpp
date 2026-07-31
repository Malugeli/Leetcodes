#include <ranges>

class Solution{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
        std::stack<std::pair<int,int>> check;
        std::vector<int> result(temperatures.size(), 0);

        for(auto [day, temperature] : std::views::enumerate( temperatures )){
            if(!check.empty())
{ 
            while(!check.empty() && check.top().second < temperature){
                result[check.top().first] = day - check.top().first;
                check.pop();
            }
 }
            check.push({day, temperature});
        }
       return result;
    };
};
