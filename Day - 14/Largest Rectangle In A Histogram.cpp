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
