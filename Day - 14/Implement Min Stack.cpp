// Hari

/** initialize your data structure here. */
    stack<pair<int, int>> stk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = INT_MAX;
        if(stk.empty()){
            minVal = val;
        } else {
            minVal = min(stk.top().second, val);
        }
        
        stk.push({val, minVal});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
