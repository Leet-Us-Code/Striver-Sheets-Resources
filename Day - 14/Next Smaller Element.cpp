#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    vector<int> x;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    int nse[1000];
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
        {
            s.push(i);
        }
        else 
        {
            if(x[s.top()] > x[i])
            {
                while(!s.empty() && x[s.top()] > x[i])
                {
                    nse[s.top()] = x[i];
                    s.pop();
                }
                s.push(i);
            }
            else 
            {
                s.push(i);
            }
        }
    }
    while(!s.empty())
    {
        nse[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < n; i++)
    cout << nse[i] << " ";
}
