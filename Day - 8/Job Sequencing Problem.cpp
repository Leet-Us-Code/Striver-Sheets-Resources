//Hari's

static bool compareProfit(Job a, Job b){
        return (a.profit > b.profit);
    }
    
    vector<long> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<long> ans;
        sort(arr, arr+n, compareProfit);
        long count = 0, totProfit = 0;
        long maxi = arr[0].dead;
        for(int i = 1; i<n; i++) maxi = max(maxi, arr[i].dead);

        vector<long> slots(-1, maxi+1);
        for(int i = 0; i<n; i++){
            for(int j = arr[i].dead; j>0; j--){
                if(slots[j] == -1){
                    slots[j] = i;
                    count++;
                    totProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        ans.push_back(count);
        ans.push_back(totProfit);
        return ans;
    } 
