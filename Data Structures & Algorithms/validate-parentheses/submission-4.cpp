struct Solution {
    bool isValid(std::string s) {
        if(s.size() % 2 != 0) return false;

        std::array open{'[', '(', '{'};
        std::stack<char> result;

        for(int i = 0; i < s.size(); ++i){
            if(std::ranges::contains(open, s[i])){
                result.emplace(s[i]); 
            }
            else{
              if(result.empty()) return false;
              if (s[i] == ')' && (result.top() != '(')) {
                return false;
              }
              else if(s[i] == ']' && (result.top() != '[')) {
                return false;
              } 
              else if(s[i] == '}' && (result.top() != '{')) {
                return false;
              } 
              else result.pop();
            }
        }
        if(result.empty()) return true;
        return false;
    } 

};