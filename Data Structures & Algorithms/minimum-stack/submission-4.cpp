class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        if(minstack.empty()){
            minstack.push(val);
        }
        else if(val <= minstack.top()){
            minstack.push(val);
        }
        mainstack.push(val);

    }
    
    void pop() {
       if(mainstack.top() == minstack.top()){
        minstack.pop();
       }
       mainstack.pop();
    }
    
    int top() {
       return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }

private:
std::stack<int> mainstack;
std::stack<int> minstack;
};