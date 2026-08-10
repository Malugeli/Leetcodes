// die Wurzel muss nie gezogen werden..

class Solution{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k){
        auto vergleich = [](std::vector<int>& a, std::vector<int>& b){
            return euclidean(a) < euclidean(b);     
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(vergleich)> maxheap; 

        for(auto& point : points){
            maxheap.push(point);
            if(static_cast<int>( maxheap.size() ) > k){
                maxheap.pop();
            }
        }

        std::vector<std::vector<int>> result;
        while(!maxheap.empty()){result.push_back(maxheap.top()); maxheap.pop();}
        return result;
    }

private:
    static double euclidean(std::vector<int>& p){
        return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
    }

};