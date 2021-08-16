// Hari

bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> stk;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '[') stk.push(it);
            else if(it == ')' && !stk.empty() && stk.top() == '(') stk.pop();
            else if(it == '}' && !stk.empty() && stk.top() == '{') stk.pop();
            else if(it == ']' && !stk.empty() && stk.top() == '[') stk.pop();
            else return false;
        }
        
        return stk.empty();
    }
