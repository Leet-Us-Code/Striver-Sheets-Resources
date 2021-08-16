class Solution {
public:
    int trap(vector<int>& height) {
        int l[100000]; //to hold the maximum values in the left side
        int r[100000]; // to hold the maximum values in the right side
        int maxL = INT_MIN;
        int maxR = INT_MIN;
        int n = height.size();
        //travel from left to  right 
        for(int i = 0; i < n; i++)
        {
            if(height[i] > maxL)
                maxL = height[i];
            l[i] = maxL;
        }
        //travel from right to left 
        for(int i = n-1; i >= 0; i--)
        {
            if(height[i] > maxR)
                maxR = height[i];
            r[i] = maxR;
        }
        int area = 0; // the resulting amount of water trapped 
        for(int i = 0; i < n; i++)
        {
            area += (min(l[i],r[i])-height[i]);
        }
        return area;
    }
};
