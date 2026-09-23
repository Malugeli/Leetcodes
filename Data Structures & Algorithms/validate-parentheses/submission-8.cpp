class Solution {
public:
    bool isValid(std::string s) {

       std::stack<char> parenthesis;
       for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            parenthesis.push(c);
        }
        else if(!parenthesis.empty() && c == ')'){
            if(parenthesis.top() == '('){
                parenthesis.pop();
            }
            else{
                return false;
            }
        }
        else if(!parenthesis.empty() && c == ']'){
            if(parenthesis.top() == '['){
                parenthesis.pop();
            }
            else{
                return false;
            }
        }
        else if(!parenthesis.empty() && c == '}'){
            if(parenthesis.top() == '{'){
                parenthesis.pop();
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
       }
       if(parenthesis.empty()){
        return true;
       }
       else{
        return false;
       }
    }
};