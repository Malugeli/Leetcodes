class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> heavy;
        for(auto stone : stones){
            heavy.push(stone);
        }        
        while(static_cast<int>( heavy.size() ) > 1){
            int x = heavy.top();
            heavy.pop();
            int y = heavy.top();
            heavy.pop();
            int z = x - y;
            if(z > 0){
                heavy.push(z);
            }
        }
        if(heavy.size()){
        return heavy.top();}
        return 0;
    }
};