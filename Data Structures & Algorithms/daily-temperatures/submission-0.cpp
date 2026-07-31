// O(n²) Lösung, ich wollte erstmal verstehen warum wir es anders machen sollten

class Solution{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
        int highest_temperature{};
        std::vector<int> result(temperatures.size(), 0);
       for(int day = 0; day < static_cast<int>( temperatures.size() ); ++day){
            highest_temperature = temperatures[day]; 
            int next_day = day +1;
            while(next_day < static_cast<int>( temperatures.size() )){
               if(highest_temperature < temperatures[next_day]){
                result[day] = next_day - day;
                break;
               }
               ++next_day;
            }
       }
       return result;
    };
};