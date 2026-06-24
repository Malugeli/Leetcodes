struct Solution{
    char bracketCheck(char c){
      switch (c) {
      case ')':
        return '(';
      case ']':
        return '[';
      case '}':
        return '{';
      default: return '\0';
      }
    };

    bool isValid(std::string s){
        std::array open{'{', '[', '('};
        std::stack<char> result;

        for(auto c : s){
            if(std::ranges::contains(open, c)){
                result.emplace(c);
            }
            else if(!result.empty() && result.top() == bracketCheck(c)){
                    result.pop();
                }
            else return false;
            }
            if(result.empty()) return true;
            return false;
        }
    };