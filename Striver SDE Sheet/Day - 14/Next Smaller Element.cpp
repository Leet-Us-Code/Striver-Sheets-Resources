// Sid

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

// Hari

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> a;
	
	cin >> n;
	
	for(int i = 0; i<n; i++){
	    int temp;
	    cin >> temp;
	    a.push_back(temp);
	}
	
	int NSE[1000];
	stack<int> s;
	
	for(int i = 0; i<n; i++){
	    if(s.empty()){
	        s.push(i); // pushing the index of element
	    }
	    else if(a[s.top()] > a[i]){
	        while(!s.empty() && a[s.top()] > a[i]){
	            NSE[s.top()] = a[i];
	            s.pop();
	        }
	        s.push(i);
	    }
	    else s.push(i);
	}
	
	while(!s.empty()){
	    // check if remaining elements exist and for them in NSE assign -1
	    NSE[s.top()] = -1;
	    s.pop();
	}
	
	for(int i = 0; i<n; i++){
	    cout << NSE[i] << " ";
	}
}
