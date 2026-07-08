class Solution{
public:
    int evalRPN(std::vector<std::string>& tokens){
        std::stack<int> symbol;
        for(auto token : tokens){
            if(token.size() < 2 && !isdigit(token[0])){
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
