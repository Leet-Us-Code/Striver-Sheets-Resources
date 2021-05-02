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

//Sid's solution 
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
   return -1;
   else
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())
   return -1;
   else
   {
       
       if(s.top() >= minEle)
       {
           int x = s.top();
           s.pop();
           return x;
       }
       else
       {
           int x = minEle;
           minEle = 2*x - s.top();
           s.pop();
           return x;
       }
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty())
   {
       minEle = x;
       s.push(x);
   }
   else if(x >= minEle)
   {
       s.push(x);
   }
   else
   {
       s.push(2*x-minEle);
       minEle = x;
   }
}
