// Bei der ersten Solution habe ich den String kopiert statt als Reference.. Asche über mein Haupt, außerdem token.size() == 1 was es deutlicher macht was gemeint ist.
// ich könnte top(); pop(); in einer linie machen aber das ist nur stilistisch idk

class Solution{
public:
    int evalRPN(std::vector<std::string>& tokens){
        std::stack<int> symbol;
        for(const auto& token : tokens){
            if(token.size() == 1 && !isdigit(token[0])){
                auto y = symbol.top();
                symbol.pop();
                auto x = symbol.top();
                symbol.pop();

                switch (token[0]) {
                case '/':
                  symbol.push(x / y);
                  break;
                case '*':
                  symbol.push(x * y);
                  break;
                case '+':
                  symbol.push(x + y);
                  break;
                case '-':
                  symbol.push(x - y);
                  break;
                }
            }
            else{
                symbol.push(std::stoi(token));
            }
        }
        return symbol.top();
    }
};
