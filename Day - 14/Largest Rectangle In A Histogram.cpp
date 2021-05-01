//Sid's solution 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int nser[1000000], nsel[100000];
        stack<int> r, l;
        //calculating next smaller element on the right
        for(int i = 0; i < heights.size(); i++)
        {
            if(r.empty())
            {
                r.push(i);
            }
            else
            {
                if(heights[r.top()] > heights[i])
                {
                    while(!r.empty() && heights[r.top()] > heights[i])
                    {
                        nser[r.top()] = i;
                        r.pop();
                    }
                    r.push(i);
                }
                else
                {
                    r.push(i);
                }
            }
        }
        while(!r.empty())
        {
            nser[r.top()] = heights.size();
            r.pop();
        }
        //calculating next smaller element on the left 
        for(int i = heights.size()-1; i >= 0; i--)
        {
            if(l.empty())
            {
                l.push(i);
            }
            else
            {
                if(heights[l.top()] > heights[i])
                {
                    while(!l.empty() && heights[l.top()] > heights[i])
                    {
                        nsel[l.top()] = i;
                        l.pop();
                    }
                    l.push(i);
                }
                else
                {
                    l.push(i);
                }
                
            }
        }
        while(!l.empty())
        {
            nsel[l.top()] = -1;
            l.pop();
        }
        //calculating the maximum area 
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++)
        {
            int area = heights[i]*(nser[i]-nsel[i]-1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

// Hari's 
// much shorter. Crucial sum. Different method than sid's.

int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
            
        const int sizeht = heights.size();
        stack<int> stk;
        int i = 0, maxArea = 0;
            
        while (i < sizeht) {
            // if either stk empty or curr ht > stack's top, then push it
            if (stk.empty() || heights[i] >= heights[stk.top()]) stk.push(i++);
            else {
                // if curr ht < stk top, pop top, find width and calc area
                // note there is no pushing in this case
                // dry run it. First maxArea = 6 on popping 6*1. And then 2 is not inserted. Instead go to ht = 3. 3<5(stack top). 5(idx of 3)-2(idx of 5)-1 = 2. 2*5 = 10 -> maxArea
                int h = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[h] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
