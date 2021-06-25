// Hari

int maxSumIS(int arr[], int n)  
	{  
	    // Very similar to LIS. Instead of max length, we find max sum
	    int res = 0;
	    int MSIS[n];
	    
	    // assign arr values to MSIS. In LIS we add 1 to incorporate chosen ele being added to
	    // subsequence. Here, we will add the element value itself to get final max sum
	    
	    for(int i = 0; i<n; i++) MSIS[i] = arr[i];
	    
	    //Find max sum val in bottom up approach 
	    for(int i = 1; i<n; i++){
	        for(int j = 0; j<i; j++){
	            if(arr[i] > arr[j] && MSIS[i] < MSIS[j] + arr[i]) {
	                // then arr[i] can be included in subseq
	                MSIS[i] = MSIS[j] + arr[i];
	            }
	        }
	    }
	    
	    // final traverse to check max sum 
	    for(int i = 0; i<n; i++){
	        res = max(res, MSIS[i]);
	    }
	    
	    return res;
	}  
